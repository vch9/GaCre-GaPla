#include "damage.hpp"

/* Constructors */
Damage::Damage(int dmg): dmg(dmg){

}

/* Methods */
bool Damage::applyDamage(Elem* e){
  Health* h = (Health*) e;
  return h->reduceHealth(Damage::dmg);
}
