#ifndef DOOR
#define DOOR

#include "elem.hpp"
#include "../game/game.hpp"

class Door: public Elem{
    private:
        bool opened;
        bool isExit;

    public:
        /* Constructors */
        Door(Game*, int, int, bool);

        /* Getters */
        bool isOpened();

        /* Setters */
        void open();

        /* Methods */

        /* Door is blockable but we can pass throught it */
        bool blockable();

        /* Return true if the door is the next door */
        bool isDoorExit();

        /* Change the board if the door is open */
        void onCollision(Elem*);
};

#endif