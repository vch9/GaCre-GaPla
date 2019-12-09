#include <iostream>
#include <string>
#include <regex>
using namespace std;

void play_game(string game){
}

void play_board(string board){
}

int main(int argc, char* argv[]){
  if(argc < 2){
    cerr << "missing parameter" << endl;
    return -1;
  }
  
  string arg1 = string(argv[1]);
  
  if(std::regex_match(arg1, std::regex{".*\\.game"})){
    play_game(arg1);
  }
  else if(std::regex_match(arg1, std::regex{".*\\.board"})){
    play_board(arg1);
  }
  else{
    cerr << "unknown parameter" << endl;
    return -1;
  }
  
  return 0;
}
