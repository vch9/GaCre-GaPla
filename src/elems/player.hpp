#ifndef PLAYER
#define PLAYER

#include "elem.hpp"
#include "../actions/move.hpp"
#include <cstring>
#include <iostream>
using namespace std;

class Player: public Elem, public Move{
    private:
        int diamond_count;
        int teleport_count;
    public:
        /* Constructors */
        Player(Game* g, int teleports);

        /* Setters */
        void addDiamond(int);
        void addTeleport();

        /* Waits for user's input,
            move topleft,
            move top,
            move topright,
            move left,
            move right,
            move botleft,
            move bot,
            move botright
        */
        void takeAction();

        /* Player is blockable */
        bool blockable();

        /* Display diamonds, teleports, health.. */
        void print();
};

#endif
