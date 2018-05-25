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

}
