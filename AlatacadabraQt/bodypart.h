#ifndef BODYPART_H
#define BODYPART_H

#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <GL/glu.h>
#include <QImage>


using namespace cv;

class BodyPart
{
private:
    Point center_;
    float radius_;
    GLUquadric *ball_quadric_;
    bool head_;

public:
    BodyPart(Point center,bool head);
    BodyPart(){}
    void Display(QImage headImage);
    Point getCenter(){return center_;}
    void setCenter(Point p){center_ = p;}
};




#endif // BODYPART_H
