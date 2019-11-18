#ifndef DIAMOND
#define DIAMOND

#include "elem.hpp"
#include "player.hpp"

class Diamond: public Elem{
    public:
        /* Constructors */
        Diamond(Game* g, int, int);

        /* Methods */

        /* Add diamond to the player and open all doors */
        void onCollision(Elem *);
};

#endif