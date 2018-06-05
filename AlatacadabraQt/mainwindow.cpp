#define _USE_MATH_DEFINES

#include "mainwindow.h"

using namespace cv;

const unsigned int WIN_WIDTH  = 10;
const unsigned int WIN_HEIGHT = 10;
const float MAX_DIMENSION     = 30.0f;

/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->initializeGL();
}
*/

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent)
{
    // Reglage de la taille/position
    //setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());


    // Connexion du timer
    connect(&m_AnimationTimer_,  &QTimer::timeout, [&] {
        this->update();
        updateGL();
    });

    m_AnimationTimer_.setInterval(100);
    m_AnimationTimer_.start();

    // Création du modèle
    int dimension=MAX_DIMENSION;
    model_ = new Model(dimension);
}

void MainWindow::update(){
    model_->update();
}


MainWindow::~MainWindow(){
}


// Fonction d'initialisation
void MainWindow::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(15, 15, 15, 1);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    //Réglage de la lumière

    GLfloat color_ambient_light[] = {0.3f, 0.3f, 0.3f, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, color_ambient_light);

    GLfloat color_diffuse_light[] = {0.8f, 0.8f, 0.8f, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color_diffuse_light);

    // Activation de la lumiere
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}


// Fonction de redimensionnement
void MainWindow::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Système de coordonnées
    if(width != 0){
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
    }

    glMatrixMode(GL_MODELVIEW);

    //Réinitialisation
    glLoadIdentity();
}


// Fonction d'affichage
void MainWindow::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Caméra / Cible / Vecteur vertical
    gluLookAt(0.0,0.0,10.0,
              0.0,0.0,0.0,
              0.0,1.0,0.0);

    // On va dessiner tous les murs
    model_->Display();
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    //cout<<"on entre dans key press event"<<endl;
    switch(event->key())
    {

    case Qt::Key_Left:
    {
        //cout<<"Left key"<<endl;
        model_->setSnakeDirection(Point(-1,0));
        break;
    }

    case Qt::Key_Right:
    {

        //cout<<"Right key"<<endl;
        model_->setSnakeDirection(Point(1,0));
        break;
    }

    case Qt::Key_Down:
    {

        //cout<<"Down key"<<endl;
        model_->setSnakeDirection(Point(0,-1));
        break;
    }


    case Qt::Key_Up:
    {
        //cout<<"Up key"<<endl;
        model_->setSnakeDirection(Point(0,1));
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

}
