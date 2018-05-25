#ifndef PARTIE_H
#define PARTIE_H

#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <GL/glu.h>
#include <QColor>

// C'est dans cette classe qu'on va faire tout l'affichage

class Partie : public QGLWidget
{
public:
    Partie(QWidget*parent);
    void initializeGL();
    void updateGame();
private:
    int score_;
};

#endif // PARTIE_H
