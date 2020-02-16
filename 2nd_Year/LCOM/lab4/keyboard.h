/**
 * This file concerns everything related to the keyboard
 */

#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

int (subscribe_kbc_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

uint8_t scancode[2];
int done;
int sz;
int got_error_keyboard;

void (kbc_ih)(void);

int (keyboard_poll)(uint8_t bytes[], uint8_t *size);

#endif //KEYBOARD_H_INCLUDED
