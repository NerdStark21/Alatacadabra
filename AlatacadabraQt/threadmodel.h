#ifndef THREADMODEL_H
#define THREADMODEL_H

#include <atomic>
#include <QApplication>
#include "mainwindow.h"

class ThreadModel : public QThread
{
    QApplication a_;
public:
    ThreadModel(atomic<int> * directionPipeline, int argc, char *argv[], QObject * parent = 0);
    void run();
};

#endif // THREADMODEL_H
