//
// Created by benjamin on 08/12/2019.
//
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "board_file_creator.h"

using namespace std;

int main(int argc, char *argv[]){
    if ( argc < 2 ) {
        cerr << "missing parameter" << endl;
        return -1;
    }
    string board_name  = string(argv[1]);


    //    checking file extension
    if(!std::regex_match(board_name,std::regex{".*\\.board"})){
        cout<< "Board file must end with \".board\"" <<endl;
        return -1;
    }

    ofstream dst(board_name, ios::out);
    board_file_creator::start_board_creator(dst);

    cout<< board_name <<" created."<< endl;
}