#ifndef GAME_H
#define GAME_H

#include "Pacman.h"
#include "Ghost.h"
#include "GameBoard.h"


class Game
{
    public:
        void startGame();
        void updateGame();
        void checkCollision();
        void endGame();
    private:
        Pacman pacman;
        Ghost ghosts[4];
        GameBoard board;
        bool isRunning;
};

#endif // GAME_H
