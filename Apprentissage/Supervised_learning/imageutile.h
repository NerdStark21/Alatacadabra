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

/**
 * @brief The ImageUtile class
 * Cette classe permettra de transformer une image RGB en une image YCbCr
 */

class ImageUtile
{
public:
    ImageUtile();

    /**
     * @brief RGBtoYCbCR
     *  Cette fonction passe un pixel de l'espace RGB à l'espace YCbCr.
     * @param pixel
     *  vecteur de 3 float entre 0 et 1 correspondant aux coordonnées RGB d'un pixel
     * @return
     *  vecteur de 3 float entre 0 et 1 correspondant aux coordonnées YCbCr d'un pixel
     */
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
