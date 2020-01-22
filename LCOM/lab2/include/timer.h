/**
 * This file concerns everything related to the timer
 */

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

//7.1 timer_test_read_config()
int (timer_get_conf)(uint8_t timer, uint8_t *st);
int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field);
//7.2 timer_test_time_base()
int (timer_set_frequency)(uint8_t timer, uint32_t freq);
//7.3 timer_test_int()
void (timer_int_handler)(void);
int (subscribe_timer_interrupt)(uint8_t interrupt_bit, int *interrupt_id);
uint32_t no_interrupts;

#endif //TIMER_H_INCLUDED
