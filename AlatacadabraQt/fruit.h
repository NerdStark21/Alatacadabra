#ifndef FRUIT_H
#define FRUIT_H


#include "opencv2/core/version.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <GL/glu.h>
#include <QImage>

using namespace cv;


class Fruit
{
public:
    Fruit(){}
    Fruit(Point position, QString path, int randomImg);
    ~Fruit();
    void setPosition(Point p){position_ = p;}
    Point getPosition(){return position_;}
    void drawFruit();
    QString getPath();
    int getRandomImg();

private:
    Point position_;
    float radius_ = 1.5;
    GLUquadric* quadrique_;
    QString path_;
    int randomImg_;
};

#endif // FRUIT_H
