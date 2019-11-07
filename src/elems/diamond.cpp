#include "diamond.hpp"

Diamond::Diamond(Game* g): Elem("$", g){

}

void Diamond::onCollision(Elem* e){
    if(e->getSymb() == "J"){
        ((Player*)e)->addDiamond(1);
    }
}