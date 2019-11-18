#include "move.hpp"

/* Methods */

void Move::elem_move(Board* b, Elem* e, int dest_i, int dest_j){
    /* Secure bound values */
    if(dest_i < 0) dest_i = 0;
    if(dest_i >= b->getLines()) dest_i = b->getLines()-1;
    if(dest_j < 0) dest_j = 0;
    if(dest_j >= b->getCols()) dest_j = b->getCols()-1;

    /* Inside board */
    if(b!=nullptr && (dest_i>=0 || dest_i<b->getLines() || dest_j>=0 || dest_j<b->getCols())){
        Elem* onDest = b->getCell(dest_i, dest_j)->getElem();

        /* If an elem is already on the cell we want to move e */
        if(onDest!=nullptr){
            onDest->onCollision(e);
            e->onCollision(onDest);

            /* If onDest is not blockable */
            if(!onDest->blockable()){
                /* e overplace onDest */
                b->move(dest_i, dest_j, e);
            }
        }
        /* Else, we move to the cell */
        else{
            b->move(dest_i, dest_j, e);
        }
    }
}

void Move::move(Game* g, Elem* e, Direction d, int offset){
  switch(d){
    case TOP:
      elem_move(g->getCurrentBoard(), e, e->getPosI()-offset, e->getPosJ());
      break;
    case TOPLEFT:
      elem_move(g->getCurrentBoard(), e, e->getPosI()-offset, e->getPosJ()-offset);
      break;
    case TOPRIGHT:
      elem_move(g->getCurrentBoard(), e, e->getPosI()-offset, e->getPosJ()+offset);
      break;

    case LEFT:
      elem_move(g->getCurrentBoard(), e, e->getPosI(), e->getPosJ()-offset);
      break;
    case RIGHT:
      elem_move(g->getCurrentBoard(), e, e->getPosI(), e->getPosJ()+offset);
      break;

    case BOT:
      elem_move(g->getCurrentBoard(), e, e->getPosI()+offset, e->getPosJ());
      break;
    case BOTLEFT:
      elem_move(g->getCurrentBoard(), e, e->getPosI()+offset, e->getPosJ()-offset);
      break;
    case BOTRIGHT:
      elem_move(g->getCurrentBoard(), e, e->getPosI()+offset, e->getPosJ()+offset);
      break;

    default:
      break;

  }
}
