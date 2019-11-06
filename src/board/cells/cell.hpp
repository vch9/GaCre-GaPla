#ifndef CELL
#define CELL

#include "elems/elem.hpp"

class Cell{
  private:
    int pos_i;
    int pos_j;
    Elem elem;
  public:
    Cell(const int, const int, Elem);
};

#endif
