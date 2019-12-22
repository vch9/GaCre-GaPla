#ifndef PLAYER
#define PLAYER

#include "elem.hpp"
#include "arrow.hpp"
#include "../actions/move.hpp"
#include "../actions/health.hpp"
#include "../view/control.hpp"
#include "../view/view.hpp"
#include <cstring>
#include <iostream>
#include <tuple>
using namespace std;

class Arrow;
class Move;
class Health;

enum PickedAction{
    WALK,
    TELEPORT,
    SHOOT
};

/* Define how much cells the player can move with a simple movement, and with the teleportation */
#define OFFSET_WALK 1
#define OFFSET_TP 5

class Arrow;

class Player: public Elem, public Move, public Health{
    private:
      int arrow_count;
      int diamond_count;
      int teleport_count;
      int score;

    public:
      /* Constructors */
      Player(Game* g, int teleports, int hp);

      /* Setters */
      void addDiamond(int);
      void addTeleport();
      void addArrow(int);
      void addScore(int);

      /* Getters */
      int getScore();

      /* Waits for user's input,
          move topleft,
          move top,
          move topright,
          move left,
          move right,
          move botleft,
          move bot,
          move botright
      */
      void takeAction();

      /* Player is blockable */
      bool blockable();

      /* Display diamonds, teleports, health.. */
      void print();

      /* Player is alive if it still has hp left */
      bool isActive();

      /* Return diamonds, teleports in a string etc.. */
      string to_string();

      /* Takes damage */
      bool reduceHealth(int dmg);
};

#endif
