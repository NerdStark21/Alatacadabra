#ifndef MODEL_H
#define MODEL_H

#include <QApplication>
#include <QDesktopWidget>
#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <QTimer>
#include <GL/glu.h>
#include <qdebug.h>
#include "snake.h"
#include "wall.h"
#include "partie.h"

using namespace std;

class Model
{
private:
    vector<Wall> walls_;

public:
    Model();
    void drawWalls();
};

#endif // MODEL_H
