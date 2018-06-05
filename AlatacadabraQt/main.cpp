#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <atomic>

using namespace std;

void runModel(QApplication * a) {
    a->exec();
}

int main(int argc, char *argv[])
{
    atomic<int> * deplacementPipeline(0);

    QApplication a(argc, argv);
    MainWindow w(deplacementPipeline);
    w.show();

    thread model(runModel, &a);
    model.join();

    return 0;
}
