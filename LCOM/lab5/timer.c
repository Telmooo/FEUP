#include <lcom/lcf.h>

#include "timer.h"

#include "i8254.h"

int (subscribe_timer_interrupt)(uint8_t interrupt_bit, int *interrupt_id) {
    if (interrupt_id == NULL) return 1;
    *interrupt_id = interrupt_bit;
    return (sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, interrupt_id));
}

uint32_t no_interrupts = 0;
void (timer_int_handler)() {
    no_interrupts++;
}
