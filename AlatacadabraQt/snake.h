#ifndef SNAKE_H
#define SNAKE_H
<<<<<<< HEAD
#include <vector>
#include "bodypart.h"
=======

#include "bodypart.h"
#include <vector>
>>>>>>> Modification du modèle, maintenant, on a une grille composée de node et dans cette grille on stocke le snake

class Snake
{
private:
<<<<<<< HEAD
    Point direction_;
    int size_;
    Vector<BodyPart> body_;

public:
    Snake();
    void drawSnake();
    void move();
    bool deadlyPLace();
    void eatFruit();
=======
    // liste des indices auxquels on a les points du snake
    vector<int> listNode_;
    // Diamètre des éléments du snake
    int radius_;

public:
    Snake();
    void drawNode();

>>>>>>> Modification du modèle, maintenant, on a une grille composée de node et dans cette grille on stocke le snake
};

#endif // SNAKE_H
