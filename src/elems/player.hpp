#ifndef PLAYER
#define PLAYER

#include "elem.hpp"

class Player: public Elem{
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