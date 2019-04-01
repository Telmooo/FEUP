/**
 * @file Subroutines.S
 *
 * @author telmo
 * @since 25-03-2019
 * @version 1.0
 */

.global SUM_ARRAY
.type SUM_ARRAY, %function
.text

SUM_ARRAY:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		W2, WZR
.L0:
	CBZ		W1, .R0
	ADD		W1, W1, -1
	LDR		W3, [X0, X1, LSL 2]
	ADD 	W2, W2, W3
	B		.L0
.R0:
	MOV		W0, W2
	LDP 	X29, X30, [SP], 16
	RET

.global SUM_ARRAY_LL
.type SUM_ARRAY_LL, %function
.text

SUM_ARRAY_LL:
	MOV		X2, XZR
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
.L1:
	CBZ		W1, .R1
	ADD		W1, W1, -1
	LDR		X3, [X0, X1, LSL 3]
	ADD 	X2, X2, X3
	B		.L1
.R1:
	MOV		X0, X2
	LDP		X29, X30, [SP], 16
	RET

.global MAX_ARRAY
.type MAX_ARRAY, %function
.text

MAX_ARRAY:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	CBZ 	W1, .R3
	ADD 	W1, W1, -1
	LDR 	W2, [X0]
	MOV		W4, 1
.L3:
	CBZ 	W1, .R3
	ADD 	W1, W1, -1
	LDR 	W3, [X0, X4, LSL 2]
	ADD		W4, W4, 1
	CMP		W2, W3
	CSEL	W2, W3, W2, LT
	B		.L3
.R3:
	MOV 	W0, W2
	LDP		X29, X30, [SP], 16
	RET

.global MIN_ARRAY_LL
.type MIN_ARRAY_LL, %function
.text

MIN_ARRAY_LL:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	CBZ 	W1, .R4
	ADD 	W1, W1, -1
	LDR 	X2, [X0]
	MOV		W4, 1
.L4:
	CBZ 	W1, .R4
	ADD 	W1, W1, -1
	LDR 	X3, [X0, X4, LSL 3]
	ADD		W4, W4, 1
	CMP		X2, X3
	CSEL	X2, X3, X2, GT
	B		.L4
.R4:
	MOV 	X0, X2
	LDP		X29, X30, [SP], 16
	RET

.global MAX_ARRAY_HW
.type MAX_ARRAY_HW, %function
.text

MAX_ARRAY_HW:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	CBZ 	W1, .R5
	ADD 	W1, W1, -1
	LDRSH 	W2, [X0], 2
.L5:
	CBZ 	W1, .R5
	ADD 	W1, W1, -1
	LDRSH 	W3, [X0], 2
	CMP		W2, W3
	CSEL	W2, W3, W2, LT
	B		.L5
.R5:
	MOV 	W0, W2
	LDP		X29, X30, [SP], 16
	RET

.global AVG_ARRAY_LL
.type AVG_ARRAY_LL, %function
.text

AVG_ARRAY_LL:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		W4, W1
	MOV		X5, X30
	BL		SUM_ARRAY_LL
	MOV		X30, X5
	SDIV	W0, W0, W4
	LDP		X29, X30, [SP], 16
	RET

.global VALUES_IN_INTERVAL
.type VALUES_IN_INTERVAL, %function
.text

VALUES_IN_INTERVAL:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X4, XZR
.L6:
	CBZ		W1, .R6
	LDR		X5, [X0], 8
	ADD		W1, W1, -1
	CMP		X5, X2
	B.LT	.L6
	CMP		X5, X3
	CINC 	X4, X4, LE
	B		.L6
.R6:
	MOV		X0, X4
	LDP		X29, X30, [SP], 16
	RET

.global STR_LEN
.type STR_LEN, %function
.text

STR_LEN:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X1, XZR
.L7:
	LDRB	W2, [X0], 1
	CBZ		W2, .R7
	ADD		X1, X1, 1
	B		.L7
.R7:
	MOV		X0, X1
	LDP		X29, X30, [SP], 16
	RET

.global COUNT_CHAR
.type COUNT_CHAR, %function
.text

COUNT_CHAR:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X2, XZR
.L8:
	LDRB	W3, [X0], 1
	CBZ		W3, .R8
	CMP		W3, W1
	CINC 	X2, X2, EQ
	B		.L8
