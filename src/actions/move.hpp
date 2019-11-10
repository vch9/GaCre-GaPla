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
      int move_offset;
      void elem_move(Board*, Elem*, int, int);
    public:
      Move(int);
      void move(Game*, Elem*, Direction);
};

#endif
