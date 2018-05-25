#include "partie.h"

Partie::Partie(QWidget * parent): QGLWidget(parent)
{
    score_=0;
}

void Partie::initializeGL(){
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    glEnable(GL_DEPTH_TEST);    // Activation du zbuffer
}
