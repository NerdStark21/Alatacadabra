#ifndef FANTOME_H
#define FANTOME_H

#include "personnage.h"

class Fantome : public Personnage
{
public:
    Fantome();
    void getPosition() const;
    void move() const;
};

#endif // FANTOME_H
