#include "player.hpp"


Player::Player(Game* g, int i, int j, int t): Elem("J", g, i, j){
    Player::diamonds = 0;
    Player::teleports = t;
}

void Player::addDiamond(int d){
    Player::diamonds+=d;
}

void Player::addTeleport(){
    Player::teleports++;
}

void onCollision(Elem* e){
    
}

void Player::action(){
    
}

void Player::onCollision(Elem* e){

}

bool Player::blockable(){
    return true;
}