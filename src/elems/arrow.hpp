#ifndef ARROW
#define ARROW

#include "elem.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "../actions/move.hpp"
#include "../actions/health.hpp"

class Arrow: public Elem, public Move{
  private:
    Direction direction;
    bool active;

  public:
    /* Constructors */
    Arrow(Game* g, int i, int j, Direction d);

    /* Methods */

    /* Move toward the direction */
    void takeAction();

    /* Apply damage on the monster or player */
    void onCollision(Elem*);

    /* An arrow is not blockable */
    bool blockable();

};

#endif
