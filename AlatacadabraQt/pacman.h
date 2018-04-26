#ifndef PACMAN_H
#define PACMAN_H

#include "personnage.h"

class Pacman : public Personnage
{
public:
    Pacman();
    void getPosition() const;
    void move() const;
};

#endif // PACMAN_H
