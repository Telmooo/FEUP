#include <lcom/lcf.h>

#include "mouse.h"

#include "errors.h"
#include "kbc_macros.h"
#include "mouse_macros.h"
#include "kbc.h"

int (subscribe_mouse_interrupt)(uint8_t interrupt_bit, int *interrupt_id) {
    if (interrupt_id == NULL) return NULL_PTR;
    *interrupt_id = interrupt_bit;
    if (sys_irqsetpolicy(MOUSE_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, interrupt_id)) return SBCR_ERROR;
    return SUCCESS;
}

int got_error_mouse_ih = 0;
int counter_mouse_ih = 0;

void (mouse_ih)(void) {
    uint8_t status = 0;
    got_error_mouse_ih = 0;
    if(counter_mouse_ih >= 3) counter_mouse_ih = 0;

    if ((got_error_mouse_ih = util_sys_inb(STATUS_REG, &status))) return;

    if (status & (TIME_OUT_REC | PARITY_ERROR)) {
        got_error_mouse_ih = OTHER_ERROR;
        return;
    }
    if (((status & AUX_MOUSE) == 0) || ((status & OUT_BUF_FUL) == 0)) {
        got_error_mouse_ih = READ_ERROR;
        return;
    }

    uint8_t byte = 0;

    if ((got_error_mouse_ih = util_sys_inb(OUTPUT_BUF, &byte))) return;

    /// This does not run if: I was expecting the first one but what I get is definitely not the first byte
    if((byte & FIRST_BYTE_ID)  || counter_mouse_ih){
        packet_mouse_ih[counter_mouse_ih++] = byte;
    }
}

struct packet (mouse_parse_packet)(const uint8_t *packet_bytes){
    struct packet pp;
    pp.bytes[0] = packet_bytes[0];
    pp.bytes[1] = packet_bytes[1];
    pp.bytes[2] = packet_bytes[2];
    pp.rb       = pp.bytes[0] & RIGHT_BUTTON;
    pp.mb       = pp.bytes[0] & MIDDLE_BUTTON;
    pp.lb       = pp.bytes[0] & LEFT_BUTTON;
    pp.delta_x  = sign_extend_byte((packet_bytes[0] & MSB_X_DELTA) != 0, pp.bytes[1]);
    pp.delta_y  = sign_extend_byte((packet_bytes[0] & MSB_Y_DELTA) != 0, pp.bytes[2]);
    pp.x_ov     = pp.bytes[0] & X_OVERFLOW;
    pp.y_ov     = pp.bytes[0] & Y_OVERFLOW;
    return pp;
}

int mouse_poll(struct packet *pp, uint16_t period){
    int ret = 0;

    uint8_t packet[3];
    uint8_t byte;
    if ((ret = mouse_issue_cmd(READ_DATA))) return ret;
    for(unsigned i = 0; i < 3; ++i){
        if((ret = mouse_poll_byte(&byte, period))) return ret;
        packet[i] = byte;
    }
    *pp = mouse_parse_packet(packet);
    return SUCCESS;
}

int (mouse_set_data_report)(int on){
    if(on) return mouse_issue_cmd(ENABLE_DATA_REP);
    else   return mouse_issue_cmd(   DIS_DATA_REP);
}

int (mouse_read_data)(uint8_t *data, uint16_t period) {
    int ret;
    if ((ret = mouse_issue_cmd(READ_DATA))) return ret;
    if ((ret = mouse_poll_byte(data, period))) return ret;
    return SUCCESS;
}

int (mouse_issue_cmd)(uint32_t cmd) {
    int ret;
    uint8_t ack = 0;
    for (unsigned int i = 0; i < KBC_NUM_TRIES; i++) {
        if ((ret = kbc_issue_cmd(MOUSE_WRITE_B))) return ret;
        if ((ret = kbc_issue_arg(cmd))) return ret;
        if ((ret = mouse_read_byte(&ack))) return ret;

        if (ack == ACK_OK) return SUCCESS;
        if (ack == ACK_ERROR) return INVALID_COMMAND;
        tickdelay(micros_to_ticks(DELAY));
    }
    return TIMEOUT_ERROR;
}

int (mouse_read_byte)(uint8_t *byte) {
    int ret = 0;
    uint8_t stat;
    for(int i = 0; i < KBC_NUM_TRIES; ++i){
        if((ret = util_sys_inb(STATUS_REG, &stat))) return ret;
        if((stat&OUT_BUF_FUL) && (stat&AUX_MOUSE)) {
            if(stat & (PARITY_ERROR | TIME_OUT_REC)) return OTHER_ERROR;
            if((ret = util_sys_inb(OUTPUT_BUF, byte))) return ret;
            else return SUCCESS;
        }
        tickdelay(micros_to_ticks(DELAY));
    }
    return TIMEOUT_ERROR;
}

int (mouse_poll_byte)(uint8_t *byte, uint16_t period) {
    int ret = 0;
    uint8_t stat;
    while(true){
        if((ret = util_sys_inb(STATUS_REG, &stat))) return ret;
        if((stat&OUT_BUF_FUL) && (stat&AUX_MOUSE)) {
            if(stat & (PARITY_ERROR | TIME_OUT_REC)) return OTHER_ERROR;
            if((ret = util_sys_inb(OUTPUT_BUF, byte))) return ret;
            else return SUCCESS;
        }
        tickdelay(micros_to_ticks(DELAY));
    }
}

int16_t (sign_extend_byte)(uint8_t sign_bit, uint8_t byte) {
    return (int16_t)(((0xFF * sign_bit)<<8) | byte);
}
