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
        int pos_i;
        int pos_j;
    public:
        MovingElem(string, Game*, int, int);
        void move(Directions d);
};

#endif