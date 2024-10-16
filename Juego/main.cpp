#include "tau/tau.h"
#include "Pacman.h"

TAU_MAIN()

TEST(Pacman, ClasePacman)
{
    Pacman elPacman(0, 0, 3, 0);

    CHECK(elPacman.getPositionX() == 0);
    CHECK(elPacman.getPositionY() == 0);
    CHECK(elPacman.isAlive() == true);
    CHECK(elPacman.getScore() == 0);
    CHECK(elPacman.getLives() == 3);

    elPacman.setPositionX(5);
    elPacman.setPositionY(10);
    elPacman.loseLife();
    elPacman.setScore(100);

    CHECK(elPacman.getPositionX() == 5);
    CHECK(elPacman.getPositionY() == 10);
    CHECK(elPacman.isAlive() == true);
    CHECK(elPacman.getScore() == 100);
    CHECK(elPacman.getLives() == 2);
}
