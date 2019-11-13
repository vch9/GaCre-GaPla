#ifndef PLAYER
#define PLAYER

#include "elem.hpp"
#include "../actions/move.hpp"
#include <cstring>
#include <iostream>
using namespace std;

enum PickedAction{
    WALK,
    TELEPORT
};


/* Define how much cells the player can move with a simple movement, and with the teleportation */
#define OFFSET_WALK 1
#define OFFSET_TP 5

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
