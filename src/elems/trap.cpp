#include "trap.hpp"

Trap::Trap(Game* g, int i, int j): Elem("u", g, i, j){
}

void Trap::onCollision(Elem* e){
  if(e->getSymb()=="J"){
    ((Player*)e)->reduceHealth(100);
  }
  if(e->getSymb()=="s"){
    ((Monster*)e)->reduceHealth(100);
  }
  Elem::switchActive();
  Elem::game->getCurrentBoard()->getCell(Elem::pos_i, Elem::pos_j)->setElem(nullptr);
}
