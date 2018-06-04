#include "traitement.h"


Traitement::Traitement()
{
    Mat frame;

    int frameWidth = 160;
    int frameHeight = 120;

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


    Mat frameYCbCr; // Image dans le domaine YCbCr
    Mat frameBlack; //Image binaire

    //Conversion en YCbCr
    cv::cvtColor(frame,frameYCbCr, COLOR_BGR2YCrCb);

    frameYCbCr.copyTo(frameBlack);

    //Segmentation

    bayesien *baye = new bayesien();

    cout << "On est avant segmentation"<<endl;

    frameBlack = Segmentation(baye, frameYCbCr);

    //Évaluation de la direction en fonction de l'image segmentée

    direction_ = 1;
    cout<<"Direction calculée : "<< 1 <<endl;

    return direction_;
}


Mat Traitement::Segmentation(bayesien * baye, Mat frameYCbCr){

    Mat frameBlack; //Image binaire

    // Itérator qui parcourira tous les pixels de l'image qui sont de type CvScalar
    MatIterator_<CvScalar> it;

    //On crée une copie de frameYCbCr qui deviendra une image binaire
    frameBlack = frameYCbCr.clone();

    //cout << "On est dans segmentation "<<endl;

    CvScalar pix;


    for (it = frameBlack.begin<CvScalar>(); it != frameBlack.end<CvScalar>(); it++){

        //cout<<"Je suis dans le for"<<endl;

        //Récupération de la valeur du pixel

        pix = *it;

        vector<float> pixel;
        pixel.push_back(pix.val[0]);
        pixel.push_back(pix.val[1]);
        pixel.push_back(pix.val[2]);


        //Application de la règle bayésienne

        //cout<<"Je suis dans segmentation"<<endl;

        if (baye->regle_bayesienne(pixel)){

            pix.val[0] = 1;
            pix.val[1] = 0;
            pix.val[2] = 0;

            *it = pix;

            cout<<"true"<<endl;

        }
        else{

            //On met le pixel en noir

            pix.val[0] = 0;
            pix.val[1] = 0;
            pix.val[2] = 0;

            //On l'insère dans l'image en noir et blanc
            *it = pix;

            cout<<"false"<<endl;
        }


        //cout<<"Valeur pixel YCbCr: "<<pix2.val[0]<<endl;
        //cout <<"Valeur pixel Black: "<<pix3.val[0]<<endl;
        cout<<"Valeur iterateur: "<<pix.val[0]<<endl;


    }

    return frameBlack;
}
