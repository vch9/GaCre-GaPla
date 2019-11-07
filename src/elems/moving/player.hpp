#ifndef PLAYER
#define PLAYER

#include "movingElem.hpp"

class Player: public MovingElem{
    private:
        int diamonds;
        int teleports;
        int hp;
    public:
        Player(Game* g, int pos_i, int pos_j, int teleports, int hp);
        void addDiamond(int);
        void addTeleport();

        void onCollision(Elem*);
        void action();
};

#endif