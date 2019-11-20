#include "elem.hpp"

/* Constructors */
Elem::Elem(const string c, Game* g, int i, int j) : symb(c), game(g) {
    Elem::pos_i = i;
    Elem::pos_j = j;
}

/* Destructors */
Elem::~Elem(){

}

ostream& operator<<(ostream &os, const Elem &e){
    os << e.symb;
    return os;
}

/* Getters */
int Elem::getPosI(){
    return Elem::pos_i;
}

int Elem::getPosJ(){
    return Elem::pos_j;
}

string Elem::getSymb(){
    return Elem::symb;
}

/* Setters */
void Elem::setPosI(int pos_i){
    Elem::pos_i = pos_i;
}

void Elem::setPosJ(int pos_j){
    Elem::pos_j = pos_j;
}

/* Methods */
void Elem::takeAction(){
    // does nothing;
}

void Elem::onCollision(Elem*){
    // nothing happens
}

bool Elem::blockable(){
    // default: not blockable
    return false;
}

bool Elem::isActive(){
  return true;
}

string Elem::to_string(){
  return "";
}
