#include "fruit.h"

void Fruit::drawFruit(){
    quadrique_ = gluNewQuadric(); //On créé l'objet
    // Affichage de la quadrique
    gluSphere(quadrique_, radius_, 100, 100); //On dessine la quadrique
}
