#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>

using namespace std;

/**
 * @brief The Texture class
 * Classe contenant les différentes probabiltés nécessaires au calcul à la classification bayésienne. Deux classes hériteront de celle-ci:
 * Skin et Background.
 */

class Texture
{

public:
    //Constructeur
    Texture(vector<float> mu, vector<float> sigma);

    //Calcul des probabiltés

    void proba_priori(float proba);
    void vraisemblance(vector<float> pixel);

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
