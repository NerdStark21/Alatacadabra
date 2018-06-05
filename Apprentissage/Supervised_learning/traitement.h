#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <vector>
#include "bayesien.h"
#include "background.h"
#include "skin.h"
#include "mainwindow.h"

#include <QApplication>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core.hpp"

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;

class Traitement
{
public:
    Traitement();
    ~Traitement();
    void setDirection(int direction);
    int Direction(Mat frame);
    VideoCapture getVideoCapture();
    /**
     * @brief Segmentation
     * @param baye
     * Attribut bayésien permettant de calculer des probabilités
     * @param frame
     * Image à traiter
     * @return
     * Image segmentée en noir et blanc
     */
    Mat Segmentation(bayesien * baye, Mat frameYCbCr);
    int findDirection(Mat frameBlack);
    int getDirection();

private:

    VideoCapture webCam_;
    // Attribut permettant d'indiquer la direction à prendre. Il vaut 0 pour indéterminé, 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas
    int direction_;
};

#endif // TRAITEMENT_H
