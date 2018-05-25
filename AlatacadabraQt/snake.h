#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "bodypart.h"

class Snake
{
private:
    Point direction_;
    int size_;
    Vector<BodyPart> body_;

public:
    Snake();
    void drawSnake();
    void move();
    bool deadlyPLace();
    void eatFruit();
};

#endif // SNAKE_H
