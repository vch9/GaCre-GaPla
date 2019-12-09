#ifndef CHARGE
#define CHARGE

#include "elem.hpp"
#include "player.hpp"

class Charge: public Elem{
    public:
      /* Constructor */
      Charge(Game*, int, int);

      /* Methods */

      /* Add a telepor bonus to the player */
      void onCollision(Elem*);
};

#endif
