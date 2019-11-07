#ifndef MONSTER
#define MONSTER

#include "movingElem.hpp"

class Monster: public MovingElem{
    public:
        Monster(Board*, int, int);
};

#endif