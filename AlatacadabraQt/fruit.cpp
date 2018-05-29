#include "fruit.h"

fruit::fruit()
{

}


void Fruit::setPosition(Point p){
    position_=p;
}

Point Fruit::getPosition(){
    return position_;
}
