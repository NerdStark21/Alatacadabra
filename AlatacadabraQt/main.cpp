#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Initialisation du temps pour avoir des valeurs aléatoires.
    srand (time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
