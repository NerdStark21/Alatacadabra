#ifndef MODEL_H
#define MODEL_H

#include <QApplication>
#include <QDesktopWidget>
#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <QTimer>
#include <qdebug.h>
#include "wall.h"
#include "partie.h"
#include "fruit.h"
#include "snake.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

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
    Model();
    void drawWalls();
    void drawGrid();
    void updateGame();
    void createFruit();
};

#endif // MODEL_H
