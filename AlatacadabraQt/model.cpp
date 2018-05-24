#include "model.h"

Model::Model()
{
    qDebug()<<"Création du model"<<endl;

    // Dimension du plateau de jeux
    int cote = 250;
    int epaisseur = 5;

    // Création des Rect des murs
    Rect coordUp(-cote/2, cote/2, cote, epaisseur);
    Rect coordDown(-cote/2, -cote/2, cote, epaisseur);
    Rect coordLeft(-cote/2, -cote/2, epaisseur, cote);
    Rect coordRight(cote/2, -cote/2, epaisseur, cote);

    // Création des murs
    Wall wallUp(coordUp);
    Wall wallDown(coordDown);
    Wall wallLeft(coordLeft);
    Wall wallRight(coordRight);

    // Ajout des murs dans le vecteur
    walls_.push_back(wallUp);
    walls_.push_back(wallDown);
    walls_.push_back(wallLeft);
    walls_.push_back(wallRight);
}

void Model::drawWalls(){
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++)
        itw->drawWall();
}
