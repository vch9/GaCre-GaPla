#ifndef MONSTER
#define MONSTER

#include "movingElem.hpp"

class Monster: public MovingElem{
    public:
        Monster(Game*, int, int);

        void action();
        void onCollision(Elem*);
};

#endif