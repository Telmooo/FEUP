#ifndef KBC_MACROS_H_INCLUDED
#define KBC_MACROS_H_INCLUDED

/* KBC IRQ Line */

#define KBC_IRQ     1   /* @brief KBC Controller IRQ Line */
#define MOUSE_IRQ   12  /* @brief Mouse IRQ Line */

/* Delay for KBC */
#define DELAY           20000 /* @brief KBC Response Delay */
#define KBC_NUM_TRIES   10    /* @brief Number of tries to issue command before timeout */

/* I/O Ports Addresses */

#define KBC_CMD     0x64 /* @brief Address to send commands to KBC */
#define KBC_CMD_ARG 0x60 /* @brief Address to write KBC Command Arguments */
#define STATUS_REG  0x64 /* @brief KBC Status Register address */

#define OUTPUT_BUF  0x60 /* @brief Address of Output Buffer of KBC */

/* KBC Commands */
#define READ_KBC_CMD    0x20 /* @brief Read KBC Command Byte */
#define WRITE_KBC_CMD   0x60 /* @brief Write KBC Command Byte */
#define KBC_SELF_TEST   0xAA /* @brief KBC Diagnostic Tests */
#define KBC_INT_TEST    0xAB /* @brief Tests Keyboard Clock and Data lines */
#define KBC_INT_DISABLE 0xAD /* @brief Disable KBC Interface */
#define KBC_INT_ENABLE  0xAE /* @brief Enable KBC Interface */
#define MOUSE_DISABLE   0xA7 /* @brief Disable Mouse */
#define MOUSE_ENABLE    0xA8 /* @brief Enable Mouse */
#define MOUSE_INT_TEST  0xA9 /* @brief Tests Mouse data line */
#define MOUSE_WRITE_B   0xD4 /* @brief Write a byte directly to the mouse */

/* Status Byte Masking */

#define OUT_BUF_FUL     BIT(0) /* @brief Output Buffer State */
#define IN_BUF_FULL     BIT(1) /* @brief Input Buffer State */
#define SYS_FLAG        BIT(2) /* @brief System Flag */
#define DATA_CMD_WRITE  BIT(3) /* @brief Identifier of type of byte in input buffer */
#define INH_FLAG        BIT(4) /* @brief Keyboard inihibited */
#define AUX_MOUSE       BIT(5) /* @brief Mouse Data */
#define TIME_OUT_REC    BIT(6) /* @brief Time Out Error - Invalid Data */
#define PARITY_ERROR    BIT(7) /* @brief Parity Error - Invalid Data */

/* Scancode Constants */

#define ESC_BREAK_CODE  0x81    /* @brief ESC Break Code */
#define TWO_BYTE_CODE   0xE0    /* @brief First byte of a two byte Scancode */
#define BREAK_CODE_BIT  BIT(7)  /* @brief Bit to distinguish between Make code and Break code */

/* Command byte masks */
#define INT_KBD         BIT(0)  /* @brief Enable Keyboard Interrupts */
#define INT_MOU         BIT(1)  /* @brief Enable Mouse Interrupts */
#define DIS_KBD         BIT(4)  /* @brief Disable Keyboard */
#define DIS_MOU         BIT(5)  /* @brief Disable Mouse */

#endif //KBC_MACROS_H_INCLUDED
