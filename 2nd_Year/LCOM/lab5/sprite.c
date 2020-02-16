#include <lcom/lcf.h>

#include "sprite.h"

#include "graphics.h"

struct sprite{
    int x, y;
    int w, h;
    uint8_t *map;
};

sprite_t* sprite_ctor(const xpm_map_t xpm){
    sprite_t *ret = (sprite_t*)malloc(sizeof(sprite_t));
    if(ret == NULL) return NULL;
    enum xpm_image_type type = XPM_INDEXED;
    xpm_image_t img;
    ret->map = xpm_load(xpm, type, &img);
    if(ret->map == NULL){
        free(ret);
        return NULL;
    }
    ret->w = img.width;
    ret->h = img.height;
    return ret;
}

void sprite_dtor(sprite_t *p){
    if(p == NULL) return;
    if(p->map) free(p->map);
    free(p);
}

void sprite_set_x(sprite_t *p, int x){ p->x = x; }
void sprite_set_y(sprite_t *p, int y){ p->y = y; }
void sprite_set_pos(sprite_t *p, int x, int y){
    sprite_set_x(p, x);
    sprite_set_y(p, y);
}

int sprite_get_w(const sprite_t *p){ return p->w; }
int sprite_get_h(const sprite_t *p){ return p->h; }

void sprite_draw(const sprite_t *p){
    for (int i = 0; i < p->w; i++) {
        for (int j = 0; j < p->h; j++) {
            if (p->x + i < get_XRes() && p->y + j < get_YRes()) {
                set_pixel(p->x + i, p->y + j, p->map[i + j * p->w]);
            }
        }
    }
}
