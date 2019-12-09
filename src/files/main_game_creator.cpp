//
// Created by benjamin on 08/12/2019.
//


#include "board_file_creator.hpp"
#include "game_file_creator.hpp"
using namespace std;

void create_board(int argc, char **argv);

void create_game(int argc, char **argv);

int main(int argc, char *argv[]){


    if ( argc < 2 ) {
        cerr << "missing parameter" << endl;
        return -1;
    }
    string arg1  = string(argv[1]);
    if(std::regex_match(arg1,std::regex{".*\\.game"})){
        create_game(argc ,argv);
    }
    else  if(std::regex_match(arg1,std::regex{".*\\.board"})){
        create_board(argc, argv);
    }
    else {
        cerr << "unknown parameter" << endl;
        return -1;
    }


}

void create_game(int argc, char **argv) {
    vector<string> boards{};
    for (int i = 2; i < argc; ++i) {
        boards.emplace_back(argv[i]);
    }


    const string& out(argv[1]);

    game_file_creator::create_game_file(out , boards);


}

void create_board(int argc, char **argv) {
    string board_name  = string(argv[1]);


    //    checking file extension
    if(!std::regex_match(board_name,std::regex{".*\\.board"})){
        cout<< "Board file must end with \".board\"" <<endl;
        return;
    }

    ofstream dst(board_name, ios::out);
    board_file_creator::start_board_creator(dst);

    cout<< board_name <<" created."<< endl;
}
