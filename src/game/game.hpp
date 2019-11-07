#ifndef GAME
#define GAME

#include "../board/board.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Board;

class Game{
    private:
        vector<Board*> boards;
        int current_board;
    public:
        Game();
        Game(vector<Board*>);
        void add_board(Board*);
};

#endif