//
// Created by benjamin on 07/11/2019.
//

#include <cstdio>
#include "Control.hpp"

KeyCode Control::getKeyDown() {
//    A modifier si l'on rajoute une api pour capturer les touches du clavier
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
}
