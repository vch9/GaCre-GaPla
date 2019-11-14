#ifndef BOARD
#define BOARD

#include "../cells/cell.hpp"
#include "../elems/elem.hpp"
#include <vector>
using namespace std;

class Cell;
class Elem;

class Board{
  private:
    Cell** board;
    const int lines;
    const int cols;
    /* We keep a reference on the elems, we may lose in memory optimisation.
    But we win in speed optimisation, because we don't use takeAction() on every cell, on every elem
    */
    vector<Elem*> elems;

  public:
    Board(const int, const int);
    virtual ~Board();

    /* Getters */
    int getLines();
    int getCols();
    Cell* getCell(const int, const int);
    vector<Elem*> getElems();

    /* Setters */
    void addElem(Elem* e);
    void setCell(const int, const int, Cell*);
    void setElemOnCell(const int, const int, Elem*);
    void removeFromElems(Elem*);

    /* Methods */
    void print();

    /* Move elem to (pos_i, pos_j) and changes elem->pos_i elem->pos_j */
    void move(int, int, Elem*);
};


#endif
