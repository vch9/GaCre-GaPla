#ifndef ELEM
#define ELEM

#include <iostream>
#include "../board/board.hpp"
using namespace std;
class Board;

class Elem{
  protected:
    string symb;
    Board* board;

  public:
    Elem(const string, Board*);
    friend ostream& operator<<(ostream& , const Elem&);
    string getSymb();
    void action();
};

#endif
