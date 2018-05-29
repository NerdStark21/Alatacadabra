#ifndef BAYESIEN_H
#define BAYESIEN_H

#include <vector>
#include "skin.h"
#include "background.h"

using namespace std;

class bayesien
{
public:
    bayesien(vector<float> muSkin, vector<float> sigmaSkin, vector<float> muBack, vector<float> sigmaBack);
    void probab_posteriori();
    void proba_totale();
    bool regle_bayesienne(vector<float> pixel);
    vector<float> getProbaTotale();

private:

    Background * background_;
    Skin * skin_;

    vector<float> proba_totale_;

    //Probabilité à posteriori
    vector<float> p_w_x_;

};

#endif // BAYESIEN_H
