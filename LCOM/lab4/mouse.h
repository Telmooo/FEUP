#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include <stdint.h>

/**
 * @brief Subscribes Mouse Interrupts and disables Minix Default IH
 * @param interrupt_bit Bit of Interrupt Vector that will be set when Mouse Interrupt is pending
 * @param interrupt_id Mouse Interrupt ID to specify the Mouse Interrupt in other calls
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (subscribe_mouse_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

//These have to do with mouse_ih
int got_error_mouse_ih;
uint8_t packet_mouse_ih[3];
int counter_mouse_ih;

/**
 * @brief   Parse 3 bytes and returns it as a parsed, struct packet.
 * @param   packet_bytes    array of bytes to parse
 * @return  parsed struct packet
 */
struct packet (mouse_parse_packet)(const uint8_t *packet_bytes);

/**
 * @brief Polls mouse for data. Blocks execution until a valid mouse packet is obtained.
 * @param   pp      pointer to packet struct in which the result will be stored
 * @param   period  time (in milliseconds) the poller should wait between pollings of bytes
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int mouse_poll(struct packet *pp, uint16_t period);

/**
 * @brief Sets data report mode for mouse
 * @param   on  zero to disable data report, any other value to enable data report
 * @return  ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int (mouse_set_data_report)(int on);

/**
 * @brief Reads data byte from mouse
 * <summary>
 * Polls the mouse till data is available for reading
 * </summary>
 * @param data Pointer to variable where byte read from mouse will be stored
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (mouse_read_data)(uint8_t *data, uint16_t period);

/**
 * @brief Issues command to mouse
 * <summary>
 * Issues command to mouse, returns error after two consecutive errors reported by the acknowledgment byte
 * </summary>
 * @param cmd Command to be issued
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (mouse_issue_cmd)(uint32_t cmd);

/**
 * @brief Reads byte from mouse
 * <summary>
 * Reads byte from mouse, giving error if exceeds number of tries to read
 * </summary>
 * @param byte Pointer to variable where byte read from mouse will be stored
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (mouse_read_byte)(uint8_t *byte);

/**
 * @brief Polls OUT_BUF for byte coming from mouse.
 * @param   byte    pointer to byte read from OUT_BUF
 * @param   period  time (in milliseconds) the poller should wait between pollings of bytes
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int (mouse_poll_byte)(uint8_t *byte, uint16_t period);

/**
 * @brief Converts 9-bit number to 16-bit with sign extension
 * @param sign_bit  Sign bit identifiying the signal of the number
 * @param byte      Least significant byte that will be extended
 * @return Extended 9-bit number
 */
int16_t (sign_extend_byte)(uint8_t sign_bit, uint8_t byte);

#endif //MOUSE_H_INCLUDED
