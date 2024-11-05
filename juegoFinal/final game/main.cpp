#include <allegro.h>
#include "nave.h"
#include "bala.h"
#include "enemigo.h"
#include <iostream>


#define MAX_BALAS 10
#define MAX_ENEMIGOS 11
#define ENEMY_SPEED 0.1
#define SCREEN_MARGIN 20
#define ENEMY_DROP 10

BITMAP* lienzo;
nave* miNave;
bala* balas[MAX_BALAS] = { NULL };
enemigo* enemigos[MAX_ENEMIGOS] = { NULL };

bool movingRight = true; // Dirección inicial de los enemigos
double enemySpeed = ENEMY_SPEED;

void init();
void deinit();
void verificarColisiones();

int main() {
    init();

    lienzo = create_bitmap(SCREEN_W, SCREEN_H);
    miNave = new nave();

    // Crear enemigos en una fila horizontal con separación
    for (int i = 0; i < MAX_ENEMIGOS; i++) {
        enemigos[i] = new enemigo(100 + (i * 70), 50); // Posiciones iniciales de enemigos
    }

    while (!key[KEY_ESC]) {
        miNave->mov(lienzo);

        // Disparo de bala
        if (key[KEY_SPACE]) {
            for (int i = 0; i < MAX_BALAS; i++) {
                if (balas[i] == NULL) {
                    balas[i] = new bala(miNave->x + miNave->sprite->w / 2, miNave->y);
                    break;
                }
            }
        }

        // Mover y dibujar balas
        for (int i = 0; i < MAX_BALAS; i++) {
            if (balas[i] != NULL) {
                balas[i]->mov(lienzo);
                if (balas[i]->y <= 0) {
                    delete balas[i];
                    balas[i] = NULL;
                }
            }
        }

        // Verificar colisiones entre balas y enemigos
        verificarColisiones();

        // Movimiento de los enemigos al estilo Space Invaders
        bool atEdge = false;
        for (int i = 0; i < MAX_ENEMIGOS; i++) {
            if (enemigos[i] != NULL) {
                int nextX = enemigos[i]->x + (movingRight ? enemySpeed : -enemySpeed);
                if (nextX <= SCREEN_MARGIN || nextX >= SCREEN_W - SCREEN_MARGIN - 32) {
                    atEdge = true;
                    break;
                }
            }
        }

        // Cambiar dirección y bajar una línea si algún enemigo alcanza el borde
        if (atEdge) {
            movingRight = !movingRight;
            for (int i = 0; i < MAX_ENEMIGOS; i++) {
                if (enemigos[i] != NULL) {
                    enemigos[i]->y += ENEMY_DROP;
                }
            }
        }

        // Mover todos los enemigos en la dirección actual
        for (int i = 0; i < MAX_ENEMIGOS; i++) {
            if (enemigos[i] != NULL) {
                enemigos[i]->x += movingRight ? enemySpeed : -enemySpeed;
                enemigos[i]->mov(lienzo); // Dibujar enemigo en la nueva posición
            }
        }

        // Dibujar el lienzo en pantalla
        draw_sprite(screen, lienzo, 0, 0);
        clear_to_color(lienzo, 0x000000);
    }

    // Liberar memoria de los enemigos y las balas


    deinit();
    return 0;
}
END_OF_MAIN()

void verificarColisiones()
{
    for (int i = 0; i < MAX_ENEMIGOS; i++)
    {
        if (enemigos[i] != NULL) // Asegurarse de que el enemigo exista
        {
            for (int j = 0; j < MAX_BALAS; j++)
            {
                if (balas[j] != NULL) // Asegurarse de que la bala exista
                {
                    // Verificar si la bala y el enemigo están en la misma posición
                    if (balas[j]->x >= enemigos[i]->x &&
                        balas[j]->x <= enemigos[i]->x + enemigos[i]->sprite->w &&
                        balas[j]->y >= enemigos[i]->y &&
                        balas[j]->y <= enemigos[i]->y + enemigos[i]->sprite->h)
                    {

                         std::cout << "Colisión detectada entre bala y enemigo en ("
                                  << balas[j]->x << ", " << balas[j]->y << ")" << std::endl;
                        // Colisión detectada, elimina la bala y el enemigo
                        delete balas[j];
                        balas[j] = NULL;
                        delete enemigos[i];
                        enemigos[i] = NULL;
                        std::cout << "Colisión detectada entre bala y enemigo!" << std::endl;
                        break;

                    }
                }
            }
        }
    }
}


void init() {
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if (depth == 0) depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 960, 800, 0, 0);
    if (res != 0) {
        allegro_message(allegro_error);
        exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
}

void deinit() {
    clear_keybuf();
}
