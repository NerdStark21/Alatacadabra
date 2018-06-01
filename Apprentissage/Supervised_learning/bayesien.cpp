#include "bayesien.h"


bayesien::bayesien()
{
    //Moyenne de la classe peau
    vector<float> muSkin;

    //Écart-type de la classe peau
    vector<float> sigmaSkin;

    //Moyenne de la classe fond
    vector<float> muBack;

    //Écart-type de la classe fond
    vector<float> sigmaBack;

    muBack.push_back(96.25);
    muBack.push_back(120.56);
    muBack.push_back(137.53);

    sigmaBack.push_back(60.94);
    sigmaBack.push_back(8.94);
    sigmaBack.push_back(13.15);

    muSkin.push_back(1);
    muSkin.push_back(1);
    muSkin.push_back(1);

    sigmaSkin.push_back(1);
    sigmaSkin.push_back(1);
    sigmaSkin.push_back(1);

    skin_ = new Skin(muSkin,sigmaSkin);
    background_ = new Background(muBack, sigmaBack);
}

void bayesien::proba_posteriori()
{

//Pour la peau
vector<float> p_w_x_skin;
 p_w_x_skin.at(1) = (skin_->getVraisemblance().at(1) * skin_->getPriori())/proba_totale_.at(1);
 p_w_x_skin.at(2) = (skin_->getVraisemblance().at(2) * skin_->getPriori())/proba_totale_.at(2);
 p_w_x_skin.at(3) = (skin_->getVraisemblance().at(3) * skin_->getPriori())/proba_totale_.at(3);
 skin_->setPosteriori(p_w_x_skin);

 //Pour le fond
 vector<float> p_w_x_back;
  p_w_x_back.at(1) = (background_->getVraisemblance().at(1) * background_->getPriori())/proba_totale_.at(1);
  p_w_x_back.at(2) = (background_->getVraisemblance().at(2) * background_->getPriori())/proba_totale_.at(2);
  p_w_x_back.at(3) = (background_->getVraisemblance().at(3) * background_->getPriori())/proba_totale_.at(3);
  background_->setPosteriori(p_w_x_skin);
}

void bayesien::proba_totale(){

    proba_totale_.at(1) = skin_->getVraisemblance().at(1) * skin_->getPriori() + background_->getVraisemblance().at(1) * background_->getPriori();
    proba_totale_.at(2) = skin_->getVraisemblance().at(2) * skin_->getPriori() + background_->getVraisemblance().at(2) * background_->getPriori();
    proba_totale_.at(3) = skin_->getVraisemblance().at(3) * skin_->getPriori() + background_->getVraisemblance().at(3) * background_->getPriori();

}

vector<float> bayesien::getProbaTotale(){
    return proba_totale_;
}

bool bayesien::regle_bayesienne(vector<float> pixel)
{
    skin_->probab_priori(1/5);
    background_->probab_priori(4/5);
    skin_->vraisemblance(pixel);
    background_->vraisemblance(pixel);
    proba_totale();
    proba_posteriori();
    if(skin_->getPosteriori()>background_->getPosteriori())
    {
        return true;
    }
    return false;
}

