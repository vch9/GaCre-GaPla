#include "door.hpp"

Door::Door(Game* g, int i, int j, bool isExit): Elem("-", g, i, j){
    Door::opened = false;
    Door::isExit = isExit;
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

bool Door::isDoorExit(){
    return Door::isExit;
}
