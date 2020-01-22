#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include <stdint.h>
#include <stdio.h>

#include "sprite.h"
#include "graphics.h"
#include "graphics_macros.h"
#include "keyboard.h"
#include "kbc.h"
#include "kbc_macros.h"
#include "timer.h"
#include "utils.h"

// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
    // sets the language of LCF messages (can be either EN-US or PT-PT)
    lcf_set_language("EN-US");

    // enables to log function invocations that are being "wrapped" by LCF
    // [comment this out if you don't want/need it]
    lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

    // enables to save the output of printf function calls on a file
    // [comment this out if you don't want/need it]
    lcf_log_output("/home/lcom/labs/lab5/output.txt");

    // handles control over to LCF
    // [LCF handles command line arguments and invokes the right function]
    if (lcf_start(argc, argv))
    return 1;

    // LCF clean up tasks
    // [must be the last statement before return]
    lcf_cleanup();

    return 0;
}

int(video_test_init)(uint16_t mode, uint8_t delay) {

    if (vbe_get_mode_information(mode)) {
        printf("%s: failed to get information for mode %x.\n", __func__, mode);
        if (vg_exit())
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        return 1;
    }

    map_vram(); // if function fails it aborts program

    if (set_graphics_mode(mode)) {
        printf("%s: failed to set graphic mode %x.\n", __func__, mode);
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    tickdelay(micros_to_ticks(delay*1e6));

    if (vg_exit()) {
        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map())
            printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    if (free_memory_map()) {
        printf("%s: lm_free failed\n", __func__);
        return 1;
    }
    return 0;
}

// lcom_run lab5 "rectangle 105 100 100 100 100 1"
// lcom_run lab5 "rectangle 115 100 100 100 100 FF0000"
int(video_test_rectangle)(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) {
    int r;

    if (vbe_get_mode_information(mode)) {
        printf("%s: failed to get information for mode %x.\n", __func__, mode);
        if (vg_exit())
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        return 1;
    }

    map_vram(); // if function fails it aborts program

    if (set_graphics_mode(mode)) {
        printf("%s: failed to set graphic mode %x.\n", __func__, mode);
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    uint16_t w = (x + width > get_XRes()) ? (get_XRes() - x) : (width);
    uint16_t h = (y + height > get_YRes()) ? (get_YRes() - y) : (height);

    if (x < get_XRes() && y < get_YRes()) {
        if (vg_draw_rectangle(x, y, w, h, color)) {
            if (vg_exit()) {
                printf("%s: vg_exit failed to exit to text mode.\n", __func__);
            }
            if (free_memory_map()) {
                printf("%s: lm_free failed\n", __func__);
            }
            return 1;
        }
    }

    /// loop stuff
    int ipc_status;
    message msg;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = KBC_IRQ;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if (subscribe_kbc_interrupt(kbc_irq_bit, &kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }
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

    if (unsubscribe_interrupt(&kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    if (vg_exit()) {
        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    if (free_memory_map()) {
        printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    return 0;
}

int(video_test_pattern)(uint16_t mode, uint8_t no_rectangles, uint32_t first, uint8_t step) {
    int r;

    if (vbe_get_mode_information(mode)) {
        printf("%s: failed to get information for mode %x.\n", __func__, mode);
        if (vg_exit())
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        return 1;
    }

    map_vram(); // if function fails it aborts program

    if (set_graphics_mode(mode)) {
        printf("%s: failed to set graphic mode %x.\n", __func__, mode);
        if (vg_exit()) printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    uint16_t W = get_XRes()/no_rectangles;
    uint16_t H = get_YRes()/no_rectangles;

    uint32_t color, R, G, B;
    for(uint8_t row = 0; row < no_rectangles; ++row){
        for(uint8_t col = 0; col < no_rectangles; ++col){
            if(get_bytes_pixel() == 1){
                color = (first + (row * no_rectangles + col) * step) % (1 << get_bits_pixel());
            }else{
                R = (GET_RED(first) + col*step) % (1 << get_RedMaskSize());
                G = (GET_GRE(first) + row*step) % (1 << get_GreenMaskSize());
                B = (GET_BLU(first) + (col+row)*step) % (1 << get_BlueMaskSize());
                color = SET_COLOR(R,G,B);
            }
            uint16_t x = col * W;
            uint16_t y = row * H;
            uint16_t w = (x + W > get_XRes()) ? (get_XRes() - x) : (W);
            uint16_t h = (y + H > get_YRes()) ? (get_YRes() - y) : (H);

            if (x < get_XRes() && y < get_YRes()) {
                if (vg_draw_rectangle(x,y,w,h,color)) {
                    if (vg_exit()) {
                        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
                    }
                    if (free_memory_map()) {
                        printf("%s: lm_free failed\n", __func__);
                    }
                    return 1;
                }
            }
        }
    }
    /// loop stuff
    int ipc_status;
    message msg;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = KBC_IRQ;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if (subscribe_kbc_interrupt(kbc_irq_bit, &kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }
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

    if (unsubscribe_interrupt(&kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    if (vg_exit()) {
        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    if (free_memory_map()) {
        printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    return 0;
}

int(video_test_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
    int r;

    if (vbe_get_mode_information(INDEXED_1024_768)) {
        printf("%s: failed to get information for mode %x.\n", __func__, INDEXED_1024_768);
        if (vg_exit())
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        return 1;
    }

    map_vram(); // if function fails it aborts program

    if (set_graphics_mode(INDEXED_1024_768)) {
        printf("%s: failed to set graphic mode %x.\n", __func__, INDEXED_1024_768);
        if (vg_exit()) printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    sprite_t *sp = sprite_ctor(xpm);
    sprite_set_pos(sp, x, y);
    sprite_draw(sp);

    /// loop stuff
    int ipc_status;
    message msg;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = KBC_IRQ;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if (subscribe_kbc_interrupt(kbc_irq_bit, &kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }
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

    if (unsubscribe_interrupt(&kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    if (vg_exit()) {
        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    if (free_memory_map()) {
        printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    return 0;
}

int(video_test_move)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate) {
    int r;

    if (vbe_get_mode_information(INDEXED_1024_768)) {
        printf("%s: failed to get information for mode %x.\n", __func__, INDEXED_1024_768);
        if (vg_exit())
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        return 1;
    }

    map_vram(); // if function fails it aborts program

    if (set_graphics_mode(INDEXED_1024_768)) {
        printf("%s: failed to set graphic mode %x.\n", __func__, INDEXED_1024_768);
        if (vg_exit()) printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    sprite_t *sp = sprite_ctor(xpm);

    /// Timer interrupt handling
    const uint32_t frequency = sys_hz(); // Frequency asummed at 60Hz
    uint8_t timer_irq_bit = 0;
    int timer_id = 0;
    int timer_irq = BIT(timer_irq_bit);
    if(subscribe_timer_interrupt(timer_irq_bit, &timer_id)) {
        if (vg_exit()) printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }

    no_interrupts = 0;
    /// Keyboard interrupt handling
    uint8_t kbc_irq_bit = KBC_IRQ;
    int kbc_id = 0;
    int kbc_irq = BIT(kbc_irq_bit);
    if (subscribe_kbc_interrupt(kbc_irq_bit, &kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }
    ///
    int16_t v = (speed <= 0 ? 1 : speed);
    int16_t vx = 0, vy = 0;
    if(xi != xf) vx = (xi < xf ? v : -v);
    else         vy = (yi < yf ? v : -v);

    uint16_t Nt     = (speed <  0 ? -speed : 1);
    uint32_t ticks_per_frame = frequency/(uint32_t)fr_rate;

    /// loop stuff
    int ipc_status;
    message msg;
    /// cycle
    uint16_t x = xi, y = yi;

    sprite_set_pos(sp,x,y);
    clear_screen();
    sprite_draw(sp);

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
                        if(no_interrupts == Nt*ticks_per_frame){

                            if(vx) {
                                uint16_t x_clear = (vx > 0 ? x : x+sprite_get_w(sp)+vx);
                                uint16_t y_clear = y;
                                uint16_t w = (x + abs(v) > get_XRes()) ? (get_XRes() - x) : (abs(v));
                                uint16_t h = (y + sprite_get_h(sp) > get_YRes()) ? (get_YRes() - y) : (sprite_get_h(sp));

                                if (x_clear < get_XRes() && y_clear < get_YRes()) {
                                    if (draw_rectangle(x_clear,y_clear,w,h, BLACK)) {
                                        if (vg_exit()) {
                                            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
                                        }
                                        if (free_memory_map()) {
                                            printf("%s: lm_free failed\n", __func__);
                                        }
                                        return 1;
                                    }
                                }
                            }
                            if(vy) {
                                uint16_t x_clear = x;
                                uint16_t y_clear = (vy > 0 ? y : y+sprite_get_h(sp)+vy);
                                uint16_t w = (x + sprite_get_w(sp) > get_XRes()) ? (get_XRes() - x) : (sprite_get_w(sp));
                                uint16_t h = (y + abs(v) > get_YRes()) ? (get_YRes() - y) : (abs(v));

                                if (x_clear < get_XRes() && y_clear < get_YRes()) {
                                    if (draw_rectangle(x_clear,y_clear,w,h, BLACK)) {
                                        if (vg_exit()) {
                                            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
                                        }
                                        if (free_memory_map()) {
                                            printf("%s: lm_free failed\n", __func__);
                                        }
                                        return 1;
                                    }
                                }
                            }

                            vx = (vx > 0 ? min(vx, xf-x) : max(vx, xf-x) );
                            vy = (vy > 0 ? min(vy, yf-y) : max(vy, yf-y) );
                            x += vx;
                            y += vy;
                            sprite_set_pos(sp,x,y);
                            sprite_draw(sp);

                            no_interrupts = 0;
                        }
                    }
                    if (msg.m_notify.interrupts & kbc_irq) { /* subscribed interrupt */
                        kbc_ih();
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

    if (unsubscribe_interrupt(&kbc_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    };

    if (unsubscribe_interrupt(&timer_id)) {
        if (vg_exit()) {
            printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        }
        if (free_memory_map()) {
            printf("%s: lm_free failed\n", __func__);
        }
        return 1;
    }

    if (vg_exit()) {
        printf("%s: vg_exit failed to exit to text mode.\n", __func__);
        if (free_memory_map()) printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    if (free_memory_map()) {
        printf("%s: lm_free failed\n", __func__);
        return 1;
    }

    return 0;
}

int(video_test_controller)() {

    vg_vbe_contr_info_t cntrl_info;

    if (vbe_get_controller_information(&cntrl_info)) {
        printf("%s: vbe_get_controller_information failed to get controller info.\n", __func__);
        return 1;
    }

    if (vg_display_vbe_contr_info(&cntrl_info)) {
        printf("%s: vg_display_vbe_contr_info failed to display controller info.\n", __func__);
        return 1;
    }

    return 0;
}
