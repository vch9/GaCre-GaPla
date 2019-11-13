#include "player.hpp"


Player::Player(Game* g, int t): Elem("J", g, -1, -1), Move(){
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

void Player::takeAction(){
  char input[256];
  cout << "Pick your action" << endl;
  cin.getline(input, 256);

  char* token = strtok(input, " ");

  PickedAction action;

  if(token && (strncmp(token, "move", 4)==0 || strncmp(token, "teleport", 8)==0) ){
    if(strncmp(token, "move", 4)==0){
      action=WALK;
    }
    else if(strncmp(token, "teleport", 8)==0){
      action=TELEPORT;
    }
    token = strtok(NULL, " ");

    Direction d;
    if(!token){
      cout << "Need action precision" << endl;
      takeAction();
      return;
    }
    else if(strncmp(token, "topleft", 7)==0){
      d=TOPLEFT;
    }
    else if(strncmp(token, "topright", 8)==0){
      d=TOPRIGHT;
    }
    else if(strncmp(token, "top", 3)==0){
      d=TOP;
    }
    else if(strncmp(token, "left", 4)==0){
      d=LEFT;
    }
    else if(strncmp(token, "right", 5)==0){
      d=RIGHT;
    }
    else if(strncmp(token, "botright", 8)==0){
      d=BOTRIGHT;
    }
    else if(strncmp(token, "botleft", 7)==0){
      d=BOTLEFT;
    }
    else if(strncmp(token, "bot", 3)==0){
      d=BOT;
    }
    else{
      cout << "Wrong move" << endl;
      takeAction();
      return;
    }

    if(action==WALK){
      Move::move(Elem::game, this, d, OFFSET_WALK);
    }
    if(action==TELEPORT){
      Move::move(Elem::game, this, d, OFFSET_TP);
    }
    return;
  }
  

  cout << "Wrong command for player" << endl;
  takeAction();
}

bool Player::blockable(){
    return true;
}

void Player::print(){
  cout << "Teleports: " << Player::teleport_count << endl;
  cout << "Diamonds: " << Player::diamond_count << endl;
}