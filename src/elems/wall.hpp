#ifndef WALL
#define WALL

#include "elem.hpp"

class Wall : public Elem{
    public:
        Wall(Game* g, int, int);
        bool blockable();
};

#endif