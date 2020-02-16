/**
 * This file concerns everything related to the keyboard
 */

#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

/**
 * @brief Subscribes KBC Interrupts and disables Minix Default Keyboard IH
 * @param interrupt_bit Bit of Interrupt Vector that will be set when KBC Interrupt is pending
 * @param interrupt_id KBC Interrupt ID to specify the KBC Interrupt in other calls
 * @return Whether operation was sucessful or not
 */
int (subscribe_keyboard_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

uint8_t scancode[2];
int keyboard_done;
int scancode_sz;
int got_error_keyboard;

/**
 * @brief KBC Interrupt Handler
 */
void (kbc_ih)(void);

/**
 * @brief High-level function that polls keyboard for scancode
 * High-level function that polls keyboard for scancode of up to 2 bytes. If
 * scancode has only 1 byte, the second byte is set to 0x00.
 * @param bytes Array of at least 2 bytes to store scancode
 * @param size Size of scancode in bytes
 * @return 0 if operation was successful, 1 otherwise
 */
int (keyboard_poll)(uint8_t bytes[], uint8_t *size);

#endif //KEYBOARD_H_INCLUDED
