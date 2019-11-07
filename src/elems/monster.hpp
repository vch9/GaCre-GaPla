#ifndef MONSTER
#define MONSTER

#include "elem.hpp"

class Monster: public Elem{
    public:
        Monster(Game*, int, int);

        void action();
        void onCollision(Elem*);
        bool blockable();
};

#endif