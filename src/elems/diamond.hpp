#ifndef DIAMOND
#define DIAMOND

#include "elem.hpp"
#include "player.hpp"

class Diamond: public Elem{
    public:
        Diamond(Game* g, int, int);
        void onCollision(Elem *);
};

#endif