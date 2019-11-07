#ifndef ELEM
#define ELEM

#include <iostream>
#include "../game/game.hpp"
using namespace std;
class Game;

class Elem{
  protected:
    string symb;
    Game* game;
    int pos_i;
    int pos_j;
    Elem(const string, Game*, int, int);

  public:
    int getPosI();
    int getPosJ();

    friend ostream& operator<<(ostream& , const Elem&);
    string getSymb();
    virtual void action();
    virtual void onCollision(Elem*);
    virtual bool blockable();
};

#endif
