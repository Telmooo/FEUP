#ifndef GRAPHICS_MACROS_H_INCLUDED
#define GRAPHICS_MACROS_H_INCLUDED

#define VC_BIOS_SERV  0x10 /** @brief TODO */
#define VBE_CALL      0x4F /** @brief TODO */

#define MBYTE_BASE  0x0
#define MBYTE_SIZE  0xFFFFF

// Graphics Functions
#define VBE_CTRL_INFO       0x00 /** @brief Get VBE Controller Information */
#define VBE_MD_INFO         0x01 /** @brief Get VBE Mode Information */
#define SET_VBE_MD          0x02 /** @brief Set VBE Mode */

// Error codes (AH)
#define AH_SUCCESS          0x00
#define AH_FUNC_CALL_FAIL   0x01
#define AH_FUNC_NOT_SUPP    0x02
#define AH_FUNC_INVALID     0x03

// Graphics modes
#define INDEXED_1024_768        0x105
#define DIRECT_640_480          0x110
#define DIRECT_800_600          0x115
#define DIRECT_1280_1024_565    0x11A
#define DIRECT_1280_1024_888    0x11B
#define LINEAR_FRAME_BUFFER_MD  BIT(14)

// Colors
#define BLACK               0x00

#endif /* end of include guard: GRAPHICS_MACROS_H_INCLUDED */
