/**
 * This file concerns everything related to the timer
 */

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <stdint.h>

/**
 * @brief Subscribes Timer Interrupts and disables Minix Default IH
 * @param interrupt_bit Bit of Interrupt Vector that will be set when Timer Interrupt is pending
 * @param interrupt_id Timer Interrupt ID to specify the Timer Interrupt in other calls
 * @return ERROR_CODE code representing the result of the operation, SUCCESS code is returned if everything is OK
 * @see {_ERRORS_H_::errors}
 */
int (subscribe_timer_interrupt)(uint8_t interrupt_bit, int *interrupt_id);

int no_interrupts;

#endif //TIMER_H_INCLUDED
