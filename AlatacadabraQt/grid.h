#ifndef GRID_H
#define GRID_H

#include "node.h"
#include "snake.h"

#include <vector>

class Grid
{
private:
    vector<Node> listNode_;
    Snake snake_;
    // Pour que l'on puisse initialiser les dimensions de la grille
    int
        largeur_,
        hauteur_,
        nbLigne_,
        nbColonne_;

public:
    Grid();
    void drawSnake();
};

#endif // GRID_H
