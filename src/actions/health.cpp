#include "health.hpp"

/* Constructors */
Health::Health(int hp): hp_max(hp), current_hp(hp){
}

bool Health::reduceHealth(int dmg){
  Health::current_hp = Health::current_hp - dmg;
  if(Health::current_hp <= 0){
    Health::current_hp = 0;
    return true;
  }
  return false;
}

void Health::heal(int h){
  Health::current_hp += h;
  if(Health::current_hp > Health::hp_max)
    Health::current_hp = Health::hp_max;
}
