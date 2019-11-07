#ifndef BOARD
#define BOARD

#include "../cells/cell.hpp"
class Cell;

class Board{
  private:
    Cell** board;
    const int lines;
    const int cols;

  public:
    Board(const int, const int);
    void setCell(const int, const int, Cell*);
    void print();
    Cell* getCell(const int, const int);
};


#endif
