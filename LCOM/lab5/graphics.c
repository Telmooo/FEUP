#include "graphics.h"
#include "graphics_macros.h"
#include "errors.h"

#include <lcom/lcf.h>

#include <stdio.h>

static void *video_mem; /** @brief Frame-buffer VM address */
static vbe_mode_info_t vbe_mem_info;
static mmap_t mem_map;

int (get_permission)(unsigned int base_addr, unsigned int size) {
    struct minix_mem_range mmr;
    mmr.mr_base = base_addr;
    mmr.mr_limit = base_addr + size;
    return sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mmr);
}

//int (get_permissions_first_mbyte)(void) {
//    return get_permission(MBYTE_BASE, MBYTE_SIZE);
//}

int (vbe_get_mode_information)(uint16_t mode) {
    memset(&vbe_mem_info, 0, sizeof(vbe_mode_info_t)); // reset values

    struct reg86 reg_86;
    memset(&reg_86, 0, sizeof(struct reg86)); // reset struct

    vbe_mode_info_t *virtual_addr = lm_alloc(sizeof(vbe_mode_info_t), &mem_map);

    reg_86.intno = VC_BIOS_SERV;
    reg_86.ah = VBE_CALL;
    reg_86.al = VBE_MD_INFO;
    reg_86.cx = mode;
    reg_86.es = PB2BASE(mem_map.phys);
    reg_86.di = PB2OFF(mem_map.phys);
    // BIOS CALL
    if (sys_int86(&reg_86) || reg_86.ah != AH_SUCCESS) {
        printf("%s: sys_int86 failed\n", __func__);
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return BIOS_CALL_ERROR;
    }

    memcpy((void*)&vbe_mem_info, (void*)virtual_addr, mem_map.size);
    return SUCCESS;
}

int (vbe_get_controller_information)(vg_vbe_contr_info_t *info_p) {
    memset(info_p, 0, sizeof(vg_vbe_contr_info_t)); // reset values

    mmap_t controller_map;

    struct reg86 reg_86;
    memset(&reg_86, 0, sizeof(struct reg86)); // reset struct

    VbeInfoBlock *virtual_addr = lm_alloc(sizeof(VbeInfoBlock), &controller_map);

    uint32_t virtual_base = (uint32_t)(virtual_addr) - controller_map.phys;

    virtual_addr->VbeSignature[0] = 'V';
    virtual_addr->VbeSignature[1] = 'B';
    virtual_addr->VbeSignature[2] = 'E';
    virtual_addr->VbeSignature[3] = '2';


    reg_86.intno = VC_BIOS_SERV;
    reg_86.ah = VBE_CALL;
    reg_86.al = VBE_CTRL_INFO;
    reg_86.es = PB2BASE(controller_map.phys);
    reg_86.di = PB2OFF(controller_map.phys);
    // BIOS CALL
    if (sys_int86(&reg_86) || reg_86.ah != AH_SUCCESS) {
        printf("%s: sys_int86 failed\n", __func__);
        if (!lm_free(&controller_map)) {
            printf("%s: lm_free failed\n", __func__);
        }
        return BIOS_CALL_ERROR;
    }

    info_p->VBESignature[0] = virtual_addr->VbeSignature[0];
    info_p->VBESignature[1] = virtual_addr->VbeSignature[1];
    info_p->VBESignature[2] = virtual_addr->VbeSignature[2];
    info_p->VBESignature[3] = virtual_addr->VbeSignature[3];

    uint8_t lsb, msb;
    util_get_LSB(virtual_addr->VbeVersion, &lsb);
    util_get_MSB(virtual_addr->VbeVersion, &msb);
    info_p->VBEVersion[0] = lsb;
    info_p->VBEVersion[1] = msb;

    info_p->TotalMemory = (virtual_addr->TotalMemory << 6);

    // Convert Far Far Pointer to Virtual Address

    uint32_t phys_ptr = FAR2PHYS(virtual_addr->OemStringPtr);
    uint32_t virtual_ptr = phys_ptr + virtual_base;
    info_p->OEMString = (char*)(virtual_ptr);

    phys_ptr = FAR2PHYS(virtual_addr->VideoModePtr);
    virtual_ptr = phys_ptr + virtual_base;
    info_p->VideoModeList = (uint16_t*)(virtual_ptr);

    phys_ptr = FAR2PHYS(virtual_addr->OemVendorNamePtr);
    virtual_ptr = phys_ptr + virtual_base;
    info_p->OEMVendorNamePtr = (char*)(virtual_ptr);

    phys_ptr = FAR2PHYS(virtual_addr->OemProductNamePtr);
    virtual_ptr = phys_ptr + virtual_base;
    info_p->OEMProductNamePtr = (char*)(virtual_ptr);

    phys_ptr = FAR2PHYS(virtual_addr->OemProductRevPtr);
    virtual_ptr = phys_ptr + virtual_base;
    info_p->OEMProductRevPtr = (char*)(virtual_ptr);

    if (!lm_free(&controller_map)) {
        printf("%s: lm_free failed\n", __func__);
        return LCF_ERROR;
    }

    return SUCCESS;
}

