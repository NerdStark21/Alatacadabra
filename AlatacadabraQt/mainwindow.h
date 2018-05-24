#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "partie.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "detection.h"

class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
    int width_;
    int height_;
    Model* model_;
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    Detection* detection_;

    /*
private:
    Ui::MainWindow *ui;
    */
};

#endif // MAINWINDOW_H
