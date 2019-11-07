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
    Elem(const string, Game*);

  public:
    friend ostream& operator<<(ostream& , const Elem&);
    string getSymb();
    virtual void action();
    virtual void onCollision(Elem*);
};

#endif
