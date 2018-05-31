#include "bodypart.h"

//BodyPart::BodyPart(Point center, int radius)
//    : center_(center), radius_(radius){}

BodyPart::BodyPart(){
}

BodyPart::BodyPart(Point center, int radius){
    center_=center;
    radius_=radius;
}

void drawBodyPart(){

}


Point BodyPart::getCenter(){
    return center_;
}

void BodyPart::setCenter(Point p){
    center_=p;
}
