
#ifndef GACRE_GAPLA_GAME_FILE_CREATOR_H
#define GACRE_GAPLA_GAME_FILE_CREATOR_H


class game_file_creator {
public:
    static bool check_board(ifstream& stream);

//    this method write on "out" all the boards content in "board_file_name" separate by a '#' character
//    "out" must end with ".game"
    static void create_game_file(string out, vector<string> board_file_name);
};


#endif //GACRE_GAPLA_GAME_FILE_CREATOR_H
