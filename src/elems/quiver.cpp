#include "quiver.hpp"

Quiver::Quiver(Game* g, int i, int j):
  Elem(":", g, i, j){
}

void Quiver::onCollision(Elem* e){
  if(e->getSymb()=="J"){
    ((Player*)e)->addArrow(5);
  }
}
