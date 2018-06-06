#include "snake.h"

#include <QDebug>
#include <qdebug.h>

#include "opencv2/core/version.hpp"
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>

#include <QGLWidget>

using namespace cv;

/**
 * @brief Snake::Snake
 * @param width
 * @param heigth
 *
 * The snake starts the game with 3 bodyparts [0,0],[0,-1],[0,-2], and can only acces the even positions.
 */

Snake::Snake(int width, int heigth, QString HeadImage)
{
    // Limits of the playground
    topLeft_ = Point(0,0);
    bottomRight_=  Point(width,heigth);
    headImage_ = HeadImage;
    size_=1;
    direction_=Point(0,1);
    radius_=1;

    // Create the snake with 3 bodyparts
    body_.push_back(BodyPart( Point(0,0),true, headImage_));
    body_.push_back(BodyPart( Point(0,-1),false, headImage_));
    body_.push_back(BodyPart( Point(0,-2),false, headImage_));

    // Gestion des textures
    //    headImage_=QGLWidget::convertToGLFormat(QImage("../../faces/Olivier_Alata.jpg"));
    //    glGenTextures(1,GLuint* textures); // Tableau dans lequel on va stocker les textures générées
    //    // On définit la texture courante
    //    glBindTexture(GL_TEXTURE_2D,GLuint* texture);  // entier correspondant à la texture courante

    //    glTexImage2D(
    //    GL_TEXTURE_2D, // GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, …
    //    0, // niveau de détail de l’image, avec 0 on a l’image de base
    //    3, // nombre de composantes de couleurs par pixel (3 si RGB, 4 si RGBA, …)
    //    512, 512, // largeur de la texture (puissance de 2) et hauteur de la texture (puissance de 2)
    //    0, // toujours 0 d’apres les spécif
    //    GL_RGB, // format de stockage (GL_RGB, GL_RGBA, …)
    //    GL_UNSIGNED_BYTE, // type dans lequel sont stockées les composantes(GL_UNSIGNED_BYTE, GL_BYTE, GL_INT, …)
    //    GLvoid* data);  // adresse de la texture


    //    // On définit les paramètres de la texture courante
    //    glTexParameteri(
    //    GL_TEXTURE_2D, // GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, …
    //    GL_TEXTURE_MIN_FILTER, // paramètre auquel on va venir setter une valeur (GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER, …)
    //    25); // valeur à setter




}

void Snake::Display(){
    qDebug()<<"Snake : ["<< body_.front().getCenter().x<<" , "<< body_.front().getCenter().y<<endl;
    for(BodyPart b : body_){
        //qDebug()<<"Snake : ["<< body_.front().getCenter().x<<" , "<< body_.front().getCenter().y<<endl;
        b.Display(headImage_);
    }
}


void Snake::move(){
    if(true/*!deadlyPlace()*/){

        body_.front().setHead(false);
        BodyPart newPart = BodyPart(body_.front().getCenter()+direction_*2*radius_,true, headImage_);
        body_.push_front(newPart);
        if(!fruitEaten_){
            body_.pop_back();
        }else{
            fruitEaten_=false;
        }

        //body_.back().setCenter(body_.front().getCenter()+direction_);

    }
    else{
        dead_=true;
    }
}

// Add a body part at the end of the snake.
void Snake::eatFruit(){

    body_.push_back(BodyPart(body_.back().getCenter(),false, headImage_));
    fruitEaten_=true;
    //    body_.push_back(BodyPart(body_.back().getCenter(),false));

}

// Returns a boolean : true if the snake shall die, false if not.
bool Snake::deadlyPlace(){

    // Point where the head of the snake will move next tick.
    Point nextPosition=body_.front().getCenter()+direction_;
    // A rect that shows the limits of the board.
    Rect gameBoard= Rect(topLeft_,bottomRight_);


    if(!nextPosition.inside(gameBoard)){
        return true;
    }
    else{
        for(BodyPart b:body_){
            if(b.getCenter()==nextPosition){
                return true;
            }
        }
    }
    return false;
}

void Snake::setDirection(Point p){
    if(p!=-1*direction_){
        direction_=p;
    }
}

QString Snake::getPath(){
    return headImage_;
}

bool Snake::getFruitEaten(){
    return fruitEaten_;
}

void Snake::setFruitEaten(bool fruit){
    fruitEaten_=fruit;

}
