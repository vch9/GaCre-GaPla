

#include <board.hpp>
#include<fstream>
#include<regex>
#include "game_file_creator.h"

void game_file_creator::create_game_file(string out, vector<string> board_file_name) {
    ofstream dst(out, ios::out);

    for( string board_name : board_file_name){
        ifstream src("name", ios::in);

        if(check_board(src)){
            dst << '#' << endl << src.rdbuf();
        }

    }
}
void update_item_count(string s, int& exit_door, int& start_door, int& diams){
    start_door += std::count(s.begin(), s.end(),'+');
    exit_door += std::count(s.begin(), s.end(),'-');
    diams += std::count(s.begin(), s.end(),'$');

}

bool game_file_creator::check_board(ifstream& stream) {
    int exit_door_count(0),start_door_count(0), diams_count(0);
    string buf;

//    determining board heigth and board
    int height, width;

    std::regex edge_pattern{"(X*(\\+|-)?X*)"};
    std::regex middle_pattern{"(X|\\+|-)( |$|s|X|\\*)*(X|\\+|-)"};

//    the first line must be a wall with one or zero door
    getline(stream, buf);
    if(!std::regex_match(buf, edge_pattern)) return false;
    update_item_count(buf, exit_door_count, start_door_count, diams_count);
    width = buf.length();

    while( getline(stream, buf)){
        if(buf.length() != width && std::regex_match(buf, middle_pattern)) return false;
        update_item_count(buf, exit_door_count, start_door_count, diams_count);
    }


    getline(stream, buf);
    if(buf.length() != width && !std::regex_match(buf, edge_pattern)) return false;
    update_item_count(buf, exit_door_count, start_door_count, diams_count);

    stream.seekg(0, ios::beg);
    return exit_door_count ==1 && start_door_count == 1 && diams_count <=1;
}
