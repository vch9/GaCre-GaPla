#include "charge.hpp"

Charge::Charge(Game* g, int i, int j): Elem("*", g, i, j){
    
}

void Charge::onCollision(Elem* e){
    if(e->getSymb()=="J"){
        ((Player*)e)->addTeleport();
    }
}