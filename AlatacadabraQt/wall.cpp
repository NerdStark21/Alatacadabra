#include "wall.h"

using namespace cv;
using namespace std;

Wall::Wall(Rect rectangle)
    : rectangle_(rectangle){
    depth_ = 5;
}

void Wall::drawWall(){
    glPushMatrix();
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);

    glVertex3f(rectangle_.x,rectangle_.y, 0);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, 0);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, 0);
    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, 0);

    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, 0);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, 0);

    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, depth_);
    glVertex3f(rectangle_.x,rectangle_.y, depth_);
    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, depth_);

    glVertex3f(rectangle_.x,rectangle_.y, depth_);
    glVertex3f(rectangle_.x,rectangle_.y, 0);
    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, 0);
    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, depth_);

    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, 0);
    glVertex3f(rectangle_.x,rectangle_.y + rectangle_.height, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y + rectangle_.height, 0);

    glVertex3f(rectangle_.x,rectangle_.y, 0);
    glVertex3f(rectangle_.x,rectangle_.y, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, depth_);
    glVertex3f(rectangle_.x + rectangle_.width,rectangle_.y, 0);

    glEnd();
    glPopMatrix();
}
