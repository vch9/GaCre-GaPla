#include "cell.hpp"

Cell::Cell(Elem* e): elem(e) {

}

void Cell::setElem(Elem* e){
    Cell::elem = e;
}

Elem* Cell::getElem(){
    return Cell::elem;
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