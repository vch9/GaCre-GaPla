#include "diamond.hpp"

/* Constructors */
Diamond::Diamond(Game* g, int i, int j): Elem("$", g, i, j){

}

/* Methods */
void Diamond::onCollision(Elem* e){
    if(e->getSymb() == "J"){
        ((Player*)e)->addDiamond(1);
        ((Player*)e)->addScore(5);
    }
    Elem::game->openDoors();
}
