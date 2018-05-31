#ifndef BODYPART_H
#define BODYPART_H

#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <GL/glu.h>


using namespace cv;

class BodyPart
{
private:
    Point center_;
    int radius_;
    GLUquadric *ball_quadric_;

public:
    BodyPart();
    BodyPart(Point center, int radius);
    void drawBodyPart();
    void Display();


    Point getCenter();
    void setCenter(Point p);
};




#endif // BODYPART_H
