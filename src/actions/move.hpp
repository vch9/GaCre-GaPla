#ifndef MOVE
#define MOVE

#include "../elems/elem.hpp"
#include "../game/game.hpp"
#include "../board/board.hpp"

enum Direction{
  TOPLEFT, TOP, TOPRIGHT,
  LEFT, RIGHT,
  BOTLEFT, BOT, BOTRIGHT
};

class Board;
class Elem;
class Game;

class Move{
  public:
    private:
      /* How much cells we move */
      int move_offset;

      /* Apply the movement on the game */
      void elem_move(Board*, Elem*, int dest_i, int dest_j);
    public:
      /* Methods */

      /* Move elem in given direction, with given offset */
      void move(Game*, Elem*, Direction, int offset);
};

#endif
