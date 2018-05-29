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

using namespace std;

class Model
{
private:
    vector<Wall> walls_;
    vector<Fruit> fruits_;


public:
    Model();
    void drawWalls();
    void drawGrid();
    void updateGame();
    void createFruit();
};

#endif // MODEL_H
