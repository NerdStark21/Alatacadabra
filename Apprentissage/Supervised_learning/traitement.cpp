#include "direction.h"


Traitement::Traitement()
{
    int frameWidth = 320;
    int frameHeight = 240;
    direction_ = 0;

    //Ouvre la caméra par défault
    webCam_ = VideoCapture(0);

    //Changement de la taille max de la caméra
    webCam_.set(CV_CAP_PROP_FRAME_WIDTH, frameWidth);
    webCam_.set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);

     // Vérification de l'ouverture de la caméra
    if(!webCam_.isOpened())
    {
      cerr<<"Error openning the default camera" <<endl;

    }

}

void Traitement::setDirection(int direction){
    direction_ = direction;
}


/**
 * @brief Direction::getDirection
 * Cette méthode retourne la direction à prendre. Elle récupère l'image de la webcam,
 * réalise une classification bayésienne et détermine la position de la main
 * afin de connaître la direction. La direction vaut 0 pour indéterminé, 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas.
 * @return direction_
 */

int Traitement::getDirection(){

    Mat frame; //Image courante

    //Prendre une frame de la webCam
    webCam_ >> frame;

    //Effet mirroir
    cv::flip(frame, frame, 1);



    return direction_;
}

Traitement::~Traitement()
{
   webCam_.release();
}
