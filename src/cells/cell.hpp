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
    /* Constructors */
    Cell(Elem*);

    /* Destructors */
    virtual ~Cell();

    /* Setters */
    void setElem(Elem*);

    /* Getters */
    Elem* getElem();

    /* Operator */
    friend ostream& operator<<(ostream& , const Cell&);

};

#endif
