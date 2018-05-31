#include "bayesien.h"

bayesien::bayesien(vector<float> muSkin, vector<float> sigmaSkin, vector<float> muBack, vector<float> sigmaBack)
{
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