.R8:
	MOV		X0, X2
	LDP		X29, X30, [SP], 16
	RET

.global COUNT_VOWELS
.type COUNT_VOWELS, %function
.text

COUNT_VOWELS:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X1, XZR
.L9:
	LDRB	W2, [X0], 1
	CBZ		W2, .R9
	CMP		W2, 'a'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'a'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'A'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'e'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'E'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'i'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'I'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'o'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'O'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'u'
	CINC	X1, X1, EQ
	B.EQ	.L9
	CMP		W2, 'U'
	CINC	X1, X1, EQ
	B		.L9
.R9:
	MOV		X0, X1
	LDP		X29, X30, [SP], 16
	RET

.global COUNT_UPPER
.type COUNT_UPPER, %function
.text

COUNT_UPPER:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X1, XZR
.L10:
	LDRB	W2, [X0], 1
	CBZ		W2, .R10
	CMP		W2, 'A'
	B.LT	.L10
	CMP		W2, 'Z'
	CINC	X1, X1, LE
	B		.L10
.R10:
	MOV		X0, X1
	LDP		X29, X30, [SP], 16
	RET

.global PALINDROME
.type PALINDROME, %function
.text

PALINDROME:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X9, X0
	BL		STR_LEN
	ADD		X0, X0, -1
	MOV		X10, X0
	ADD		X10, X9, X0
	MOV		X0, 1
	MOV 	W3, 0xDF
.L11:
	CMP		X9, X10
	B.GE	.R11
	LDRB	W1, [X9], 1
	CMP		W1, 'A'
	B.LT	.L11
	AND		W1, W1, W3
	CMP		W1, 'Z'
	B.GT	.L11
	B		.L13
.L12:
	CMP		X9, X10
	B.GE	.R11
.L13:
	LDRB	W2, [X10], -1
	CMP		W2, 'A'
	B.LT	.L12
	AND		W2, W2, W3
	CMP		W2, 'Z'
	B.GT	.L12
	CMP		W1, W2
	B.EQ	.L11
	MOV		X0, XZR
.R11:
	LDP		X29, X30, [SP], 16
	RET

.global COUNT_WORDS
.type COUNT_WORDS, %function
.text

COUNT_WORDS:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X1, ' '
	BL		COUNT_CHAR
	LDP		X29, X30, [SP], 16
	RET

.global UBYTE_TO_UDOUBLEWORD_ARRAY
.type UBYTE_TO_UDOUBLEWORD_ARRAY, %function
.text

UBYTE_TO_UDOUBLEWORD_ARRAY:
	STP 	X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X16, X0
	MOV		X17, X1
	MOV		X0, X1
	LSL		X0, X0, 3
	BL		malloc
	MOV		X1, XZR
.L14:
	CBZ		X17, .R14
  	LDRB	W2, [X16, X1]
    STR		X2, [X0, X1, LSL 3]
  	ADD		X1, X1, 1
  	ADD		X17, X17, -1
  	B		.L14
.R14:
	LDP		X29, X30, [SP], 16
	RET

.global SBYTE_TO_SDOUBLEWORD_ARRAY
.type SBYTE_TO_SDOUBLEWORD_ARRAY, %function
.text

SWORD_TO_SDOUBLEWORD_ARRAY:
	STP 	X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X16, X0
	MOV		X17, X1
	MOV		X0, X1
	LSL		X0, X0, 1
	BL		malloc
	MOV		X1, XZR
.L15:
	CBZ		X17, .R15
  	LDRSW	X2, [X16, X1]
    STR	X2, [X0, X1, LSL 3]
    ADD		X1, X1, 1
  	ADD		X17, X17, -1
  	B		.L15
.R15:
	LDP		X29, X30, [SP], 16
	RET

.global POS1_MSB
.type POS1_MSB, %function
.text

POS1_MSB:
	STP 	X29, X30, [SP, -16]!
	MOV		X29, SP
	CLZ		X1, X0
	ADD		W0, W1, -63
	NEG		W0, W0
	LDP		X29, X30, [SP], 16
	RET

.global PAL8
.type PAL8, %function
.text

PAL8:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X1, X0
	MOV		X2, X0
	ADD		X2, X2, 7
	MOV		X0, 1
.L16:
	CMP		X1, X2
	B.GE	.R16
	LDRB	W3, [X1], 1
	LDRB	W4, [X2], -1
	CMP		W3, W4
	B.EQ	.L16
	MOV		X0, XZR
