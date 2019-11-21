#ifndef MONSTER
#define MONSTER

#include "elem.hpp"
#include "player.hpp"
#include "../game/game.hpp"
#include "../actions/move.hpp"
#include "../actions/health.hpp"
#include "../common/dijkstra.hpp"
#include <tuple>
#include "../view/view.hpp"

class Elem;

class Monster: public Elem, public Move, public Health{
  private:
    /* Get closer to the player */
    void moveToPlayer();

  public:
      /* Constructors */
      Monster(Game*, int pos_i, int pos_j);

      /* Methods */

      /* Moves towards the player */
      void takeAction();

      /* Apply damage on the player */
      void onCollision(Elem*);

      /* Monster is blockable */
      bool blockable();

      /* Takes damage */
      bool reduceHealth(int dmg);
};

#endif
