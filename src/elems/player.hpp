#ifndef PLAYER
#define PLAYER

#include "elem.hpp"
#include "../game/control.hpp"

class Player: public Elem{
    private:
        int diamond_count;
        int teleport_count;
    public:
        Player(Game* g, int pos_i, int pos_j, int teleports);
        void addDiamond(int);
        void addTeleport();

        void onCollision(Elem*);
        void takeAction();
        bool blockable();
};

#endif