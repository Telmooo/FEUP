#include <lcom/lcf.h>

#include "keyboard.h"

#include "kbc.h"
#include "kbc_macros.h"
#include "utils.h"
#include "errors.h"

int (subscribe_keyboard_interrupt)(uint8_t interrupt_bit, int *interrupt_id) {
    if (interrupt_id == NULL) return NULL_PTR;
    *interrupt_id = interrupt_bit;
    if(sys_irqsetpolicy(KBC_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, interrupt_id)) return SBCR_ERROR;
    return SUCCESS;
}

int keyboard_done = 1;
int scancode_sz = 1;
int got_error_keyboard = 0;

void (kbc_ih)(void) {
    if(keyboard_done) scancode_sz = 0;
    uint8_t status = 0;
    got_error_keyboard = 0;
    if (util_sys_inb(STATUS_REG, &status)) {
        got_error_keyboard = 1;
        return;
    }
    if (status & (TIME_OUT_REC | PARITY_ERROR)) {
        got_error_keyboard = 1;
        return;
    }
    if ((status & OUT_BUF_FUL) == 0 || (status & AUX_MOUSE) != 0) {
        got_error_keyboard = 1;
        return;
    }
    uint8_t byte = 0;
    if (util_sys_inb(OUTPUT_BUF, &byte)) {
        got_error_keyboard = 1;
        return;
    }
    scancode[scancode_sz] = byte;
    scancode_sz++;
    keyboard_done = !(TWO_BYTE_CODE == byte);
}

int (keyboard_poll)(uint8_t bytes[], uint8_t *size){
    if(bytes == NULL || size == NULL) return 1;
    uint8_t c;
    if(kbc_read_byte(&c)) return 1;
    if(c == TWO_BYTE_CODE){
        if(kbc_read_byte(&bytes[1])) return 1;
        bytes[0] = c;
        *size = 2;
    }else{
        bytes[1] = 0;
        bytes[0] = c;
        *size = 1;
    }
    return 0;
}
