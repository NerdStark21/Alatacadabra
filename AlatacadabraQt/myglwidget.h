#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <GL/glu.h>
#include "model.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    MyGLWidget();

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier (Ne fonctionne pas avec lorsque la caméra est activée)
    void keyPressEvent(QKeyEvent * event);


private:
    // Timer d'animation
    QTimer m_AnimationTimer_;
};

#endif // MYGLWIDGET_H
