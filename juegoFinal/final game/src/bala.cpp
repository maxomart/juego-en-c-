#include "bala.h"
#include <allegro.h>

bala::bala(double x, double y) {
    this->x = x;
    this->y = y;
    sprite = load_bitmap("bala.bmp", NULL);
}

void bala::mov(BITMAP* lienzo) {
    y -= 1;
    draw_sprite(lienzo, sprite, x, y);
}

bala::~bala() {
    destroy_bitmap(sprite);
}
