#include "player.hpp"


Player::Player(Game* g, int i, int j, int t): MovingElem("J", g, i, j, 1){
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
    char key;
    cin >> key;
    switch(int(key)){
        /* Top */
        case 55:
            move(TOPLEFT);
            break;
        case 56:
            move(TOP);
            break;
        case 57:
            move(TOPRIGHT);
            break;
        
        /* Middle */
        case 52:
            move(MIDLEFT);
            break;
        case 53:
            move(MID);
            break;
        case 54:
            move(MIDRIGHT);
            break;

        /* Bottoms */
        case 49:
            move(BOTLEFT);
            break;
        case 50:
            move(BOT);
            break;
        case 51:
            move(BOTRIGHT);
            break;
        default:
            return action();
    }
}

void Player::onCollision(Elem* e){

}

bool Player::blockable(){
    return true;
}