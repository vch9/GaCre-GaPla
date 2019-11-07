#include "charge.hpp"

Charge::Charge(Game* g): Elem("*", g){
    
}

void Charge::onCollision(Elem* e){
    if(e->getSymb()=="J"){
        ((Player*)e)->addTeleport();
    }
}