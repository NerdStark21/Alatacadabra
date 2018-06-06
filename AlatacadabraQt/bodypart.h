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
    QString headImage_;

public:
    BodyPart(Point center, bool head, QString headImage);
    BodyPart(){}
    void Display(QString headImage);
    Point getCenter(){return center_;}
    void setCenter(Point p){center_ = p;}
    bool getHead();
    void setHead(bool head);
};




#endif // BODYPART_H
