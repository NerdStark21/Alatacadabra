#include "bodypart.h"

#include <QDebug>
#include <qdebug.h>

//BodyPart::BodyPart(Point center, int radius)
//    : center_(center), radius_(radius){}

BodyPart::BodyPart(Point center,bool head){
    center_=center;
    radius_=1.5;
    ball_quadric_= gluNewQuadric();
    head_=head;
}

void BodyPart::Display(QImage headImage){

//    qDebug()<<"Display de BodyPart"<<endl;


    int R_,V_,B_;
    R_=0;
    V_=100;
    B_=100;
    glPushMatrix();
    glTranslated(center_.x,center_.y,0);


    // Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    glColor3f(0.0, 1.0, 1.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique
    gluSphere(ball_quadric_, radius_, 50.0, 50.0);


    glPopMatrix();
}
