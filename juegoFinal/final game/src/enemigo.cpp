#include "enemigo.h"

enemigo::enemigo(double x, double y) {
    this->x = x;
    this->y = y;
    velocidad = 2;
    sprite = load_bitmap("enemigo1.bmp", NULL);
}

void enemigo::mov(BITMAP* lienzo) {
    draw_sprite(lienzo, sprite, x, y);
}

enemigo::~enemigo() {
    destroy_bitmap(sprite);
}
