#include "snake.h"

Snake::Snake()
{



}


void Snake::move(){
    if(!deadlyPLace()){
        body_[end].setCenter(body_[begin].getCenter()+direction_);
    }
}

void Snake::eatFruit(){
    body_.push_back(new BodyPart);
}


bool Snake::deadlyPLace(){
    Point topLeft= new Point(10,10);
    Point bottomRight= new Point(0,0);
    Point nextPosition=body_[begin]+direction_;
    Rect gameBoard=new Rect(topLeft,bottomRight);
    if(nextPosition.inside());
}

void Snake::setDirection(Point p){
    direction_=p;
}
