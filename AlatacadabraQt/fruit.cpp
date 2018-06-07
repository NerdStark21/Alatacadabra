#include "fruit.h"
#include <qdebug.h>


Fruit::Fruit(Point position, QString path, int randomImg){
    quadrique_=gluNewQuadric();
    position_=position;
    path_ = path;
    randomImg_ = randomImg;
}

Fruit::~Fruit(){
//    qDebug()<<"destruction de la quadrique"<<endl;
    gluDeleteQuadric(quadrique_);
}



void Fruit::drawFruit(){
    // Affichage de la quadrique
//    qDebug()<<"Affichage du fruit"<<endl;
    int R_,V_,B_;
    R_=100;
    V_=100;
    B_=100;
    glPushMatrix();
//    qDebug()<<position_.x<<"   "<<position_.y<<endl;
    glTranslated(position_.x,position_.y,0);

    glRotated(40,0,1,0);
    glRotated(-45,0,0,1);
    glRotated(-65,1,0,0);

    // Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glColor3f(0.5, 0.5, 0.5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique

    gluQuadricTexture(quadrique_,GL_TRUE);
    gluSphere(quadrique_, radius_, 100.0, 100.0); //On dessine la quadrique
    glPopMatrix();

}

QString Fruit::getPath(){
    return path_;
}

int Fruit::getRandomImg(){
    return randomImg_;
}
