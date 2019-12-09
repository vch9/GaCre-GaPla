#include "arrow.hpp"

/* Constructors */
Arrow::Arrow(Game* g, int i, int j, Direction d):
  Elem("~", g, i, j),
  Move(),
  direction(d),
  active(true){
}

/* Methods */

void Arrow::takeAction(){
  /* Follow it's journey */
  move(Arrow::game, this, Arrow::direction, 1);
}

void Arrow::onCollision(Elem* e){
  if(e->getSymb()=="s"){
    ((Monster*)e)->reduceHealth(50);
  }
  if(e->getSymb()=="J"){
    ((Player*)e)->reduceHealth(50);
  }
  Elem::switchActive();
  Elem::game->getCurrentBoard()->getCell(Elem::pos_i, Elem::pos_j)->setElem(nullptr);
}

bool Arrow::blockable(){
  return false;
}
