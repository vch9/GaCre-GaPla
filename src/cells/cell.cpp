#include "cell.hpp"

Cell::Cell(const int i, const int j, Elem* e): pos_i(i), pos_j(j), elem(e) {
    this->elem = e;
}
ostream& operator<<(ostream &os, const Cell &c){
    if(c.elem==nullptr){
        os << " ";
    }
    else{
        os << *c.elem;
    }
    return os;
}