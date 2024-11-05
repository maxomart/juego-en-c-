#include "nave.h"

#include "bala.h"


nave::nave()
{
    x=450;
    y=700;
    velocidad = 0.8;
    sprite = load_bitmap("ship.bmp", NULL);
}



void nave::mov(BITMAP *lienzo)
{
    int limite_izquierdo = 0;
    int limite_derecho = SCREEN_W - sprite->w;
    int limite_superior = 0;
    int limite_inferior = SCREEN_H - sprite->h;


    if(key[KEY_RIGHT] && x < limite_derecho) {
        x += velocidad;
    }
    if(key[KEY_LEFT] && x > limite_izquierdo) {
        x -= velocidad;
    }


    draw_sprite(lienzo,sprite,x,y);
}
