#ifndef SKIN_H
#define SKIN_H

#include <vector>
#include "texture.h"
using namespace std;


class Skin : public Texture
{
public:
    //Constructeur
    Skin(vector<float> mu, vector<float> sigma);


};

#endif // SKIN_H
