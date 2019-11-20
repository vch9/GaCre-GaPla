#ifndef VIEW
#define VIEW

#include <ncurses.h>
#include "../board/board.hpp"
#include "../cells/cell.hpp"
#include "../elems/elem.hpp"
#include <cstring>
using namespace std;

class View{
  public:
    /* Start curses mode */
    static void init();

    /* Print the board */
    static void printBoard(Board* b);

    /* Print a message */
    static void print(string m);

    /* Clear the window */
    static void clear_window();

    /* End curses mode by printing the board and a message */
    static void close(Board* b, string m);

};

#endif
