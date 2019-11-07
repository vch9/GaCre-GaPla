#include "movingElem.hpp"

MovingElem::MovingElem(string symb, Board* b, int i, int j): Elem(symb, b){
    this->pos_i = i;
    this->pos_j = j;
}