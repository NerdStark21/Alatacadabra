#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "ui_mainwindow.h"
#include "model.h"
#include "traitement.h"

class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();
    void update();
    void DrawBackGround();
    Model* getModel();

protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    void keyPressEvent(QKeyEvent * event);



private:
    int width_;
    int height_;
    Model* model_;
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer_;
    GLuint * m_TextureID_;
    QImage * img_plan_;

    /*
private:
    Ui::MainWindow *ui;
    */

};

#endif // MAINWINDOW_H
