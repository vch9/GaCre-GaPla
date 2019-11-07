#include "monster.hpp"

Monster::Monster(Game* g, int i, int j): Elem("s", g, i, j){

}

void Monster::takeAction(){

}

void Monster::onCollision(Elem *e){
    
}

bool Monster::blockable(){
    return true;
}