#include <lcom/lcf.h>

#include "utils.h"

#include <stdint.h>
#include "errors.h"

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
    if (lsb == NULL) return NULL_PTR;
    *lsb = val;
    return SUCCESS;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
    if (msb == NULL) return NULL_PTR;
    *msb = (val >> 8);
    return SUCCESS;
}

#ifdef LAB3
    uint32_t sys_inb_counter = 0;
#endif

int (util_sys_inb)(int port, uint8_t *value) {
    if(value == NULL) return NULL_PTR;
    uint32_t n = 0;
    if(sys_inb(port, &n)) return READ_ERROR;
    *value = n;
    #ifdef LAB3
        ++sys_inb_counter;
    #endif
    return SUCCESS;
}

int16_t abs16(int16_t x) {
    return (x >= 0) ? (int16_t)(x) : (int16_t)(-x);
}
