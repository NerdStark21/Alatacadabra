#ifndef FRUIT_H
#define FRUIT_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;


class Fruit
{
public:
    fruit();
    void setPosition(Point p);
    Point getPosition();

private:
    Point position_;
};

#endif // FRUIT_H
