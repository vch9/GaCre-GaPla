#include "elem.hpp"

Elem::Elem(const string c) : symb(c) {
    
}

ostream& operator<<(ostream &os, const Elem &e){
    os << e.symb;
    return os;
}