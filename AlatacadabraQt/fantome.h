#ifndef FANTOME_H
#define FANTOME_H

#include "personnage.h"

class fantome : public personnage
{
public:
    fantome();

    void getPosition() const;
    void move(int direction) const;
};

#endif // FANTOME_H
