#ifndef MONSTER
#define MONSTER

#include "elem.hpp"
#include "../game/game.hpp"
#include "../cells/cell.hpp"
#include "../actions/move.hpp"
#include <queue>
#include <tuple>
#include <climits>

class Elem;

class Monster: public Elem, public Move{
    public:
        /* Constructors */
        Monster(Game*, int, int);

        /* Methods */

        /* Moves towards the player */
        void takeAction();

        /* Apply damage on the player */
        void onCollision(Elem*);

        /* Monster is blockable */
        bool blockable();
};

#endif