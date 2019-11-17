#include "health.hpp"

/* Constructors */
Health::Health(int hp): hp_max(hp), current_hp(hp){

}

void Health::reduceHealth(int dmg){
  Health::current_hp = (Health::current_hp - dmg) % Health::hp_max;
}

void Health::heal(int h){
  Health::current_hp += h;
  if(Health::current_hp > Health::hp_max)
    Health::current_hp = Health::hp_max;
}
