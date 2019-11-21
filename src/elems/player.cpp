#include "player.hpp"


Player::Player(Game* g, int t, int hp):
  Elem("J", g, -1, -1),
  Move(),
  Health(hp),
  arrow_count(2),
  diamond_count(0),
  teleport_count(t){
}

void Player::addDiamond(int d){
  Player::diamond_count+=d;
}

void Player::addTeleport(){
  Player::teleport_count++;
}

void Player::addArrow(int nb){
  Player::arrow_count = Player::arrow_count+nb;
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
    case SPACE:
      a = SHOOT;
      d = BOT; /* default */
      break;
    default:
      View::print("Wrong action, try again!\n");
      return direction();
    }
  return make_pair(a, d);
}

void shootArrow(Game* g, int from_i, int from_j){
  int dest_i = from_i;
  int dest_j = from_j;

  View::print("What direction do you wan't to shoot?\n");
  pair<PickedAction, Direction> p = direction();
  Direction d = p.second;

  /* We need the first position to instantiate the arrow */
  switch(d){
    case TOP:
    dest_i--;
    break;
    case TOPLEFT:
    dest_i--; dest_j--;
    break;
    case TOPRIGHT:
    dest_i--; dest_j++;
    break;
    case LEFT:
    dest_j--;
    break;
    case RIGHT:
    dest_j++;
    break;
    case BOT:
    dest_i++;
    break;
    case BOTLEFT:
    dest_i++, dest_j--;
    break;
    case BOTRIGHT:
    dest_i++; dest_j++;
  }

  Cell* c = g->getCurrentBoard()->getCell(dest_i, dest_j);
  Elem* e = c->getElem();

  if(e==nullptr){
    Elem* arrow = new Arrow(g, dest_i, dest_j, d);
    g->getCurrentBoard()->addElem(arrow);
    c->setElem(arrow);
  }
}
void Player::takeAction(){
  pair<PickedAction, Direction> p = direction();

  switch(p.first){
    case SHOOT:
      if(Player::arrow_count==0){
        View::print("You don't have any arrow! \n");
        takeAction();
        return;
      }
      Player::arrow_count--;
      View::print("What direction do you want to shoot\n");
      shootArrow(Elem::game, Elem::pos_i, Elem::pos_j);
      break;
    case WALK:
      Move::move(Elem::game, this, p.second, OFFSET_WALK);
      break;
    case TELEPORT:
      if(Player::teleport_count==0){
        View::print("You don't have any teleport bonus!\n");
        takeAction();
        return;
      }
      Player::teleport_count--;
      View::print("What direction do you want to teleport\n");
      pair<PickedAction, Direction> p_tp = direction();
      Move::move(Elem::game, this, p_tp.second, OFFSET_TP);
      break;
  }
}

bool Player::blockable(){
    return true;
}

string Player::to_string(){
  string s = "";
  s += "Teleports: " + std::to_string(Player::teleport_count) + "\n";
  s += "Diamonds: " + std::to_string(Player::diamond_count) + "\n";
  s += "Arrows: " + std::to_string(Player::arrow_count) + "\n";
  return s;
}

bool Player::reduceHealth(int dmg){
  bool dead = Health::reduceHealth(dmg);
  if(dead){
    Elem::switchActive();
  }
  return dead;
}
