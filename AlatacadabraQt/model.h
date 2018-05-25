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
#include "grid.h"

using namespace std;

class Model
{
private:
    vector<Wall> walls_;

public:
    Model();
    void drawWalls();
    void drawGrid();
    void updateGame();
};

#endif // MODEL_H
