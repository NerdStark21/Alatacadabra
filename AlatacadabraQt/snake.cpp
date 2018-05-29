#include "snake.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

Snake::Snake(int width, int heigth)
{
    // Limits of the playground
    topLeft_ = Point(0,0);
    bottomRight_=  Point(width,heigth);

    // Create the snake with 1 bodypart
    body_.push_back(BodyPart( Point(width/2,heigth/2),1));
    size_=1;
    direction_=Point(0,-1);
    radius_=0.5;

}


void Snake::move(){
    if(!deadlyPLace()){
        body_[body_.end()].setCenter(body_[body_.begin()].getCenter()+direction_);
    }
}

// Add a body part at the end of the snake.
void Snake::eatFruit(){
    body_.push_back(new BodyPart(body_[end].getCenter());
}


bool Snake::deadlyPLace(){

    Point nextPosition=body_[begin]+direction_;
    Rect gameBoard=new Rect(topLeft_,bottomRight_);
    if(nextPosition.inside(gameBoard)){

    };
}

void Snake::setDirection(Point p){
    direction_=p;
}

Vector<BodyPart> Snake::getBody(){
    return body_;
}
