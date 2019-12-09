#ifndef TRAP
#define TRAP

#include "elem.hpp"
#include "player.hpp"
#include "monster.hpp"

class Trap: public Elem{
  public:
  /* Constructors */
  Trap(Game* g, int i, int j);

  /* Apply damage on the monster or player and disappears */
  void onCollision(Elem*);
  
};

#endif
