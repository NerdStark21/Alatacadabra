#ifndef WALL_H
#define WALL_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <GL/glu.h>
#include <vector>

using namespace cv;

class Wall
{
private:
    Rect stuff_;
    int depth_;

public:
    Wall(Rect stuff);
    void drawWall();
};

#endif // WALL_H
