#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>

#include "mouse.h"
#include "kbc.h"
#include "errors.h"
#include "mouse_macros.h"
#include "kbc_macros.h"
#include "timer.h"
#include "state_machine.h"

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int (mouse_test_packet)(uint32_t cnt) {
    /// loop stuff
    int ipc_status, r;
    message msg;
    /// Mouse interrupt handling
    uint8_t mouse_irq_bit = 12;
    int mouse_id = 0;
    int mouse_irq = BIT(mouse_irq_bit);

    if (subscribe_mouse_interrupt(mouse_irq_bit, &mouse_id)) return 1; // subscribes mouse interrupts in exclusive mode
    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(true)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications

    /// cycle
    int good = (cnt != 0);
    uint32_t cnt_now = 0;
    while (good) {
        /* Get a request message. */
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) { /* received notification */
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE: /* hardware interrupt notification */
                    if (msg.m_notify.interrupts & mouse_irq) { /* subscribed interrupt */
                        mouse_ih();
                        if(counter_mouse_ih >= 3){
                            struct packet pp = mouse_parse_packet(packet_mouse_ih);
                            mouse_print_packet(&pp);
                            cnt_now++;
                            if(cnt == cnt_now) good = 0;
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
    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(false)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications
    if (unsubscribe_interrupt(&mouse_id)) return 1; // unsubscribes interrupts
    return 0;
}

int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    //if (mouse_issue_cmd(SET_REMOTE_MD)) return 1;
    //if (mouse_set_data_report(true)) return 1;

    struct packet pp;
    while(cnt--){
        if(mouse_poll(&pp, period)) return 1;
        mouse_print_packet(&pp);
        tickdelay(micros_to_ticks(period*1000));
    }
    // Set Stream mode
    if (mouse_issue_cmd(SET_STREAM_MD)) return 1;
    // Disable data reporting
    if (mouse_set_data_report(false)) return 1;
    uint8_t cmd_byte = minix_get_dflt_kbc_cmd_byte();
    if (kbc_change_cmd(cmd_byte)) return 1;

    return SUCCESS;
}

int (mouse_test_async)(uint8_t idle_time) {
    /// loop stuff
    int ipc_status, r;
    message msg;
    /// Timer interrupt handling
    const uint32_t frequency = sys_hz(); // Frequency asummed at 60Hz
    uint8_t timer_irq_bit = 0;
    int timer_id = 0;
    int timer_irq = BIT(timer_irq_bit);
    if(subscribe_timer_interrupt(timer_irq_bit, &timer_id)) return 1;

    no_interrupts = 0;
    int time = 0;
    /// Mouse interrupt handling
    uint8_t mouse_irq_bit = 12;
    int mouse_id = 0;
    int mouse_irq = BIT(mouse_irq_bit);

    if (subscribe_mouse_interrupt(mouse_irq_bit, &mouse_id)) return 1; // subscribes mouse interrupts in exclusive mode
    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(true)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications

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
                        if(time >= idle_time) good = 0;
                    }
                    if (msg.m_notify.interrupts & mouse_irq) { /// subscribed interrupt
                        mouse_ih();
                        if(counter_mouse_ih >= 3){
                            struct packet pp = mouse_parse_packet(packet_mouse_ih);
                            mouse_print_packet(&pp);
                            time = 0;
                            no_interrupts = 0;
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

    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(false)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications
    if (unsubscribe_interrupt(&mouse_id)) return 1; // unsubscribes interrupts

    if (unsubscribe_interrupt(&timer_id)) return 1;

    return 0;
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
    /// loop stuff
    int ipc_status, r;
    message msg;
    /// Mouse interrupt handling
    uint8_t mouse_irq_bit = 12;
    int mouse_id = 0;
    int mouse_irq = BIT(mouse_irq_bit);

    if (subscribe_mouse_interrupt(mouse_irq_bit, &mouse_id)) return 1; // subscribes mouse interrupts in exclusive mode
    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(true)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications

    /// cycle
    int good = 1;

    // mouse event gesture
    struct mouse_ev *event;
    struct packet pp;
    int response;
    while (good) {
        /* Get a request message. */
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
            printf("driver_receive failed with %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) { /* received notification */
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE: /* hardware interrupt notification */
                    if (msg.m_notify.interrupts & mouse_irq) { /* subscribed interrupt */
                        mouse_ih();
                        if(counter_mouse_ih >= 3) {
                            pp = mouse_parse_packet(packet_mouse_ih);
                            mouse_print_packet(&pp);
                            event = mouse_get_event(&pp);

                            response = state_machine(event, x_len, tolerance);

                            if (response == SUCCESS)
                                good = 0;
                            else if (response == INVALID_STATE)
                                return response;
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

    if (sys_irqdisable(&mouse_id)) return 1; // temporarily disables our interrupts notifications
    if (mouse_set_data_report(false)) return 1; // enables mouse data reporting
    if (sys_irqenable(&mouse_id)) return 1; // re-enables our interrupts notifications
    if (unsubscribe_interrupt(&mouse_id)) return 1; // unsubscribes interrupts

    return 0;
}
