#ifndef _KBC_FUNC_H_
#define _KBC_FUNC_H_

#include <stdint.h>

#define GET         0 /* @brief Argument to get counter without incrementing */
#define INCREMENT   1 /* @brief Argument for incrementing counter */

/**
 * @brief Subscribes KBC Interrupts and disables Minix Default Keyboard IH
 * @param interrupt_bit Bit of Interrupt Vector that will be set when KBC Interrupt is pending
 * @param interrupt_id KBC Interrupt ID to specify the KBC Interrupt in other calls
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (subscribe_kbc_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

/**
 * @brief Subscribes Mouse Interrupts and disables Minix Default IH
 * @param interrupt_bit Bit of Interrupt Vector that will be set when Mouse Interrupt is pending
 * @param interrupt_id Mouse Interrupt ID to specify the Mouse Interrupt in other calls
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (subscribe_mouse_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

/**
 * @brief Unsubcribes Interrupts
 * @param interrupt_id Interrupt ID, value via arguments on subscription of the interrupt_id
 * @see subscribe_kbc_interrupt, subscribe_timer_interrupt
 * @return Whether operation was sucessful or not
 */
int (unsubscribe_interrupt)(int *interrupt_id);

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
int (kbd_poll)(uint8_t bytes[], uint8_t *size);

/**
 * @brief High-level function that reads the command byte of the KBC
 * @param cmd Pointer to variable where command byte read from KBC will be stored
 * @return 0 if operation was successful, 1 otherwise
 */
int (kbc_read_cmd)(uint8_t *cmd);

/**
 * @brief High-level function that changes the command byte of the KBC
 * @param cmd New value for command byte of KBC
 * @return 0 if operation was successful, 1 otherwise
 */
int (kbc_change_cmd)(uint8_t cmd);

/**
 * @brief High-level function that restores KBC to normal state
 * High-level function that restores KBC to normal state, because lcf_start
 * changes the command byte of KBC. If this function is not used, there is a
 * chance that the keyboard and keyboard interrupts remain disabled.
 * @return 1 if operation was successful, 1 otherwise
 */
int (kbc_restore_kbd)();

/**
 * @brief Low-level function to issue a command to keyboard
 * @param cmd command to be issued
 * @return 0 if operation was successful, 1 otherwise
 */
int (kbc_issue_cmd)(uint8_t cmd);

/**
 * @brief Low-level function to issue an argument of a command
 * @param cmd argument to be issued
 * @return 0 if operation was successful, 1 otherwise
 */
int (kbc_issue_arg)(uint8_t arg);

/**
 * @brief Low-level function for reading byte from keyboard
 * Low-level function for reading byte from keyboard. Waits until output buffer
 * is full
 * @param value Pointer to variable where byte read from keyboard will be stored
 * @return 0 if operation was successful, 1 otherwise
 */
int (kbc_read_byte)(uint8_t *byte);


#endif
