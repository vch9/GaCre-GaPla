#include "elem.hpp"

Elem::Elem(const string c, Game* g) : symb(c), game(g) {
    
}

ostream& operator<<(ostream &os, const Elem &e){
    os << e.symb;
    return os;
}

string Elem::getSymb(){
    return Elem::symb;
}

void Elem::action(){
    // does nothing;
}

void Elem::onCollision(Elem*){
    // nothing happens
}