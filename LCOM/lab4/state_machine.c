#include <lcom/lcf.h>

#include "state_machine.h"
#include "mouse_macros.h"
#include "mouse.h"
#include "errors.h"
#include "utils.h"

struct mouse_ev* mouse_get_event(struct packet *pp) {
    static struct mouse_ev event;
    static uint8_t last = 0;

    if (pp == NULL)
        return &event;

    // current button presses
    uint8_t button_presses = pp->bytes[0] & (LEFT_BUTTON | RIGHT_BUTTON | MIDDLE_BUTTON);
    int16_t delta_x = pp->delta_x;
    int16_t delta_y = pp->delta_y;

    if ((button_presses ^ last) == LEFT_BUTTON && !(last & LEFT_BUTTON)) {
        event.type = LB_PRESSED;
        last |= LEFT_BUTTON;

    } else if ((button_presses ^ last) == RIGHT_BUTTON && !(last & RIGHT_BUTTON)) {
        event.type = RB_PRESSED;
        last |= RIGHT_BUTTON;

    } else if ((button_presses ^ last) == LEFT_BUTTON && (last & LEFT_BUTTON)) {
        event.type = LB_RELEASED;
        last &= ~LEFT_BUTTON;

    } else if ((button_presses ^ last) == RIGHT_BUTTON && (last & RIGHT_BUTTON)) {
        event.type = RB_RELEASED;
        last &= ~RIGHT_BUTTON;

    } else if ((delta_x || delta_y) && (button_presses == last)) {
        event.type = MOUSE_MOV;

    } else
        event.type = BUTTON_EV;

    event.delta_x = delta_x;
    event.delta_y = delta_y;
    return &event;
}

int state_machine(struct mouse_ev* event, uint8_t x_len, uint8_t tolerance) {

    static enum states state = INITIAL;
    static int response = OTHER_ERROR;
    static int x_length = 0;
    static int y_length = 0;

    if (event == NULL)
        return response;

    switch (state) {
        case INITIAL:
            if (event->type == LB_PRESSED)
                state = DRAG_UP;
            break;
        case DRAG_UP:
            if (event->type == MOUSE_MOV) {
                if (event->delta_x < -tolerance || event->delta_y < -tolerance) {
                    state = INITIAL;
                    x_length = 0;
                    y_length = 0;
                    break;
                }

                x_length += event->delta_x;
                y_length += event->delta_y;
            } else if (event->type == LB_RELEASED) {
                if (y_length < x_length || x_length < x_len) {
                    state = INITIAL;
                    x_length = 0;
                    y_length = 0;
                    break;
                }

                state = VERTEX;
                x_length = 0;
                y_length = 0;
            } else {
                state = INITIAL;
                x_length = 0;
                y_length = 0;
            }
            break;
        case VERTEX:
            if (event->type == MOUSE_MOV) {
                x_length += event->delta_x;
                y_length += event->delta_y;
                if (abs(x_length) > tolerance || abs(y_length) > tolerance) {
                    state = INITIAL;
                    x_length = 0;
                    y_length = 0;
                }
            } else if (event->type == RB_PRESSED) {
                state = DRAG_DOWN;
                x_length = 0;
                y_length = 0;
            } else if (event->type == LB_PRESSED) {
                state = DRAG_UP;
                x_length = 0;
                y_length = 0;
            } else {
                state = INITIAL;
                x_length = 0;
                y_length = 0;
            }
            break;
        case DRAG_DOWN:
            if (event->type == MOUSE_MOV) {
                if (event->delta_x < -tolerance || event->delta_y > tolerance) {
                    state = INITIAL;
                    x_length = 0;
                    y_length = 0;
                    break;
                }

                x_length += event->delta_x;
                y_length += event->delta_y;
            } else if (event->type == RB_RELEASED) {
                if (x_length == 0 || y_length == 0) {
                    state = INITIAL;
                    break;
                }

                if (y_length > -x_length || x_length < x_len) {
                    state = INITIAL;
                    x_length = 0;
                    y_length = 0;
                    break;
                }

                state = FINAL;
                response = SUCCESS;
                x_length = 0;
                y_length = 0;
            } else {
                state = INITIAL;
                x_length = 0;
                y_length = 0;
            }
            break;
        case FINAL: // acception state
            response = SUCCESS;
        default: // invalid state / dead state
            response = INVALID_STATE;
    }
    return response;
}
