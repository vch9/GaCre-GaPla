#include "player.hpp"
#include "../game/Control.hpp"


Player::Player(Game* g, int i, int j, int t): Elem("J", g, i, j){
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
    KeyCode key = Control::getKeyDown();
//    TODO : compléter
    switch (key){
        case Z:
            return;
        case Q:
            return;
        case S:
            return;
        case D:
            return;

    }
}

void Player::onCollision(Elem* e){

}

bool Player::blockable(){
    return true;
}