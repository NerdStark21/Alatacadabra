#include "model.h"


Model::Model(atomic<int> *currentDirection)
    : currentDirection_(currentDirection)
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
    snake_=Snake(width_,heigth_);
}


void Model::update(){
    snake_.move();
    fruitEaten();
}

/**
 * @brief Model::fruitEaten
 * Checks if a fruit has been eaten, and process it on the snake.
 */

void Model::fruitEaten(){
    for(Fruit f : fruits_){
        if( f.getPosition()== snake_.getBody().begin()->getCenter()){
            snake_.eatFruit();
            f.~Fruit();
        }
    }
}

void Model::Display(){
    drawWalls();
    drawSnake();
}

void Model::drawWalls(){
    vector<Wall>::iterator itw;
    for (itw = walls_.begin(); itw != walls_.end(); itw++)
        itw->drawWall();
}

void Model::drawFruits(){
    for(Fruit f:fruits_){
        f.drawFruit();
    }
}

void Model::drawSnake(){
    snake_.Display();
}

void Model::setSnakeDirection(Point direction){
    snake_.setDirection(direction);
}


/**
 * Change the snake direction accordingly with the int returned in the detection class.
 */

void Model::intToDirection(int i){
    switch(i){
    case(0):
        break;
    case(1):
        setSnakeDirection(Point(-1,0));
        break;
    case(2):
        setSnakeDirection(Point(0,1));
        break;
    case(3):
        setSnakeDirection(Point(1,0));
        break;
    case(4):
        setSnakeDirection(Point(0,-1));
        break;
    }
}

/**
 * Create a fruit on a random free space
 */

void Model::createFruit(){
    // Random point
    Point position= Point(rand() % width_ ,rand() % heigth_ );
    Fruit cherry= Fruit(position);
    bool freeSpace=false;
    while(!freeSpace){
        freeSpace=true;
        // Check if there is already a fruit there
        for( Fruit apple : fruits_ ){
            if (apple.getPosition()== cherry.getPosition()){
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






