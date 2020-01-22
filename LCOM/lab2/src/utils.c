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

int (unsubscribe_interrupt)(int *interrupt_id) {
    if (interrupt_id == NULL) return NULL_PTR;
    if(sys_irqrmpolicy(interrupt_id)) return UNSBCR_ERROR;
    return SUCCESS;
}

int32_t min(int32_t a, int32_t b){ return (b < a ? b : a); }
int32_t max(int32_t a, int32_t b){ return (a < b ? b : a); }
