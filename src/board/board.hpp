#ifndef BOARD
#define BOARD

#include "../cells/cell.hpp"
#include <vector>

class Board{
  private:
    Cell** board;
    const int lines;
    const int cols;

  public:
    Board(const int, const int);
    void setCell(const int, const int, Cell*);
    void print();
};


#endif
