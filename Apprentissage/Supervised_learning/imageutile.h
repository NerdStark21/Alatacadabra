#ifndef IMAGEUTILE_H
#define IMAGEUTILE_H

#include <vector>
using namespace std;

class ImageUtile
{
public:
    ImageUtile();
    static vector<float> RGBtoYCbCR(vector<float> pixel);
};

#endif // IMAGEUTILE_H
