#include "player.hpp"


Player::Player(Game* g, int t, int hp): Elem("J", g, -1, -1), Move(), Health(hp){
    Player::diamond_count = 0;
    Player::teleport_count = t;
}

void Player::addDiamond(int d){
    Player::diamond_count+=d;
}

void Player::addTeleport(){
    Player::teleport_count++;
}

void onCollision(Elem* e){

}

pair<PickedAction, Direction> direction(){
  KeyCode key = Control::getKeyDown();

  Direction d;
  PickedAction a;

  switch(key){
    case Z:
      d = TOP;
      a = WALK;
      break;
    case Q:
      d = LEFT;
      a = WALK;
      break;
    case S:
      d = BOT;
      a = WALK;
      break;
    case D:
      d = RIGHT;
      a = WALK;
      break;
    case A:
      d = TOPLEFT;
      a = WALK;
      break;
    case E:
      d = TOPRIGHT;
      a = WALK;
      break;
    case W:
      d = BOTLEFT;
      a = WALK;
      break;
    case C:
      d = BOTRIGHT;
      a = WALK;
      break;
    case T:
      a = TELEPORT;
      d = BOT; /* default */
      break;
    default:
      View::print("Wrong action, try again!\n");
      return direction();
    }
  return make_pair(a, d);
}

void Player::takeAction(){
  pair<PickedAction, Direction> p = direction();

  switch(p.first){
    case WALK:
      Move::move(Elem::game, this, p.second, OFFSET_WALK);
      return;
    case TELEPORT:
      if(Player::teleport_count==0){
        View::print("You don't have any teleport bonus!\n");
        takeAction();
        return;
      }
      Player::teleport_count--;
      View::print("What direction do you want to teleport\n");
      pair<PickedAction, Direction> prim = direction();
      Move::move(Elem::game, this, prim.second, OFFSET_TP);
      return;
  }
}

bool Player::blockable(){
    return true;
}

bool Player::isActive(){
  return Health::current_hp > 0;
}

string Player::to_string(){
  string s = "";
  s += "Teleports: " + std::to_string(Player::teleport_count) + "\n";
  s += "Diamonds: " + std::to_string(Player::diamond_count) + "\n";
  return s;
}

/* Virtual from health */
bool Health::reduceHealth(int dmg){
  Health::current_hp = Health::current_hp - dmg;
  if(Health::current_hp < 0){
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
