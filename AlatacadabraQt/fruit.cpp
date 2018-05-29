#include "fruit.h"

Fruit::Fruit()
{

}


void Fruit::setPosition(Point p){
    position_=p;
}

Point Fruit::getPosition(){
    return position_;
}
