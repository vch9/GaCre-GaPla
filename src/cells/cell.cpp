#include "cell.hpp"

/* Constructors */
Cell::Cell(Elem* e): elem(e) {

}

/* Destuctors */
Cell::~Cell(){
    if(Cell::elem!=nullptr){
        delete(Cell::elem);
    }
}

/* Setters */
void Cell::setElem(Elem* e){
    Cell::elem = e;
}

/* Getters */
Elem* Cell::getElem(){
    return Cell::elem;
}

/* Operator */
ostream& operator<<(ostream &os, const Cell &c){
    if(c.elem==nullptr){
        os << " ";
    }
    else{
        os << *c.elem;
    }
    return os;
}