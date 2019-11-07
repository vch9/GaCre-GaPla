#ifndef PLAYER
#define PLAYER

#include "movingElem.hpp"

class Player: public MovingElem{
    private:
        int diamonds;
        int teleports;
    public:
        Player(Game* g, int pos_i, int pos_j, int teleports);
        void addDiamond(int);
        void addTeleport();

        void onCollision(Elem*);
        void action();
        bool blockable();
};

#endif