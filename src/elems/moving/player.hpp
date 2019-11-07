#ifndef PLAYER
#define PLAYER

#include "movingElem.hpp"

class Player: public MovingElem{
    public:
        Player(Board*, int, int);
};

#endif