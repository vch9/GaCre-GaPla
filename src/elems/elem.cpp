#include "elem.hpp"

Elem::Elem(const string c, Game* g, int i, int j) : symb(c), game(g) {
    Elem::pos_i = i;
    Elem::pos_j = j;
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

bool Elem::blockable(){
    // default: not blockable
    return false;
}

int Elem::getPosI(){
    return Elem::pos_i;
}

int Elem::getPosJ(){
    return Elem::pos_j;
}