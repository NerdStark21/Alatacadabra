#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>

using namespace std;

class Texture
{

public:
    //Constructeur
    Texture(vector<float> mu, vector<float> sigma);

    //Calcul des probabiltés

    vector<float> probab_priori(float proba);
    vector<float> vraisemblance(vector<float> x);

    //Setters
    void setSigma(vector<float> sigma);
    void setMu(vector<float> mu);
    void setPosteriori(vector<float> p_w_x);

    //Getters
    vector<float> getSigma();
    vector<float> getMu();
    vector<float> getPosteriori();
    float getPriori();
    vector<float> getVraisemblance();

protected:
    //Moyenne YCbCr et écart-type
    vector<float> mu_;
    vector<float> sigma_;

    //Vraisemblance
    vector<float> p_x_w_;

    //Probabilté à priori
    float p_w_;

    //Probabilité à posteriori
    vector<float> p_w_x_;

};

#endif // TEXTURE_H
