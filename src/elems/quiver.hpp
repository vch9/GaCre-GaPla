#ifndef QUIVER
#define QUIVER

#include "elem.hpp"
#include "player.hpp"

class Quiver: public Elem{
    public:
      /* Constructor */
      Quiver(Game*, int, int);

      /* Methods */

      /* Add 5 arrows to the player */
      void onCollision(Elem*);
};

#endif
