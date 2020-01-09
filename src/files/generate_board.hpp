#ifndef GENERATE_BOARD
#define GENERATE_BOARD

#include "../game/game_endless.hpp"
#include "../common/dijkstra.hpp"
#include "../game/game.hpp"
#include "../board/board.hpp"
#include "../cells/cell.hpp"

#include "../elems/wall.hpp"
#include "../elems/charge.hpp"
#include "../elems/diamond.hpp"
#include "../elems/door.hpp"
#include "../elems/player.hpp"
#include "../elems/monster.hpp"
#include "../elems/quiver.hpp"
#include "../elems/trap.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
using namespace std;
class Game_endless;
class GenerateBoard{
    public:
        static int getBoardLines(string);
        static int getBoardCols(string);
        static Board* createBoard(Game* g , string s);
        static Board * createRandomBoard(Game_endless* g , int currentFloor  );

};

#endif
