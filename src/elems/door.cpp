#include "door.hpp"

/* Constructors */
Door::Door(Game* g, int i, int j, bool isExit): Elem("-", g, i, j){
    Door::opened = false;
    Door::isExit = isExit;
}

/* Getters */
bool Door::isOpened(){
    return Door::opened;
}

bool Door::isDoorExit(){
    return Door::isExit;
}

/* Setters */
void Door::open(){
    Door::opened = true;
    Elem::symb = "+";
}

/* Methods */
bool Door::blockable(){
    return true;
}

void Door::onCollision(Elem* e){
    if(e->getSymb()=="J"){
        if(Door::opened){
            /* Next board */
            if(Door::isExit){
                Elem::game->changeBoard(true);
            }

            /* Previous board */
            else{
                Elem::game->changeBoard(false);
            }
        }
    }
}