#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

struct sprite;
typedef struct sprite sprite_t;

sprite_t* sprite_ctor(const xpm_map_t xpm);
void      sprite_dtor(sprite_t *p);

void sprite_set_x(sprite_t *p, int x);
void sprite_set_y(sprite_t *p, int y);
void sprite_set_pos(sprite_t *p, int x, int y);

int sprite_get_h(const sprite_t *p);
int sprite_get_w(const sprite_t *p);

void sprite_draw(const sprite_t *p);

#endif //SPRITE_H_INCLUDED
