#include "model.h"

Model::Model()
{
    qDebug()<<"Création du model"<<endl;

    // Dimension du plateau de jeux en openGL
    int cote = 250;
    int epaisseur = 5;

   // Dimension du plateau de jeu
    width_=50;
    heigth_=50;

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

    // Ajout du snake
    Snake Snake_=new Snake(width,length);
}

void Model::drawWalls(){
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++)
        itw->drawWall();
}


/*
 * Create a fruit on a random free space
 *
 *
 */

void Model::createFruit(){
    // Random point
    Point position= new Point(rand() % width_ ,rand() % heigth_ );
    fruit cherry= new fruit(position);
    bool freeSpace=false;
    while(!freeSpace){
        freeSpace=true;
        // Check if there is already a fruit there
        for( Fruit apple : fruits_ ){
            if (apple.getPosition()== cherry.getPosition){
                freeSpace=false;
                break;
            }
        }

        // Check if there is already a bodypart there
        for(BodyPart part:snake_.getBody()){
            if(part.getCenter()==cherry.getPosition()){
                freeSpace=false;
                break;
            }
        }
        // Get another point
        position=Point(rand() % width_ ,rand() % heigth_ );
    }

    fruits_.push_back(cherry);
}








