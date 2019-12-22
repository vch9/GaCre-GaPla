


#include "game_file_creator.hpp"

void game_file_creator::create_game_file(string out, vector<string> board_file_name) {
    int board_counter(0);
    ofstream dst(out, ios::out);

//    checking file extension
    if(!std::regex_match(out,std::regex{".*\\.game"})){
        cout << "Game file must end with \".game\"" <<endl;
        return;
    }

    for( string board_name : board_file_name){
        ifstream src(board_name, ios::in);

        if(check_board(src)){
            dst << '#' << endl << board_name <<endl;
            cout << "board " << std::to_string(board_counter++) << " added" << endl;
        }
        else {
            cout << "error with board " << std::to_string(board_counter)<< endl;
        }
    }
    dst << "$ Leaderboard" << endl;
    for(int i=0; i<5; i++)
      dst << "$ N/A" << endl;
    
    cout << endl<<"Success !" << endl <<"Game created at " << out << endl;

    dst.close();
}
void update_item_count(string s, int& exit_door, int& start_door, int& diams){
    start_door += std::count(s.begin(), s.end(),'+');
    exit_door += std::count(s.begin(), s.end(),'-');
    diams += std::count(s.begin(), s.end(),'$');

}

bool game_file_creator::check_board(ifstream& stream) {
    int exit_door_count(0),start_door_count(0), diams_count(0);
    long unsigned int  width(0);

    string buf;

//    the edge lines must be fill of X with one or zero door
    std::regex edge_pattern{"(X*(\\+|-){0,2}X*)"};
    std::regex middle_pattern{"(X|\\+|-)( |$|s|X|\\*)*(X|\\+|-)"};

//    checking top line
    getline(stream, buf);
    if(!std::regex_match(buf, edge_pattern)) return false;
    update_item_count(buf, exit_door_count, start_door_count, diams_count);
//    determining board height and width
    width = buf.length();

//    checking matrix center
    while( getline(stream, buf)){
        if(buf.length() != width && !std::regex_match(buf, middle_pattern)) return false;
        update_item_count(buf, exit_door_count, start_door_count, diams_count);
    }

//    checking bottom line
    getline(stream, buf);
    if(buf.length() != width && !std::regex_match(buf, edge_pattern)) return false;
    update_item_count(buf, exit_door_count, start_door_count, diams_count);

    stream.clear();
    stream.seekg(0, ios::beg);
    return exit_door_count ==1 && start_door_count == 1;// && diams_count <=1;
}
