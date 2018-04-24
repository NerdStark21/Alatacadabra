#include "imageanalyzing.h"

ImageAnalyzing::ImageAnalyzing()
{
    cam_=new VideoCapture(0);
}


ImageAnalyzing::getImage(){
    Mat image;
    cam_->read(image);
    flip(image,image,1);
    cvtColor(image,image,CV_BGR2RGB);
    QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    return img;
}


