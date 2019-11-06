#ifndef BOARD
#define BOARD

#include "cells/cell.hpp"

class Board{
  private:
    Cell** board;
    const int lines;
    const int cols;

  public:
    Board(const int, const int);
};


#endif
