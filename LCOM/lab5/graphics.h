#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <lcom/lcf.h>
#include <stdint.h>

#define GET_RED(n)          (0xFF & ((n) >> 16))
#define GET_GRE(n)          (0xFF & ((n) >>  8))
#define GET_BLU(n)          (0xFF & (n      ))
#define SET_RED(n)          (((n)&0xFF) << 16)
#define SET_GRE(n)          (((n)&0xFF) <<  8)
#define SET_BLU(n)          (((n)&0xFF)      )
#define SET_COLOR(r,g,b)    (SET_RED(r) | SET_GRE(g) | SET_BLU(b))
#define FAR2PHYS(n)         ((((n)>>12) & 0xFFFFFFF0) + ((n) & 0x0000FFFF))

typedef struct __attribute__((packed)) {

    char        VbeSignature[4]     ;
    uint16_t    VbeVersion          ;
    uint32_t    OemStringPtr        ;
    uint8_t     Capabilities[4]     ;
    uint32_t    VideoModePtr        ;
    uint16_t    TotalMemory         ;

    uint16_t    OemSoftwareRev      ;
    uint32_t    OemVendorNamePtr    ;
    uint32_t    OemProductNamePtr   ;
    uint32_t    OemProductRevPtr    ;
    char        Reserved[222]       ;

    char        OemData[256]        ;
} VbeInfoBlock;

int (get_permission)(unsigned int base_addr, unsigned int size);

//int (get_permissions_first_mbyte)(void);

int (vbe_get_mode_information)(uint16_t mode);

int (vbe_get_controller_information)(vg_vbe_contr_info_t *info_p);

phys_bytes get_phys_addr(void);

unsigned int get_vram_size(void);

uint16_t get_XRes(void);

uint16_t get_YRes(void);

uint16_t get_bits_pixel(void);

uint16_t get_bytes_pixel(void);

uint16_t get_RedMaskSize(void);

uint16_t get_GreenMaskSize(void);

uint16_t get_BlueMaskSize(void);

int (map_vram)(void);

int (free_memory_map)(void);

int (set_pixel)(uint16_t row, uint16_t col, uint32_t color);

/**
 * @brief
 * @param mode
 * @return
 */
int (set_graphics_mode)(uint16_t mode);

int (draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);

int (draw_rectangle)(uint16_t x, uint16_t y,uint16_t width, uint16_t height, uint32_t color);

int (paint_screen)(uint32_t color);

int (clear_screen)();

#endif /* end of include guard: GRAPHICS_H_INCLUDED */
