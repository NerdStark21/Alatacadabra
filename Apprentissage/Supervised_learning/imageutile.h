#ifndef IMAGEUTILE_H
#define IMAGEUTILE_H

#include <vector>

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;


class ImageUtile
{
public:
    ImageUtile();
    static vector<float> RGBtoYCbCR(vector<float> pixel);

    /**
     * @brief MatToYCbCr
     *  Cette fonction transforme une image de type Mat dont le codage des couleurs sont dans le domaine RGB
     *  en une matrice de type Mat dont le codage des couleurs
     *  sont dans le domaine YCbCr
     * @param M
     * Image Mat en RGB
     * @return
     * Image Mat en YCbCr
     */
    static Mat MatToYCbCr(Mat M);
};

#endif // IMAGEUTILE_H
