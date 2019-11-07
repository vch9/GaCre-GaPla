#include "door.hpp"

Door::Door(Game* g): Elem("-", g){
    Door::opened = false;
}

bool Door::isOpened(){
    return Door::opened;
}

void Door::open(){
    Door::opened = true;
}