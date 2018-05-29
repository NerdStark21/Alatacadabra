#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"
using namespace std;

class Background : public Texture
{
public:
    //Constructeur
    Background(vector<float> mu, vector<float> sigma);

};

#endif // BACKGROUND_H
