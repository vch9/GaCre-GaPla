#include "elem.hpp"

Elem::Elem(const string c, Board* b) : symb(c), board(b) {
    
}

ostream& operator<<(ostream &os, const Elem &e){
    os << e.symb;
    return os;
}

string Elem::getSymb(){
    return Elem::symb;
}

void Elem::action(){
    cout << "action" << endl;
}