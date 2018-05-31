#ifndef SKIN_H
#define SKIN_H

#include <vector>
#include "texture.h"
using namespace std;

/**
 * @brief The Skin class
 * Cette classe représentera la classe de la peau. Elle hérite de la classe texture.h
 */

class Skin : public Texture
{
public:
    //Constructeur
    Skin(vector<float> mu, vector<float> sigma);


};

#endif // SKIN_H
