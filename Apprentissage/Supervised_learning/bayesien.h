#ifndef BAYESIEN_H
#define BAYESIEN_H

#include <vector>
#include "skin.h"
#include "background.h"

using namespace std;

/**
 * @brief The bayesien class
 * Cette classe permet de réaliser une classification bayésienne afin de distinguer la main du fond
 */

class bayesien
{
public:
    bayesien(vector<float> muSkin, vector<float> sigmaSkin, vector<float> muBack, vector<float> sigmaBack);

    /**
     * @brief probab_posteriori
     *  Calcule la probabilité a posteriori et met à jour les attributs
     */
    void proba_posteriori();

    /**
     * @brief proba_totale
     *  Calcule la probabilité totatle et met à jour les attributs
     */
    void proba_totale();

    /**
     * @brief regle_bayesienne
     * @param pixel
     * @return
     */
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
