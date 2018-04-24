#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <QDebug>


// Declarations des constantes
// 1600 - 900
const unsigned int WIN_WIDTH  = 1000;
const unsigned int WIN_HEIGHT = 600;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);   // Reglage de la couleur de fond
}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    width_ = width;
    height_ = height;

    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width),
                MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f,
                MAX_DIMENSION * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Vertices avec array
    glEnableClientState(GL_VERTEX_ARRAY); // Active le tableau permettant de définir les vertices
    GLfloat vertices[] = { 0, 0, 50, 0, 0, 50}; // triangle 1
    glVertexPointer(2, GL_FLOAT, 0, vertices); // 2 coordonnées pour chaque vertex
    glEnableClientState(GL_COLOR_ARRAY);
    //Générateur de couleur alétoire pour chaque vertice
    GLfloat colors[] = { rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX}; // triangle 1
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, 3*1); // Dessine 2 triangles ayant 3 vertices chacun
    glDisableClientState(GL_COLOR_ARRAY); // Désactive le tableau
    glDisableClientState(GL_VERTEX_ARRAY); // Désactive le tableau

    // Definition de la position de la camera
    // Caméra / Cible / Vecteur vertical
    glLoadIdentity();
    gluLookAt(-10, 0, 3, 0, 0, 0, 0, 0, 1);
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    // Activation/Arret de l'animation
    case Qt::Key_Space:
    {
        if(m_AnimationTimer.isActive())
            m_AnimationTimer.stop();
        else
            m_AnimationTimer.start();

        break;
    }
        // Sortie de l'application
    case Qt::Key_Escape:
    {
        exit(0);
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
