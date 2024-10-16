#include "Pacman.h"

Pacman::Pacman(int posX, int posY, int lives, int score)
    : positionX(posX), positionY(posY), lives(lives), score(score)
{
}

void Pacman::loseLife()
{
    if (lives > 0) {
        lives--;
    }
}

bool Pacman::isAlive() const
{
    return lives > 0;
}
int Pacman::getPositionX() const
{
    return positionX;
}

void Pacman::setPositionX(int newPositionX)
{
    positionX = newPositionX;
}

int Pacman::getPositionY() const
{
    return positionY;
}

void Pacman::setPositionY(int newPositionY)
{
    positionY = newPositionY;
}

int Pacman::getLives() const
{
    return lives;
}
void Pacman::setLives(int newLives)
{
    lives = newLives;
}
int Pacman::getScore() const
{
    return score;
}

void Pacman::setScore(int newScore)
{
    score = newScore;
}

