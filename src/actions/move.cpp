#include "move.hpp"

Move::Move(int offset): move_offset(offset){

}

void Move::elem_move(Board* b, Elem* e, int dest_i, int dest_j){
    /* Inside board */
    if(dest_i>=0 || dest_i<b->getLines() || dest_j>=0 || dest_j<b->getCols()){
        Elem* onDest = b->getCell(dest_i, dest_j)->getElem();

        /* If an elem is already on the cell we want to move e */
        if(onDest!=nullptr){
            onDest->onCollision(e);
            /* If onDest is not blockable */
            if(!onDest->blockable()){
                /* e overplace onDest */
                // delete(onDest);

                b->move(dest_i, dest_j, e);
            }
        }
        /* Else, we move to the cell */
        else{
            b->move(dest_i, dest_j, e);
        }
    }
}

void Move::move(Game* g, Elem* e, Direction d){
  switch(d){
    case TOP:
      elem_move(g->getCurrentBoard(), e, e->getPosI()-Move::move_offset, e->getPosJ());
      break;
    case LEFT:
      elem_move(g->getCurrentBoard(), e, e->getPosI(), e->getPosJ()-Move::move_offset);
      break;
    case RIGHT:
      elem_move(g->getCurrentBoard(), e, e->getPosI(), e->getPosJ()+Move::move_offset);
      break;
    case BOTTOM:
      elem_move(g->getCurrentBoard(), e, e->getPosI()-Move::move_offset, e->getPosJ());
      break;
    default:
      break;

  }
}
