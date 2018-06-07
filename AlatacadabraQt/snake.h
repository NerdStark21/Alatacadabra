#ifndef SNAKE_H
#define SNAKE_H

#include "bodypart.h"
#include <vector>
#include <list>
#include <QImage>

using namespace std;

class Snake
{
private:
    // Vecteur contenant toutes les parties du corps du snake :Le premier élément est la tête.
    list<BodyPart> body_;
    int size_;
    Point direction_;


    int radius_;
    bool dead_;
    bool fruitEaten_;

    QString headImage_;
    Point topLeft_;
    Point bottomRight_;

public:
    Snake(){}
    Snake(int width, int heigth, QString HeadImage);
    void drawNode();
    void Display();
    void move();
    void deadlyPlace();
    void eatFruit();
    void setDirection(Point p);
    list<BodyPart> getBody(){return body_;}
    QString getPath();
    bool getFruitEaten();
    void setFruitEaten(bool fruit);
    bool getDead();
    void setDead(bool dead);

};

#endif // SNAKE_H
