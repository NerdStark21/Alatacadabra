#include "snake.h"

#include <QDebug>
#include <qdebug.h>

#include "opencv2/core/version.hpp"
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>

using namespace cv;


Snake::Snake(int width, int heigth)
{
    // Limits of the playground
    topLeft_ = Point(0,0);
    bottomRight_=  Point(width,heigth);

    // Create the snake with 1 bodypart
    body_.push_back(BodyPart( Point(floor(width/2),floor(heigth/2)),1));
    body_.push_back(BodyPart( Point(floor(width/2),floor(heigth/2)-1),1));
    body_.push_back(BodyPart( Point(floor(width/2),floor(heigth/2)-2),1));

    size_=1;
    direction_=Point(0,1);
    radius_=0.5;

}

void Snake::Display(){
    for(BodyPart b : body_){
        b.Display();
    }
}


void Snake::move(){
    if(true/*!deadlyPlace()*/){
        qDebug()<<"Position de Snake : "<<"["<<body_.front().getCenter().x<<" ; "<< body_.front().getCenter().y<<"]";
//        qDebug()<<"  ["<<body_.
        BodyPart newPart = BodyPart(body_.front().getCenter()+direction_,radius_);
        body_.push_front(newPart);
        body_.pop_back();
        qDebug()<<body_.size()<<endl;

        //body_.back().setCenter(body_.front().getCenter()+direction_);

    }
    else{
        dead_=true;
    }
}

// Add a body part at the end of the snake.
void Snake::eatFruit(){
    body_.push_back(BodyPart(body_.back().getCenter(),1));
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
