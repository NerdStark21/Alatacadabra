#include "fruit.h"

Fruit::Fruit()
{

}


Fruit::Fruit(Point position)
{
    position_=position;
}


void Fruit::setPosition(Point p){
    position_=p;
}

Point Fruit::getPosition(){
    return position_;
}
