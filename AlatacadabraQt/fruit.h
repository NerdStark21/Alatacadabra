#ifndef FRUIT_H
#define FRUIT_H

#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <GL/glu.h>

using namespace cv;


class Fruit
{
public:
    Fruit(){}
    Fruit(Point position);

    ~Fruit();
    void setPosition(Point p){position_ = p;}
    Point getPosition(){return position_;}
    void drawFruit();

private:
    Point position_;
    int radius_ = 1;
    GLUquadric* quadrique_;
};

#endif // FRUIT_H
