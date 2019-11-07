#ifndef CELL
#define CELL

#include "../elems/elem.hpp"
#include <iostream>
using namespace std;
class Elem;

class Cell{
  private:
    const int pos_i;
    const int pos_j;
    Elem* elem;
  public:
    Cell(const int, const int, Elem*);
    friend ostream& operator<<(ostream& , const Cell&);

};

#endif
