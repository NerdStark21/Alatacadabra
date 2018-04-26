#include "myglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creation du widget opengl
    MyGLWidget glWidget;
    glWidget.show();

    return a.exec();
}
