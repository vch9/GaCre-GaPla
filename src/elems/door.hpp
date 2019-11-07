#ifndef DOOR
#define DOOR

#include "elem.hpp"

class Door: public Elem{
    private:
        bool opened;
    public:
        Door(Game*);
        bool isOpened();
        void open();
};

#endif