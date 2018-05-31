#ifndef BODYPART_H
#define BODYPART_H

#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class BodyPart
{
private:
    Point center_;
    int radius_;

public:
    BodyPart();
    BodyPart(Point center, int radius);
    BodyPart(){}
    void drawBodyPart();


    Point getCenter();
    void setCenter(Point p);
};




#endif // BODYPART_H
