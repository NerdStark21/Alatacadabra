#ifndef IMAGEANALYZING_H
#define IMAGEANALYZING_H


class ImageAnalyzing
{
public:
    ImageAnalyzing();
    QImage getImage();
private:
    VideoCapture cam_;
};

#endif // IMAGEANALYZING_H
