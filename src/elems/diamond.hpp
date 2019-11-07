#ifndef DIAMOND
#define DIAMOND

#include "elem.hpp"
#include "moving/player.hpp"

class Diamond: public Elem{
    public:
        Diamond(Game* g);
        void onCollision(Elem *);
};

#endif