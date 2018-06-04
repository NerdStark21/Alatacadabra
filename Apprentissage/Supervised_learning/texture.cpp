#include "texture.h"

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

Texture::Texture(vector<float> mu, vector<float> sigma)
{
    mu_ = mu;
    sigma_ = sigma;

}

//Calcul des probabiltés

void Texture::proba_priori(float proba)
{
    p_w_ = proba;
}
void Texture::vraisemblance(vector<float> pixel)
{

    // Y
    float Y = 1/sqrt(2*pow(sigma_.at(0),2) * M_PI) * exp(-0.5 * (pow((pixel.at(0) - mu_.at(0))/sigma_.at(0),2)));

    // Cb
    float Cb = 1/sqrt(2*pow(sigma_.at(1),2) * M_PI) * exp(-0.5 * (pow((pixel.at(1) - mu_.at(1))/sigma_.at(1),2)));

    //Cr
    float Cr = 1/sqrt(2*pow(sigma_.at(2),2) * M_PI) * exp(-0.5 * (pow((pixel.at(2) - mu_.at(2))/sigma_.at(2),2)));


    p_x_w_.push_back(Y);
    p_x_w_.push_back(Cb);
    p_x_w_.push_back(Cr);
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
