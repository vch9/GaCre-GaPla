#ifndef GENERATE_BOARD
#define GENERATE_BOARD

#include "../board/board.hpp"
#include "../cells/cell.hpp"

#include "../elems/wall.hpp"
#include "../elems/charge.hpp"
#include "../elems/diamond.hpp"
#include "../elems/door.hpp"
#include "../elems/moving/player.hpp"
#include "../elems/moving/monster.hpp"

#include <iostream>
#include <fstream>
using namespace std;

class GenerateBoard{
    public:
        static int getBoardLines(string);
        static int getBoardCols(string);
        static Board* createBoard(string);
};

#endif