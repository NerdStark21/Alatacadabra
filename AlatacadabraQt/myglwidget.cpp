#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>






// Declarations des constantes
const unsigned int WIN_WIDTH  = 15;
const unsigned int WIN_HEIGHT = 6;
const float MAX_DIMENSION     = 15.0f;

MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Connexion du timer
    connect(&m_AnimationTimer_,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer_.setInterval(10);
    m_AnimationTimer_.start();


    move(QApplication::desktop()->screen()->rect().center()-rect().center());
    model_=new Model();
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);


    // Gestion des lumières
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat blanc[]={1,1,1};
    glLightfv(GL_LIGHT0,GL_AMBIENT,blanc);


    // Activation des textures
    glEnable(GL_TEXTURE_2D);
}



// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Système de coordonnées
    if(width != 0){
        //glOrtho(-MAX_DIMENSION, MAX_DIMENSION,-6.0,6.0,0.0,10.0);
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
        //glOrtho(0.0,30.0,0.0,30.0,-5.0,5.0);
    }

    glMatrixMode(GL_MODELVIEW);

    //Réinitialisation
    glLoadIdentity();

}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    //Couleur du fond et mise à jour du buffer
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Placement de la caméra
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,-1.0,0.0);

    //cout<<"on est dans paint"<<endl;

    // Mise à jour du jeu (affichage + déroulement de la partie)
    updateModel();

}


void MyGLWidget::updateModel(){

}


// Fonction de gestion d'interactions clavier (Ne fonctionne pas avec l'activation de la caméra)
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    cout<<"on entre dans key press event"<<endl;
    switch(event->key())
    {
    cout<<"on entre dans le switch key press event"<<endl;

    //Le Palet partira à gauche
    case Qt::Key_Left:
    {
        break;
    }

    //Le Palet partira à droite
    case Qt::Key_Right:
    {
        break;
    }

    // Activation/Arret de l'animation
    case Qt::Key_Space:
    {
        if(m_AnimationTimer_.isActive())
            m_AnimationTimer_.stop();
        else
            m_AnimationTimer_.start();

        break;
    }

    // Immobilisation du Palet
    case Qt::Key_Up:
    {
        break;
    }

    // Lancement de la balle
    case Qt::Key_Enter:
    {
        break;
    }

    // Cas par defaut
    default:
    {
        // Ignorer l'evenement
        event->ignore();
        return;
    }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
