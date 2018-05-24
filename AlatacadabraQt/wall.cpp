#include "wall.h"

using namespace cv;
using namespace std;

Wall::Wall(Rect stuff)
    : stuff_(stuff){
    depth_ = 5;
}

void Wall::drawWall(){
    glPushMatrix();
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);

    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);

    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);

    glVertex3f(stuff_.x,stuff_.y + stuff_.height, 0);
    glVertex3f(stuff_.x,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y + stuff_.height, 0);

    glVertex3f(stuff_.x,stuff_.y, 0);
    glVertex3f(stuff_.x,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, depth_);
    glVertex3f(stuff_.x + stuff_.width,stuff_.y, 0);

    glEnd();
    glPopMatrix();
}
