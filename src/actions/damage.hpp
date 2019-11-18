#ifndef DAMAGE
#define DAMAGE

#include "health.hpp"
#include "../elems/elem.hpp"
#include "../elems/player.hpp"

class Damage{
  private:
    int dmg;
  public:
    /* Constructors */
    Damage(int dmg);

    /* Methods */

    /* Apply damage on a elem, this elem inherites Health, return true if we killed the elem */
    bool applyDamage(Elem* e);
};

#endif
