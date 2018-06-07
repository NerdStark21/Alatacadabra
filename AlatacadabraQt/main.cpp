#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Initialisation du temps pour avoir des valeurs aléatoires.
    srand (time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Traitement * traitement = new Traitement();

    // Lancement de la vidéo
    Mat frame, frameCopy;
    int i = 0;
    //Model *model = w.getModel();
    while (waitKey(5)<0)
    {

        //Prendre une frame de la webcam
        traitement->getVideoCapture() >> frame;

        //Effet mirroir
        cv::flip(frame, frame, 1);

        //copie de la frame pour la traiter en parallèle
        frameCopy  = frame.clone();
        int direction = 0;

        if (i%2 == 0){
            cout<<"On est avant traitement"<<endl;
            direction = traitement->Direction(frameCopy);
             w.getModel()->intToDirection(direction);
        }
        i++;

        // affichage de la frame suivante
        imshow("WebCam", frame);

    }



    return a.exec();
}
