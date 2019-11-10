#include <cstdio>
#include "control.hpp"

KeyCode Control::getKeyDown() {
    // To modify if we change API for user's input
    char c;
    c= getchar();
    switch (c){
        case 'a':
            return A;
            break;
        case 'x':
            return X;
            break;
        case 'z':
            return Z;
            break;
        case 'q':
            return Q;
            break;
        case 's':
            return S;
            break;
        case 'd':
            return D;
            break;
    }

    return V;
}
