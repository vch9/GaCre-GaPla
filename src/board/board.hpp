#ifndef BOARD
#define BOARD

#include "../cells/cell.hpp"
#include "../elems/elem.hpp"
#include <vector>
using namespace std;


class Cell;
class Elem;
// class MovingElem;

class Board{
  private:
    Cell** board;
    const int lines;
    const int cols;
    /* We keep a reference on the actionnables elems, we may lose in memory optimisation.
    But we win in speed optimisation, because we don't use action() on every cell, on every elem
    */
    vector<Elem*> actionnables_elems;

    void move(int, int, Elem*);

  public:
    Board(const int, const int);
    void addActionnableElem(Elem* e);
    void setCell(const int, const int, Cell*);
    void setElemOnCell(const int, const int, Elem*);
    void print();
    Cell* getCell(const int, const int);

    void elem_move(Elem*, int, int);
};


#endif
