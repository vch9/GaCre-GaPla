#include "wall.hpp"

Wall::Wall(Game* g, int i, int j): Elem("X", g, i, j){

}

bool Wall::blockable(){
    return true;
}