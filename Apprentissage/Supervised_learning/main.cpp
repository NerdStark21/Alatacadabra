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

    // Lancement de la vidéo
    Mat frame, frameCopy;
    int i = 0;
    while (waitKey(5)<0)
    {

        //Prendre une frame de la webcam
        traitement->getVideoCapture() >> frame;

        //Effet mirroir
        cv::flip(frame, frame, 1);

        //copie de la frame pour la traiter en parallèle
        frameCopy  = frame.clone();
        int direction = 0;


        if (i== 1){
            cout<<"En cours de traitement, ça prend environ 2 min..."<<endl;
            direction = traitement->getDirection(frameCopy);
            cout<<"Diretion = "<<direction<<endl;

        }
        i+=1;


        // affichage de la frame suivante
        imshow("WebCam", frame);

    }

    return a.exec();
}
