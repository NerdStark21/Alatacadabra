#include "fruit.h"


Fruit::Fruit(Point position){
    quadrique_=gluNewQuadric();
    position_=position;
}

Fruit::~Fruit(){
    gluDeleteQuadric(quadrique_);
}



void Fruit::drawFruit(){
    // Affichage de la quadrique

    int R_,V_,B_;
    R_=100;
    V_=100;
    B_=100;
    glPushMatrix();
    glTranslated(position_.x,position_.y,0);


    // Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique

    gluSphere(quadrique_, radius_, 100.0, 100.0); //On dessine la quadrique
    glPopMatrix();

}
