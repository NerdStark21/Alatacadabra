#include "snake.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

Snake::Snake(){

}


Snake::Snake(int width, int heigth)
{
    // Limits of the playground
    topLeft_ = Point(0,0);
    bottomRight_=  Point(width,heigth);

    // Create the snake with 1 bodypart
    body_.push_back(BodyPart( Point(floor(width/2),floor(heigth/2)),1));
    size_=1;
    direction_=Point(0,-1);
    radius_=0.5;

}


void Snake::move(){
    if(!deadlyPlace()){
        body_.back().setCenter(body_.front().getCenter()+direction_);
    }
}

// Add a body part at the end of the snake.
void Snake::eatFruit(){
    body_.push_back(BodyPart(body_.back().getCenter(),1));
}


bool Snake::deadlyPlace(){

    Point nextPosition=body_.front().getCenter()+direction_;
    Rect gameBoard= Rect(topLeft_,bottomRight_);
    if(nextPosition.inside(gameBoard)){
    return true;
    };
    return true;
}

void Snake::setDirection(Point p){
    direction_=p;
}

Vector<BodyPart> Snake::getBody(){
    return body_;
}
