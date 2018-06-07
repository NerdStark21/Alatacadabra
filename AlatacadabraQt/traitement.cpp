#include "traitement.h"


Traitement::Traitement()
{
    Mat frame;

    int frameWidth = 16;
    int frameHeight = 12;

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

int Traitement::Direction(Mat frame){


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

    direction_ = findDirection(frameBlack);
    cout<<"Direction calculée : "<< this->getDirection() <<endl;

    return direction_;
}


Mat Traitement::Segmentation(bayesien * baye, Mat frameYCbCr){


    //Pour chaque pixels de l'image, on réalise une classification bayésienne:
    int row = frameYCbCr.rows;
    int col = frameYCbCr.cols;

    Mat frameBlack(row,col, CV_64F, Scalar(0)); //Image binaire

    //cout << "On est dans segmentation "<<endl;

    //Images permettant de réaliser des traitements comme l'extraction d'un pixel.
    IplImage tempYCbCr = frameYCbCr;

    CvScalar pix;

    for (int i = 0 ; i < row ; i++){

        for (int j = 0 ; j < col ; j++){

            //cout<<"Je suis dans le for"<<endl;

            //Récupération de la valeur du pixel

            pix = cvGet2D(&tempYCbCr, i , j);

            vector<float> pixel;
            pixel.push_back(pix.val[0]);
            pixel.push_back(pix.val[1]);
            pixel.push_back(pix.val[2]);


            //Application de la règle bayésienne

            if (baye->regle_bayesienne(pixel)){

                frameBlack.at<double>(i,j) = 1;

            }

        }
    }
    return frameBlack;
}

int Traitement::findDirection(Mat frameBlack){
    // la ligne suivante permet de récupérer le nombre de lignes de la matrice
    int r;
    r = frameBlack.rows;

    // la ligne suivante permet de récupérer le nombre de colonnes de la matrice
    int c;
    c = frameBlack.cols;


    // On définit les 4 directions.
    int haut = 0;
    int gauche = 0;
    int droite = 0;
    int bas = 0;
    int i;
    int j;

    // For imbriqué pour parcourrir la matrice
    for (i = 0;i < r;i++)
    {
        for (j = 0; j < c;j++)
        {
            // On teste deux choses : si le point est dans la zone basse (c'est à dire si il est en dessous des deux diagonales) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).

            if ((i > r*j / c) && (i > -(r*j / c) + r) && (frameBlack.at<double>(i, j) == 1))
            {
                bas++;
            }
            // On teste deux choses : si le point est dans la zone droite(c'est à dire si il est en dessous de la diagonale montante et au dessus de la diagonale descendante) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).

            if ((i < r*j / c) && (i > -(r*j / c) + r) && (frameBlack.at<double>(i, j) == 1))
            {
                droite++;
            }
            // On teste deux choses : si le point est dans la zone haute (c'est à dire si il est au dessus des deux diagonales) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).
            if ((i < r*j / c) && (i < -(r*j / c) + r) && (frameBlack.at<double>(i, j) == 1))
            {
                haut++;
            }
            // On teste deux choses : si le point est dans la zone gauche (c'est à dire si il est au dessus de la diagonale montante et en dessous de la diagonale descendante) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).
            if ((i > r*j / c) && (i < -(r*j / c) + r) && (frameBlack.at<double>(i, j) == 1))
            {
                gauche++;
            }
        }
    }

    //Recherche de la direction en prenant le maximum entre les différentes directions
    int tab[4] = {gauche, haut, droite, bas};

    int min = tab[0];
    int max = tab[0];
    direction_ = 1;

    for(int i = 1; i < 4; i++){
        if (tab[i]>max){
            direction_ = i+1;
            max = tab[i];
        }
        if (tab[i] < min) {
            min = tab[i];
        }
    }

    if (max < r * c / 20 || max - min < r * c / 10) {
        return 0;
    }

    return direction_;
}

int Traitement::getDirection(){
    return direction_;
}
