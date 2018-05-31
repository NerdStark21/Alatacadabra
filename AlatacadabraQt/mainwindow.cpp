#define _USE_MATH_DEFINES

#include "mainwindow.h"

using namespace cv;

const unsigned int WIN_WIDTH  = 50;
const unsigned int WIN_HEIGHT = 50;
const float MAX_DIMENSION     = 200.0f;

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
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        this->update();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();


    qDebug()<<"On a set le timer"<<endl;

    // Création du modèle
    model_ = new Model();
    // Création de la classe de détection
    detection_ = new Detection();
}

void MainWindow::update(){
    model_->update();
}


MainWindow::~MainWindow(){
}


// Fonction d'initialisation
void MainWindow::initializeGL()
{
    qDebug()<<"On initialise le GL"<<endl;
    // Reglage de la couleur de fond
    glClearColor(15, 15, 15, 1);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
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

    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Caméra / Cible / Vecteur vertical
    gluLookAt(0.0,0.0,10,
              0.0,0.0,0.0,
              0.0,1.0,0.0);

    // On va dessiner tous les murs
    model_->drawWalls();
    model_->Display();
}
