#ifndef CHARGE
#define CHARGE

#include "elem.hpp"
#include "moving/player.hpp"

class Charge: public Elem{
    public:
        Charge(Game*);
        void onCollision(Elem*);
};

#endif