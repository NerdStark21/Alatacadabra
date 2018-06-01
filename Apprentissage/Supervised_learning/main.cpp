#include "mainwindow.h"
#include "traitement.h"
#include <QApplication>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;


VideoCapture * webCam_;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Traitement * traitement = new Traitement();
    //traitement->getDirection();
    return a.exec();
}
