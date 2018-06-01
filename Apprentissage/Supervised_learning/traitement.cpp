#include "traitement.h"


Traitement::Traitement()
{
    Mat frame;

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

    //Initialisation
    for(;;)
    {
        if (webCam_.read(frame)) {
            cout<<"First frame captured !"<<endl;
            imshow("WebCam", frame);
            break;
        }
        else {
            cerr<<"Error capturing the first frame"<<endl;
            cerr<<"retrying..."<<endl;
            if(waitKey(30) >= 0) break;
        }
    }

}


Traitement::~Traitement()
{
    webCam_.release();
}


void Traitement::setDirection(int direction){
    direction_ = direction;
}

VideoCapture Traitement::getVideoCapture(){
    return webCam_;
}

/**
 * @brief Direction::getDirection
 * Cette méthode retourne la direction à prendre. Elle récupère l'image de la webcam,
 * réalise une classification bayésienne et détermine la position de la main
 * afin de connaître la direction. La direction vaut 0 pour indéterminé, 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas.
 * @return direction_
 */

int Traitement::getDirection(Mat frame){

    //Mat frame; //Image courante
    Mat frameYCbCr; // Image dans le domaine YCbCr
    Mat frameBlack; //Image binaire


    //Prendre une frame de la webCam
    //webCam_ >> frame;


    //Conversion en YCbCr
    cv::cvtColor(frame,frameYCbCr, COLOR_BGR2YCrCb);

    frameYCbCr.copyTo(frameBlack);

    //Segmentation

    bayesien *baye = new bayesien();

    //Segmentation

    frameBlack = Segmentation(baye, frameYCbCr);

    //Évaluation de la direction en fonction de l'image segmentée

    return direction_;
}


Mat Traitement::Segmentation(bayesien * baye, Mat frameYCbCr){

    Mat frameBlack; //Image binaire

    //On crée une copie de frameYCbCr;
    frameYCbCr.copyTo(frameBlack);

    //Images permettant de réaliser des traitements comme l'extraction d'un pixel.
    IplImage tempBlack = frameBlack;
    IplImage temp = frameYCbCr;

    //Pour chaque pixels de l'image, on réalise une classification bayésienne:
    int row = frameYCbCr.rows;
    int col = frameYCbCr.cols;

    for (int i = 0 ; i < row ; i++){

        for (int j = 0 ; j < col ; j++){

            //cout<<"Je suis dans le for"<<endl;


            //Récupération de la valeur du pixel
            CvScalar pix;


            pix = cvGet2D(&temp, i, j);

            vector<float> pixel;
            pixel.push_back(pix.val[0]);
            pixel.push_back(pix.val[1]);
            pixel.push_back(pix.val[2]);

            //Application de la règle bayésienne

            if (baye->regle_bayesienne(pixel)){

                //On récupère le pixel qu'on veut changer dans la matrice binaire
                pix = cvGet2D(&tempBlack, i, j);

                //On met le pixel en blanc
                pix.val[0] = 255;
                pix.val[1] = 255;
                pix.val[2] = 255;

                //On l'insère dans l'image en noir et blanc
                cvSet2D(&tempBlack,i,j,pix);
            }
            else{
                //On récupère le pixel qu'on veut changer dans la matrice binaire
                pix = cvGet2D(&tempBlack, i, j);

                //On met le pixel en noir

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
