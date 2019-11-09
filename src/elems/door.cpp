#include "door.hpp"

Door::Door(Game* g, int i, int j): Elem("-", g, i, j){
    Door::opened = false;
}

bool Door::isOpened(){
    return Door::opened;
}

void Door::open(){
    Door::opened = true;
    Elem::symb = "+";
}

bool Door::blockable(){
    return !Door::opened;
}
