#include "snake.h"

Snake::Snake()
{
    // Limits of the playground
    topLeft_=new Point(0,0);
    bottomRight_= new Point(50,50);

    // Create the snake with 1 bodypart
    body_.push_back(new BodyPart(new Point(0,0)));
    size_=1;
    direction_=new Point(0,-1);
    radius_=0.5;

}


void Snake::move(){
    if(!deadlyPLace()){
        body_[end].setCenter(body_[begin].getCenter()+direction_);
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
