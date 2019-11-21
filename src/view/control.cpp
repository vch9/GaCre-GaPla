#include "control.hpp"

KeyCode Control::getKeyDown() {
    char c;
    c= getch();
    KeyCode key = O;
    switch (c){
        case 'z':
          key = Z;
          break;
        case 'q':
          key = Q;
          break;
        case 's':
          key = S;
          break;
        case 'd':
          key = D;
          break;
        case 'a':
          key = A;
          break;
        case 'e':
          key = E;
          break;
        case 'w':
          key = W;
          break;
        case 'c':
          key = C;
          break;
        case 't':
          key = T;
          break;
    }
    return key;
}
