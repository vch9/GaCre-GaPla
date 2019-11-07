#ifndef CELL
#define CELL

#include "../elems/elem.hpp"
#include <iostream>
using namespace std;
class Elem;

class Cell{
  private:
    Elem* elem;
  public:
    Cell(Elem*);
    void setElem(Elem*);
    Elem* getElem();
    friend ostream& operator<<(ostream& , const Cell&);

};

#endif
