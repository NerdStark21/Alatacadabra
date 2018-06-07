#include "bodypart.h"

#include <QDebug>
#include <qdebug.h>

//BodyPart::BodyPart(Point center, int radius)
//    : center_(center), radius_(radius){}

BodyPart::BodyPart(Point center, bool head, QString headImage){
    center_=center;
    radius_=1.5;
    ball_quadric_= gluNewQuadric();
    head_= head;
    headImage_ = headImage;
}

void BodyPart::Display(QString headImage){

    //    qDebug()<<"Display de BodyPart"<<endl;

    int R_,V_,B_;
    if(!head_){
        R_=0;
        V_=100;
        B_=100;
    }
    else{
        R_=100;
        V_=100;
        B_=100;
    }
    glPushMatrix();
    glTranslated(center_.x,center_.y,0);
    glRotated(40,0,1,0);
    glRotated(-45,0,0,1);
    glRotated(-65,1,0,0);
    // Couleur de l'objet
    GLfloat colorAmbiante[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    GLfloat colorDiffuse[] = {GLfloat(R_)/255, GLfloat(V_)/255, GLfloat(B_)/255, 1.0f};
    //GLfloat colorSpeculaire_planet[] = {0.5f, 0.5f, 0.5f, 1.0f};

    if(!head_){
        glColor3f(0.0, 1.0, 1.0);
    }
    else{
        glColor3f(0.5,0.5,0.5);
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpeculaire_planet);


    // Affichage de la quadrique

    //Si c'est la tête, affichage de la texture
    if (head_)
    {
        gluQuadricTexture(ball_quadric_,GL_TRUE);
    }
    else{
        gluQuadricTexture(ball_quadric_,GL_FALSE);
    }

    gluSphere(ball_quadric_, radius_, 100.0, 100.0);
    glPopMatrix();
}


bool BodyPart::getHead(){
    return head_;
}
void BodyPart::setHead(bool head){
    head_ = head;
}
