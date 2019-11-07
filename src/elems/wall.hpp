#ifndef WALL
#define WALL

#include "elem.hpp"

class Wall : public Elem{
    public:
        Wall(Board* b);
};

#endif