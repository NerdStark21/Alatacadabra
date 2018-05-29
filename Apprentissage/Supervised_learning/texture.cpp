#include "texture.h"

#include <vector>
#include <math.h>

using namespace std;

Texture::Texture(vector<float> mu, vector<float> sigma)
{
    mu_ = mu;
    sigma_ = sigma;

}

//Calcul des probabiltés

vector<float> Texture::probab_priori(float proba)
{
    p_w_ = proba;
}
vector<float> Texture::vraisemblance(vector<float> x)
{
 // Y
 p_x_w_.at(1) = 1/sqrt(2*pow(sigma_.at(1),2) * M_PI) * exp(-0.5 * (pow((x.at(1) - mu_.at(1))/sigma_.at(1),2)));
 // Cb
 p_x_w_.at(2) = 1/sqrt(2*pow(sigma_.at(2),2) * M_PI) * exp(-0.5 * (pow((x.at(2) - mu_.at(2))/sigma_.at(2),2)));
 //Cr
 p_x_w_.at(3) = 1/sqrt(2*pow(sigma_.at(3),2) * M_PI) * exp(-0.5 * (pow((x.at(3) - mu_.at(3))/sigma_.at(3),2)));
}

//Setters
void Texture::setSigma(vector<float> sigma){
    sigma_  = sigma;
}

void Texture::setMu(vector<float> mu){
    mu_ = mu;
}


void Texture::setPosteriori(vector<float> p_w_x){
    p_w_x_ = p_w_x;
}

//Getters
vector<float> Texture::getSigma(){
    return sigma_;
}

vector<float> Texture::getMu(){
    return mu_;
}

vector<float> Texture::getPosteriori(){
    return p_w_x_;
}

float Texture::getPriori(){
    return p_w_;
}

vector<float> Texture::getVraisemblance()
{
 return p_x_w_;
}
