#include "monster.hpp"

Monster::Monster(Game* g, int i, int j): MovingElem("s", g, i, j, 1){

}

void Monster::action(){

}

void Monster::onCollision(Elem *e){
    
}

bool Monster::blockable(){
    return true;
}