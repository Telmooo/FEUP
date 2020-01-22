#include <lcom/lcf.h>

#include "keyboard.h"

#include "kbc.h"
#include "kbc_macros.h"
#include "utils.h"
#include "errors.h"

int (subscribe_kbc_interrupt)(uint8_t interrupt_bit, int *interrupt_id) {
    if (interrupt_id == NULL) return NULL_PTR;
    *interrupt_id = interrupt_bit;
    if(sys_irqsetpolicy(KBC_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, interrupt_id)) return SBCR_ERROR;
    return SUCCESS;
}

int done = 1;
int sz = 1;
int got_error_keyboard = SUCCESS;

void (kbc_ih)(void) {
    if(done) sz = 1;
    else     sz++;
    uint8_t status = 0;
    got_error_keyboard = SUCCESS;
    if ((got_error_keyboard = util_sys_inb(STATUS_REG, &status))) return;
    if (status & (TIME_OUT_REC | PARITY_ERROR)) {
        got_error_keyboard = 1;
        return;
    }
    if ((status & OUT_BUF_FUL) == 0 || (status & AUX_MOUSE) != 0) {
        got_error_keyboard = READ_ERROR;
        return;
    }
    uint8_t byte = 0;
    if ((got_error_keyboard = util_sys_inb(OUTPUT_BUF, &byte))) return;

    scancode[sz-1] = byte;
    done = !(TWO_BYTE_CODE == byte);
}

int (keyboard_poll)(uint8_t bytes[], uint8_t *size){
    int ret = 0;
    if(bytes == NULL || size == NULL) return NULL_PTR;
    uint8_t c;
    if((ret = kbc_read_byte(&c))) return ret;
    if(c == TWO_BYTE_CODE){
        if((ret = kbc_read_byte(&bytes[1]))) return ret;
        bytes[0] = c;
        *size = 2;
    }else{
        bytes[1] = 0;
        bytes[0] = c;
        *size = 1;
    }
    return SUCCESS;
}
