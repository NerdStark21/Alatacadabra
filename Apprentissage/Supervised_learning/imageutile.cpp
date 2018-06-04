#include "imageutile.h"

#include <vector>
#include <iostream>

using namespace std;

ImageUtile::ImageUtile()
{

}

vector<float> ImageUtile::RGBtoYCbCR(vector<float> pixel)
{
 float constante = 128.0;
 vector<float> pixel_YCbCr;
 //Y
 pixel_YCbCr.at(1) = (0.299 * pixel.at(1) + 0.587 * pixel.at(2) + 0.114 * pixel.at(3));
 //Cb
 pixel_YCbCr.at(2) = ((pixel.at(3) - pixel_YCbCr.at(1)) * 0.564 + constante);
 //Cr
 pixel_YCbCr.at(3) = ((pixel.at(1) - pixel_YCbCr.at(1)) * 0.713 + constante);

 return pixel_YCbCr;

}

Mat ImageUtile::MatToYCbCr(Mat M){
    Mat YcbCr;
   /*Transformation de la matrice en YCbCr
    MatIterator_ it;
    Point p = Point(0,0);
    cout<<M.at(&p)<<endl;
    for(it = M.begin(); it != M.end(); it++){


    }*/
    return M;


}
