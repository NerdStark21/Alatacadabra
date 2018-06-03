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

    muBack.push_back(126);
    muBack.push_back(123);
    muBack.push_back(135);

    sigmaBack.push_back(54.4);
    sigmaBack.push_back(8.9);
    sigmaBack.push_back(13.3);

    muSkin.push_back(180);
    muSkin.push_back(109);
    muSkin.push_back(154);

    sigmaSkin.push_back(14);
    sigmaSkin.push_back(4.3);
    sigmaSkin.push_back(7);

    skin_ = new Skin(muSkin,sigmaSkin);
    background_ = new Background(muBack, sigmaBack);
}

void bayesien::proba_posteriori()
{

    //Pour la peau

    vector<float> p_w_x_skin;
    float val1,val2,val3;

    val1 = (skin_->getVraisemblance().at(0) * skin_->getPriori())/proba_totale_.at(0);
    val2 = (skin_->getVraisemblance().at(1) * skin_->getPriori())/proba_totale_.at(1);
    val3 = (skin_->getVraisemblance().at(2) * skin_->getPriori())/proba_totale_.at(2);

    p_w_x_skin.push_back(val1);
    p_w_x_skin.push_back(val2);
    p_w_x_skin.push_back(val3);

    skin_->setPosteriori(p_w_x_skin);

    //Pour le fond

    vector<float> p_w_x_back;
    float val4,val5,val6;

    val4 = (background_->getVraisemblance().at(0) * background_->getPriori())/proba_totale_.at(0);
    val5 = (background_->getVraisemblance().at(1) * background_->getPriori())/proba_totale_.at(1);
    val6 = (background_->getVraisemblance().at(2) * background_->getPriori())/proba_totale_.at(2);

    p_w_x_back.push_back(val4);
    p_w_x_back.push_back(val5);
    p_w_x_back.push_back(val6);

    background_->setPosteriori(p_w_x_back);
}

void bayesien::proba_totale(){
    float val1,val2,val3;

    val1 = skin_->getVraisemblance().at(0) * skin_->getPriori() + background_->getVraisemblance().at(0) * background_->getPriori();
    val2 = skin_->getVraisemblance().at(1) * skin_->getPriori() + background_->getVraisemblance().at(1) * background_->getPriori();
    val3 = skin_->getVraisemblance().at(2) * skin_->getPriori() + background_->getVraisemblance().at(2) * background_->getPriori();

    proba_totale_.push_back(val1);
    proba_totale_.push_back(val2);
    proba_totale_.push_back(val3);

}

vector<float> bayesien::getProbaTotale(){
    return proba_totale_;
}

bool bayesien::regle_bayesienne(vector<float> pixel)
{
    skin_->proba_priori(1/5);
    background_->proba_priori(4/5);
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

