#ifndef CHARGE
#define CHARGE

#include "elem.hpp"
#include "player.hpp"

class Charge: public Elem{
    public:
        Charge(Game*, int, int);
        void onCollision(Elem*);
};

#endif