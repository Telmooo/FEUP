#ifndef MOUSE_MACROS_H_INCLUDED
#define MOUSE_MACROS_H_INCLUDED

/* Mouse Data Packet */
// Byte 0 - Button States
#define LEFT_BUTTON     BIT(0) /* @brief Left button click event*/
#define RIGHT_BUTTON    BIT(1) /* @brief Right button click event */
#define MIDDLE_BUTTON   BIT(2) /* @brief Middle button click event */
#define FIRST_BYTE_ID   BIT(3) /* @brief Identifier of first byte of packet CAREFUL: Not 100% accurate */
#define MSB_X_DELTA     BIT(4) /* @brief Most significant bit of X delta */
#define MSB_Y_DELTA     BIT(5) /* @brief Most significant bit of Y delta */
#define X_OVERFLOW      BIT(6) /* @brief X delta overflowed */
#define Y_OVERFLOW      BIT(7) /* @brief Y delta overflowed */
// Byte 1 - X delta
// Byte 2 - Y delta

/* Mouse Commands */
#define RESET           0xFF /* @brief Reset mouse */
#define RESEND          0xFE /* @brief Resend command */
#define DEFAULT         0xF6 /* @brief Set default values */
#define DIS_DATA_REP    0xF5 /* @brief Disable Data Reporting */
#define ENABLE_DATA_REP 0xF4 /* @brief Enable Data Reporting */
#define SET_SAMPLE_RT   0xF3 /* @brief Sets state sampling rate */
#define SET_REMOTE_MD   0xF0 /* @brief Sets Mouse on Remote Mode, data on request */
#define READ_DATA       0xEB /* @brief Sends data packet request */
#define SET_STREAM_MD   0xEA /* @brief Sets mouse on Stream Mode, data on events */
#define STATUS_REQUEST  0xE9 /* @brief Get mouse configuration */
#define SET_RESOLUTION  0xE8 /* @brief Sets resolution for mouse movement */
#define SCALING_ACC_MD  0xE7 /* @brief Sets scaling on acceleration mode */
#define SCALING_LIN_MD  0xE6 /* @brief Sets scaling on linear mode */

/* Mouse Controller Responses */
#define ACK_OK      0xFA /* @brief Operation sucessful */
#define ACK_INVALID 0xFE /* @brief Invalid Byte, first occurence */
#define ACK_ERROR   0xFC /* @brief Invalid Byte on resend */

#endif // MOUSE_MACROS_H_INCLUDED
