#ifndef GAME
#define GAME

#include <vector>
#include <iostream>
#include "../board/board.hpp"
#include "../elems/elem.hpp"
using namespace std;

class Board;
class Elem;

class Game{
    private:
        vector<Board*> boards;
        int current_board;
    public:
        Game();
        Game(vector<Board*>);
        void add_board(Board*);
        void print();

        void elem_move(Elem*, int, int);
        void nextTurn();
};

#endif