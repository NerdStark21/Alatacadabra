#ifndef SNAKE_H
#define SNAKE_H

#include "bodypart.h"
#include <vector>

class Snake
{
private:
    // liste des indices auxquels on a les points du snake
    vector<int> listNode_;
    // Diamètre des éléments du snake
    int radius_;
    Point direction_;
    int size_;

public:
    Snake();
    void drawNode();
    void move();
    bool deadlyPLace();
    void eatFruit();
};

#endif // SNAKE_H
