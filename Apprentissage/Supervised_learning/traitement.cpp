#include "traitement.h"


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


Traitement::~Traitement()
{
    webCam_.release();
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
    Mat frameYCbCr; // Image dans le domaine YCbCr
    Mat frameBlack; //Image binaire


    //Prendre une frame de la webCam
    webCam_ >> frame;

    //Effet mirroir
    cv::flip(frame, frame, 1);

    //Conversion en YCbCr
    cv::cvtColor(frame,frameYCbCr, COLOR_BGR2YCrCb);

    //Segmentation

    bayesien *baye = new bayesien();

    //Segmentation

    frameBlack = Segmentation(baye, frameYCbCr);

    //Évaluation de la direction en fonction de l'image segmentée

    return direction_;
}


Mat Traitement::Segmentation(bayesien * baye, Mat frameYCbCr){

    Mat frameBlack; //Image binaire

    IplImage tempBlack = frameBlack;
    IplImage temp = frameYCbCr;

    //Pour chaque pixels de l'image, on réalise une classification bayésienne:
    int row = frameYCbCr.rows;
    int col = frameYCbCr.cols;

    for (int i = 0 ; i < row ; i++){

        for (int j = 0 ; j < col ; j++){

            //Classification bayésienne
            CvScalar pix;

            pix = cvGet2D(&temp, i, j);
            vector<float> pixel;
            pixel.at(0) = pix.val[0];
            pixel.at(1) = pix.val[1];
            pixel.at(2) = pix.val[2];

            //Application de la règle bayésienne

            if (baye->regle_bayesienne(pixel)){

                pix = cvGet2D(&tempBlack, i, j);
                //On met le pixel en blanc
                pix.val[0] = 255;
                pix.val[1] = 255;
                pix.val[2] = 255;

                //On l'insère dans l'image en noir et blanc
                cvSet2D(&tempBlack,i,j,pix);
            }
            else{
                pix = cvGet2D(&tempBlack, i, j);

                //On met le pixel en blanc

                pix.val[0] = 0;
                pix.val[1] = 0;
                pix.val[2] = 0;

                //On l'insère dans l'image en noir et blanc

                cvSet2D(&tempBlack,i,j,pix);

            }

        }
    }

    return frameBlack;
}
