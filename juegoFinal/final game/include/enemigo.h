#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <allegro.h>

class enemigo {
    public:
        double x;
        double y;
        double velocidad;
        BITMAP* sprite;
        void mov(BITMAP* lienzo);
        enemigo(double x, double y);
        ~enemigo();
};

#endif
