#include <game_file_creator.h>
#include <string>
#include <vector>

using namespace std;
// #include "cases/case.hpp"
#include <ncurses.h>
#include <board_file_creator.h>

int main(int argc, char *argv[]){
//
//    string board("/home/benjamin/Documents/GaCre-GaPla/src/test.board");
//    string board2("/home/benjamin/Documents/GaCre-GaPla/src/test2.board");
//    ifstream f(board);
//    if (f.is_open())
//        std::cout << f.rdbuf();
//
//    string out("oui.game");
//
//    game_file_creator::create_game_file(out , vector<string>{board,board2});

//BOARD CREATOR
    board_file_creator::start_board_creator();
    return 1;
}
