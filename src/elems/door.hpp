#ifndef DOOR
#define DOOR

#include "elem.hpp"

class Door: public Elem{
    private:
        bool opened;
    public:
        Door(Game*, int, int);
        bool isOpened();
        void open();
        bool blockable();
};

#endif