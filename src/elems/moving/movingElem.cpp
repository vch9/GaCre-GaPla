#include "movingElem.hpp"

MovingElem::MovingElem(string symb, Game* g, int i, int j): Elem(symb, g){
    this->pos_i = i;
    this->pos_j = j;
}

void MovingElem::move(Directions d){
    
}