/**
 * @file Subroutines.h
 *
 * @author telmo
 * @since 25-03-2019
 * @version 1.0
 */

#pragma once

typedef unsigned int UInt;
typedef long long LLong;
typedef unsigned long long ULLong;

extern int SUM_ARRAY(int *arr, UInt size);

extern int MAX_ARRAY(int *arr, UInt size);

extern LLong MIN_ARRAY_LL(LLong *arr, UInt size);

extern short MAX_ARRAY_HW(short *arr, UInt size);

extern LLong AVG_ARRAY_LL(LLong *arr, UInt size);

extern UInt VALUES_IN_INTERVAL(LLong *arr, UInt size, LLong a, LLong b);

extern ULLong STR_LEN(char *str);

extern ULLong COUNT_CHAR(char *str, char c);

extern ULLong COUNT_VOWELS(char *str);

extern ULLong COUNT_UPPER(char *str);

extern int PALINDROME(char *str);

extern ULLong COUNT_WORDS(char *str);

extern ULLong* UBYTE_TO_UDOUBLEWORD_ARRAY(char* arr, ULLong size);

extern LLong* SWORD_TO_SDOUBLEWORD_ARRAY(int* arr, ULLong size);

extern int POS1_MSB(LLong n);

extern UInt PAL8(char *s);

extern UInt N_PALINDROME(int n);

extern LLong LSL_8(LLong x);

extern LLong ASR_8(LLong x);

extern LLong ROR_3(LLong x);

extern void ARRAY_ADD(LLong *arr1, LLong *arr2, LLong *result, ULLong size);

extern void ARRAY_ADD_VS(LLong *arr1, LLong *arr2, LLong *result, ULLong size);

extern void ARRAY_MUL_SCALAR(LLong *arr, ULLong size, LLong scalar);

extern LLong DOT_PRODUCT(int *arr1, int *arr2, ULLong size);

extern LLong DOT_PRODUCT_VS(int *arr1, int *arr2, ULLong size);

extern UInt MIN_BITS(LLong x);
