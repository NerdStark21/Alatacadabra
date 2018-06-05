#include "threadmodel.h"

ThreadModel::ThreadModel(atomic<int> *directionPipeline, int argc, char *argv[], QObject *parent)
    : QThread(parent)
{
    a_ = QApplication(argc, argv);
    MainWindow w(directionPipeline);
    w.show();
}

void ThreadModel::run()
{
    a_.exec();

}