phys_bytes get_phys_addr(void) {
    return vbe_mem_info.PhysBasePtr;
}

unsigned int get_vram_size(void) {
    return vbe_mem_info.XResolution * vbe_mem_info.YResolution * ((vbe_mem_info.BitsPerPixel + 7) >> 3);
}

uint16_t get_XRes(void) {
    return vbe_mem_info.XResolution;
}

uint16_t get_YRes(void) {
    return vbe_mem_info.YResolution;
}

uint16_t get_bits_pixel(void) {
    return vbe_mem_info.BitsPerPixel;
}

uint16_t get_bytes_pixel(void) {
    return (vbe_mem_info.BitsPerPixel + 7) >> 3;
}

uint16_t get_RedMaskSize  (void){ return vbe_mem_info.RedMaskSize  ; }
uint16_t get_GreenMaskSize(void){ return vbe_mem_info.GreenMaskSize; }
uint16_t get_BlueMaskSize (void){ return vbe_mem_info.BlueMaskSize ; }

int (map_vram)(void) {
    int r;
    unsigned int vram_base = get_phys_addr();
    unsigned int vram_size = get_vram_size();
    if ((r = get_permission(vram_base, vram_size))) {
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        panic("%s: sys_privctl (ADD MEM) failed: %d\n", __func__, r);
    }

    video_mem = vm_map_phys(SELF, (void *)vram_base, vram_size);

    if (video_mem == MAP_FAILED) {
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        panic("%s: couldn't map video memory.", __func__);
    }

    return SUCCESS;
}

int (free_memory_map)(void) {
    return !lm_free(&mem_map);
}

int (set_graphics_mode)(uint16_t mode) {
    struct reg86 reg_86;

    memset(&reg_86, 0, sizeof(struct reg86)); // reset struct

    // Set Reg86
    reg_86.intno = VC_BIOS_SERV;
    reg_86.ah = VBE_CALL;
    reg_86.al = SET_VBE_MD;
    reg_86.bx = mode | LINEAR_FRAME_BUFFER_MD;

    // BIOS CALL
    if (sys_int86(&reg_86) || reg_86.ah != AH_SUCCESS) {
        printf("%s: sys_int86 failed\n", __func__);
        return BIOS_CALL_ERROR;
    }

    return SUCCESS;
}


int (set_pixel)(uint16_t x, uint16_t y, uint32_t color) {
    if (x >= vbe_mem_info.XResolution || y >= vbe_mem_info.YResolution) {
        printf("%s: invalid pixel.\n", __func__);
        return OUT_OF_RANGE;
    }
    unsigned int pos = (x + y * vbe_mem_info.XResolution) * get_bytes_pixel();
    memcpy((void*)((unsigned int)video_mem + pos), &color, get_bytes_pixel());
    return SUCCESS;
}

int (draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color){
    int r;
    for (uint16_t i = 0; i < len; i++)
        if ((r = set_pixel(x + i, y, color))) return r;
    return SUCCESS;
}
int (vg_draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color){
    return draw_hline(x,y,len,color);
}

int (draw_rectangle)(uint16_t x, uint16_t y,uint16_t width, uint16_t height, uint32_t color)	{
    int r;
    for (uint16_t i = 0; i < height; i++)
        if ((r = draw_hline(x, y + i, width, color))) return r;
    return SUCCESS;
}
int (vg_draw_rectangle)(uint16_t x, uint16_t y,uint16_t width, uint16_t height, uint32_t color){
    return draw_rectangle(x,y,width,height, color);
}

int paint_screen(uint32_t color){
    return draw_rectangle(0,0,get_XRes(),get_YRes(),color);
}

int clear_screen(){
    return paint_screen(BLACK);
}