.R16:
	LDP		X29, X30, [SP], 16
	RET

.global N_PALINDROME
.type N_PALINDROME, %function
.text

N_PALINDROME:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	RBIT	W1, W0
	CMP		W0, W1
	CSET	W0, EQ
	LDP		X29, X30, [SP], 16
	RET

.global LSL_8
.type LSL_8, %function
.text

LSL_8:
	STP		X29, X30, [SP, -16]!
	MOV 	X29, SP
	BFI		X0, X0, 8, 56
	BFM		X0, XZR, 0, 7
	LDP		X29, X30, [SP], 16
	RET

.global ASR_8
.type ASR_8, %function
.text

ASR_8:
	STP		X29, X30, [SP, -16]!
	MOV 	X29, SP
	SBFX	X0, X0, 8, 56
	LDP		X29, X30, [SP], 16
	RET

.global ROR_3
.type ROR_3, %function
.text

ROR_3:
	STP		X29, X30, [SP, -16]!
	MOV 	X29, SP
	UBFX	X1, X0, 0, 3
	UBFX	X0, X0, 3, 61
	BFI		X0, X1, 61, 3
	LDP		X29, X30, [SP], 16
	RET

.global ARRAY_ADD
.type ARRAY_ADD, %function
.text

ARRAY_ADD:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
.L17:
	CBZ		X3, .R17
	LDR		X4, [X0], 8
	LDR		X5, [X1], 8
	ADD		X4, X4, X5
	STR		X4, [X2], 8
	ADD		X3, X3, -1
	B 		.L17
.R17:
	STP		X29, X30, [SP], 16
	RET

.global ARRAY_ADD_VS
.type ARRAY_ADD_VS, %function
.text

ARRAY_ADD_VS:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X9, 3
	ROR		X9, X9, 2	// INT_MIN
	MOV		X10, -1
	LSR		X10, X10, 1 // INT_MAX
.L18:
	CBZ		X3, .R18
	LDR		X4, [X0], 8
	LDR		X5, [X1], 8
	ADDS	X4, X4, X5
	B.VC	.VC18
	CSEL	X4, X9, X10, PL
.VC18:
	STR		X4, [X2], 8
	ADD		X3, X3, -1
	B		.L18
.R18:
	LDP		X29, X30, [SP], 16
	RET

.global ARRAY_MUL_SCALAR
.type ARRAY_MUL_SCALAR, %function
.text

ARRAY_MUL_SCALAR:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
.L19:
	CBZ		X1, .R19
	LDR		X3, [X0]
	MUL		X3, X3, X2
	STR		X3, [X0], 8
	ADD		X1, X1, -1
	B		.L19
.R19:
	LDP		X29, X30, [SP], 16
	RET

.global DOT_PRODUCT
.type DOT_PRODUCT, %function
.text

DOT_PRODUCT:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X3, XZR
.L20:
	CBZ		X2, .R20
	ADD		X2, X2, -1
	LDR		W4, [X0], 4
	LDR		W5, [X1], 4
	SMADDL	X3,	W4, W5, X3
	B		.L20
.R20:
	MOV		X0, X3
	LDP		X29, X30, [SP], 16
	RET

.global DOT_PRODUCT_VS
.type DOT_PRODUCT_VS, %function
.text

DOT_PRODUCT_VS:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	MOV		X3, X0
	MOV		X0, XZR
	MOV		X9, 3
	ROR		X9, X9, 2	// INT_MIN
	MOV		X10, -1
	LSR		X10, X10, 1 // INT_MAX
.L21:
	CBZ		X2, .R21
	ADD		X2, X2, -1
	LDR		W4, [X3], 4
	LDR		W5, [X1], 4
	SMULL	X4,	W4, W5
	ADDS	X0, X0, X4
	B.VS	.VS21
	B		.L21
.VS21:
	CSEL	X0, X9, X10, PL
.R21:
	LDP		X29, X30, [SP], 16
	RET

.global MIN_BITS
.type MIN_BITS, %function
.text

MIN_BITS:
	STP		X29, X30, [SP, -16]!
	MOV		X29, SP
	CLZ		X0, X0
	ADD		X0, X0, -64
	NEGS	X0, X0
	CSINC	X0, X0, XZR, NE
	LDP		X29, X30, [SP], 16
	RET
