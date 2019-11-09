#include "monster.hpp"

Monster::Monster(Game* g, int i, int j): Elem("s", g, i, j){

}

void Monster::takeAction(){
  //Todo: code monster's movement towards player
}

void Monster::onCollision(Elem *e){
  //Todo: apply damage on player
}

bool Monster::blockable(){
    return true;
}
