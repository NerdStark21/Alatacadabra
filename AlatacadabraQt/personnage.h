#ifndef PERSONNAGE_H
#define PERSONNAGE_H


class Personnage
{
public:
    Personnage();
    virtual void getPosition() const = 0;
    virtual void move() const = 0;
};

#endif // PERSONNAGE_H
