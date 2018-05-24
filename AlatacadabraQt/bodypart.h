#ifndef BODYPART_H
#define BODYPART_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class BodyPart
{
private:
    Point center_;
    int radius_;

public:
    BodyPart(Point center, int radius);
    void drawBodyPart();
};

#endif // BODYPART_H
