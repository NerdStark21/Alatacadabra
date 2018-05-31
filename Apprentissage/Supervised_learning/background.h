#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"
using namespace std;

/**
 * @brief The Background class
 * Cette classe représentera la classe du fond. Elle hérite de la classe texture.h
 */

class Background : public Texture
{
public:
    //Constructeur
    Background(vector<float> mu, vector<float> sigma);

};

#endif // BACKGROUND_H
