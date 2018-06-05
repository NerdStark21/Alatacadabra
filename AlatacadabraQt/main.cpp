#include "mainwindow.h"
#include <QApplication>
#include <atomic>
#include "threadmodel.h"

using namespace std;

void runModel(QApplication * a) {
    a->exec();
}

int main(int argc, char *argv[])
{
    atomic<int> * deplacementPipeline(0);

    ThreadModel * threadModel = new ThreadModel(deplacementPipeline, argc, argv);
    threadModel->start();

    /*
    QApplication a(argc, argv);
    MainWindow w(deplacementPipeline);
    w.show();

    a->exec();*/

    return 0;
}
