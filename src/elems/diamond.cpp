#include "diamond.hpp"

Diamond::Diamond(Game* g, int i, int j): Elem("$", g, i, j){

}

void Diamond::onCollision(Elem* e){
    if(e->getSymb() == "J"){
        ((Player*)e)->addDiamond(1);
    }
}