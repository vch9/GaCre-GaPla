
#ifndef GACRE_GAPLA_GAME_FILE_CREATOR_H
#define GACRE_GAPLA_GAME_FILE_CREATOR_H

#include <board.hpp>
#include<fstream>
#include<regex>

class game_file_creator {
public:
//    this method write on "out" all the boards content in "board_file_name" separate by #
//    "string out" must end with .game
    static void create_game_file(string out, vector<string> board_file_name);

    static bool check_board(ifstream& stream);
};


#endif //GACRE_GAPLA_GAME_FILE_CREATOR_H
