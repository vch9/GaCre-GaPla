#ifndef HEALTH
#define HEALTH

#include <iostream>
using namespace std;

class Health{
  protected:
    int hp_max;
    int current_hp;

  public:
    /* Constructors */
    Health(int hp_max);

    /* Methods */

    /* Health reduces with dmg, returns false if current_hp > 0 */
    bool reduceHealth(int dmg);

    /* Add health with heal */
    void heal(int h);
};

#endif
