#ifndef SNAKE_H
#define SNAKE_H

#include "bodypart.h"
#include <vector>

class Snake
{
private:
    // Vecteur contenant toutes les parties du corps du snake
    Vector<BodyPart> body_;
    int size_;
    Point direction_;


    int radius_;


    Point topLeft_;
    Point bottomRight_;

public:
    Snake();
    void move();
    bool deadlyPlace();
    void eatFruit();
};

#endif // SNAKE_H
