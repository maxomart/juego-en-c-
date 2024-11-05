#ifndef BALA_H
#define BALA_H

#include <allegro.h>

class bala {
    public:
        double x;
        double y;
        BITMAP* sprite;

        void mov(BITMAP* lienzo);
        bala(double x, double y);
        ~bala();
};

#endif // BALA_H
