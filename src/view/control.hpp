#ifndef CONTROL
#define CONTROL

#include <iostream>
#include <ncurses.h>

enum KeyCode{
    Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,Z,X,C,V,B,N,M,K_UP,K_DOWN,K_LEFT,K_RIGHT
};

class Control {
  public:
    static KeyCode getKeyDown();
};


#endif //CONTROL
