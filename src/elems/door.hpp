#ifndef DOOR
#define DOOR

#include "elem.hpp"

class Door: public Elem{
    private:
        bool opened;
        bool isExit;
    public:
        Door(Game*, int, int, bool);
        bool isOpened();
        void open();
        bool blockable();
        bool isDoorExit();
};

#endif