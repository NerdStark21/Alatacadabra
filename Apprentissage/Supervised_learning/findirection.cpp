/**
* @file Morphology_1.cpp
* @brief Erosion and Dilation sample code
* @author OpenCV team
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/world.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/utility.hpp"
#include <iostream>
#include <opencv2/core/core.hpp>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// cette fonction permet de créer une matrice de taille 3x3 composée de scalaires le type CV_64F correspond juste à des entiers codés sur 64 bits (à vérifier) mais permet d'utiliser .at . 
	Mat img(6, 6, CV_64F, Scalar(0));

	// la ligne suivante permet de modifier la matrice au point (0,0) çad en haut à gauche. 
	img.at<double>(1, 0) = 1;
	cout << img << endl;
	// la ligne suivante permet de récupérer le nombre de lignes de la matrice
	int r;
	r = img.rows;

	// la ligne suivante permet de récupérer le nombre de colonnes de la matrice
	int c;
	c = img.cols;


	// On définit les 4 directions. 
	int haut = 0;
	int gauche = 0;
	int droit = 0;
	int bas = 0;
	int i;
	int j;

	// For imbriqué pour parcourrir la matrice
	for (i = 0;i < r;i++)
	{
		for (j = 0; j < c;j++)
		{
			// On teste deux choses : si le point est dans la zone basse (c'est à dire si il est en dessous des deux diagonales) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici). 
			
			if ((i > r*j / c) && (i > -(r*j / c) + r) && (img.at<double>(i, j) == 1))
			{
				bas = bas + 1;
				cout << "haut " << " i " << i << " j " << j << endl;
			}
			// On teste deux choses : si le point est dans la zone droite(c'est à dire si il est en dessous de la diagonale montante et au dessus de la diagonale descendante) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).
			
			if ((i < r*j / c) && (i > -(r*j / c) + r) && (img.at<double>(i, j) == 1))
			{
				droit = droit + 1;
				cout << "gauche " << " i " << i << " j " << j << endl;
			}
			// On teste deux choses : si le point est dans la zone haute (c'est à dire si il est au dessus des deux diagonales) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).
			if ((i < r*j / c) && (i < -(r*j / c) + r) && (img.at<double>(i, j) == 1))
			{
				haut = haut + 1;
				cout << "bas " << " i " << i << " j " << j << endl;
			}
			// On teste deux choses : si le point est dans la zone gauche (c'est à dire si il est au dessus de la diagonale montante et en dessous de la diagonale descendante) et si il est égal à 1 (c'est à dire, il y a une partie de la main ici).
			if ((i > r*j / c) && (i < -(r*j / c) + r) && (img.at<double>(i, j) == 1))
			{
				gauche = gauche + 1;
				cout << "droit " << " i " << i << " j " << j << endl;
			}
		}
	}
	cout << "nb de pixels dans la zone haute " << haut << endl;
	cout << "nb de pixels dans la zone gauche " << gauche << endl;
	cout << "nb de pixels dans la zone basse " << bas << endl;
	cout << "nb de pixels dans la zone droite " << droit << endl;
	//cout << r << endl;
	return 0;
}