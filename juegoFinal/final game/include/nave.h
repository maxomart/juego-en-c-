#include <allegro.h>

class nave
{
    public:
        double x;
        double y;
        double velocidad;
        BITMAP* sprite;

        void mov(BITMAP *lienzo);
        nave();

};


