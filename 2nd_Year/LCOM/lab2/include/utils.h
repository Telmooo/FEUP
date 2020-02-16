#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

/**
 * @brief Gets the least significant byte of a 16-bit variable
 * @param val 16-bit variable
 * @param lsb Pointer to a 8-bit variable to store the value of the LSB
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int(util_get_LSB)(uint16_t val, uint8_t *lsb);

/**
 * @brief Gets the most significant byte of a 16-bit variable
 * @param val 16-bit variable
 * @param lsb Pointer to a 8-bit variable to store the value of the MSB
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int(util_get_MSB)(uint16_t val, uint8_t *msb);

#ifdef LAB3
    uint32_t sys_inb_counter;
#endif

/**
 * @brief sys_inb wrapper
 * @param port Port to read from
 * @param value Pointer to byte to store value read
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int (util_sys_inb)(int port, uint8_t *value);

/**
 * @brief Unsubcribes Interrupts
 * @param interrupt_id Interrupt ID, value via arguments on subscription of the interrupt_id
 * @see subscribe_kbc_interrupt, subscribe_timer_interrupt
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 */
int (unsubscribe_interrupt)(int *interrupt_id);

/**
 * @brief Gets the minimum value out of two values.
 * @param a     First value
 * @param b     Second value
 * @return  The minimum of the two values
 */
int32_t min(int32_t a, int32_t b);

/**
 * @brief Gets the maximum value out of two values.
 * @param a     First value
 * @param b     Second value
 * @return  The maximum of the two values
 */
int32_t max(int32_t a, int32_t b);


#endif //UTILS_H_INCLUDED
