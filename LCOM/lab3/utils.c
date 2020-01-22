#include <lcom/lcf.h>

#include <stdint.h>

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
    if (lsb == NULL) return 1;
    *lsb = val;
    return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
    if (msb == NULL) return 1;
    *msb = (val >> 8);
    return 0;
}

#ifdef LAB3
    uint32_t sys_inb_counter = 0;
#endif

int (util_sys_inb)(int port, uint8_t *value) {
    if(value == NULL) return 1;
    uint32_t n = 0;
    if(sys_inb(port, &n)) return 1;
    *value = n;
    #ifdef LAB3
        ++sys_inb_counter;
    #endif
    return 0;
}
