#ifndef MOVINGELEM
#define MOVINGELEM

#include "../elem.hpp"

class MovingElem : public Elem{
    private:
        int pos_i;
        int pos_j;
    public:
        MovingElem(string, Board*, int, int);
};

#endif