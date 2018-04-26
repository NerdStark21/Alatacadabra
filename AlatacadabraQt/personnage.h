#ifndef PERSONNAGE_H
#define PERSONNAGE_H

class personnage{

public:
    virtual void getPosition() const = 0;
    virtual void move(int direction) const = 0;
}

#endif // PERSONNAGE_H
