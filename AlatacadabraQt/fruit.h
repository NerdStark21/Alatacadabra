#ifndef FRUIT_H
#define FRUIT_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;


class Fruit
{
public:
    Fruit();
private:
    Point position;
};

#endif // FRUIT_H
