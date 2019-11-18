#include "damage.hpp"

/* Constructors */
Damage::Damage(int dmg): dmg(dmg){

}

/* Methods */
bool Damage::applyDamage(Elem* e){
  Player* p = (Player*)e;
  return p->reduceHealth(Damage::dmg);
}
