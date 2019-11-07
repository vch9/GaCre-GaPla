#ifndef MOVINGELEM
#define MOVINGELEM

#include "../elem.hpp"

enum Directions{
    TOPLEFT, TOP, TOPRIGHT,
    MIDLEFT, MID, MIDRIGHT,
    BOTLEFT, BOT, BOTRIGHT
};

class MovingElem : public Elem{
    private:
        int offset_movement;

    public:
        MovingElem(string, Game*, int, int, int);
        void move(Directions);
};

#endif