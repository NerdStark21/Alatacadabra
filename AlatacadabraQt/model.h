#ifndef MODEL_H
#define MODEL_H

#include <QApplication>
#include <QDesktopWidget>
//#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <qdebug.h>
#include "wall.h"
#include "partie.h"
#include "fruit.h"
#include "snake.h"

using namespace cv;

using namespace std;

class Model
{
private:
    vector<Wall> walls_;
    vector<Fruit> fruits_;
    Snake snake_;
    int width_;
    int heigth_;


public:
    Model(int dimension);

    void drawWalls();
    void drawGrid();
    void drawSnake();
    void drawFruits();
    void Display();
    void setSnakeDirection(Point p);
    void intToDirection(int i);
    void createFruit();
    void update();
    void fruitEaten();
};

#endif // MODEL_H
