#ifndef PACMAN_H
#define PACMAN_H

#include <string>

class Pacman
{
    private:
        int positionX;
        int positionY;
        int lives;
        int score;
    public:
        Pacman(int positionX, int positionY, int lives, int score);
        void moverte(int direction);
        void eatPellet();
        void loseLife();
        bool isAlive() const;
        /***************************************/
        int getPositionX() const;
        void setPositionX(int newPositionX);
        int getPositionY() const;
        void setPositionY(int newPositionY);
        /***************************************/
        int getLives() const;
        void setLives(int newLives);
        /***************************************/
        int getScore() const;
        void setScore(int newScore);
};

#endif // PACMAN_H
