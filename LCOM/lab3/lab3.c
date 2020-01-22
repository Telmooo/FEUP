#include <lcom/lcf.h>
#include <lcom/lab3.h>

#include <stdbool.h>
#include <stdint.h>

#include "kbc.h"
#include "kbc_macros.h"
#include "keyboard.h"
#include "timer.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(kbd_test_scan)() {
    /// loop stuff
    int ipc_status, r;
    message msg;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = 1;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if (subscribe_keyboard_interrupt(kbc_irq_bit, &kbc_id)) return 1;
    /// cycle
    int good = 1;
    while (good) {
        /* Get a request message. */
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) { /* received notification */
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE: /* hardware interrupt notification */
                    if (msg.m_notify.interrupts & kbc_irq) { /* subscribed interrupt */
                        kbc_ih();
                        if(keyboard_done)
                            kbd_print_scancode(!(scancode[scancode_sz-1] & BREAK_CODE_BIT), scancode_sz, scancode);
                        if (scancode[0] == ESC_BREAK_CODE) good = 0;
                    }
                    break;
                default:
                    break; /* no other notifications expected: do nothing */
            }
        } else { /* received standart message, not a notification */
            /* no standart message expected: do nothing */
        }
    }

    if (unsubscribe_interrupt(&kbc_id)) return 1;

    if (kbd_print_no_sysinb(sys_inb_counter)) return 1;

    return 0;
}

int(kbd_test_poll)() {
    uint8_t c[2]; uint8_t size;
    do{
        if(keyboard_poll(c, &size)) return 1;
        if(kbd_print_scancode((~c[size-1])&BREAK_CODE_BIT, size, c)) return 1;
    }while(!(size == 1 && c[0] == ESC_BREAK_CODE));

    if(kbc_restore_keyboard()) return 1;

    if(kbd_print_no_sysinb(sys_inb_counter)) return 1;

    return 0;
}

int(kbd_test_timed_scan)(uint8_t idle) {
    /// loop stuff
    int ipc_status, r;
    message msg;
    /// Timer interrupt handling
    const uint32_t frequency = 60; // Frequency asummed at 60Hz
    uint8_t timer_irq_bit = 0;
    int timer_id = 0;
    int timer_irq = BIT(timer_irq_bit);
    if(subscribe_timer_interrupt(timer_irq_bit, &timer_id)) return 1;

    no_interrupts = 0;
    int time = 0;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = 1;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if(subscribe_keyboard_interrupt(kbc_irq_bit, &kbc_id)) return 1;
    /// cycle
    int good = 1;
    while (good) {
        /* Get a request message. */
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) { /* received notification */
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE: /* hardware interrupt notification */
                    if (msg.m_notify.interrupts & timer_irq) { /* subscribed interrupt */
                        timer_int_handler();
                        if (no_interrupts%frequency == 0) time++;
                        if(time >= idle) good = 0;
                    }
                    if (msg.m_notify.interrupts & kbc_irq) { /// subscribed interrupt
                        kbc_ih();
                        if(keyboard_done) {
                            kbd_print_scancode(!(scancode[scancode_sz-1] & BREAK_CODE_BIT), scancode_sz, scancode);
                            time = 0;
                            no_interrupts = 0;
                            if (scancode[0] == ESC_BREAK_CODE) good = 0;
                        }
                    }
                    break;
                default:
                    break; /* no other notifications expected: do nothing */
            }
        } else { /* received standart message, not a notification */
            /* no standart message expected: do nothing */
        }
    }

    if (unsubscribe_interrupt(&kbc_id)) return 1;
    if (unsubscribe_interrupt(&timer_id)) return 1;

    return 0;
}
