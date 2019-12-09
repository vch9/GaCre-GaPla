#include <iostream>
#include <string>
#include <regex>
using namespace std;

#include "../game/game.hpp"
#include "../board/board.hpp"
#include "../files/generate_board.hpp"

bool fileExists(string path){
  if (FILE *file = fopen(path.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  } 
}

Board* createBoard(Game* g, string path){
  return GenerateBoard::createBoard(g, path);
}

void play(Game* g, vector<Board*> boards){
  Elem* player = new Player(g, 1, 100);
  for(int i=0; i<(int)boards.size(); i++){
    g->addBoard(boards.at(i));
  }
  g->setPlayer(player);
  g->play();
  delete(g);
  
}
void playGame(string game){
  game = "./games/"+game;
  if(!fileExists(game)){
    cerr << game << " does not exist" << endl;
    return;
  }
  Game* g = new Game();
  vector<Board*> boards;
  
  ifstream ifs;
  ifs.open (game, ifstream::in);

  char buf[256];
  string str = "";
  while(ifs.getline(buf, 256)){
    if(buf[0]!='#'){
      str = std::string(buf);
      boards.push_back(GenerateBoard::createBoard(g, str));
    }
  }
  play(g, boards);
  
}

void playBoard(string board){
  board = "./boards/"+board;
  if(!fileExists(board)){
    cerr << board << " does not exist" << endl;
    return;
  }
  Game* game = new Game();
  vector<Board*> boards;
  boards.push_back(GenerateBoard::createBoard(game, board));
  play(game, boards);
}

int main(int argc, char* argv[]){
  if(argc < 2){
    cerr << "missing parameter" << endl;
    return -1;
  }
  
  string arg1 = string(argv[1]);
  
  if(std::regex_match(arg1, std::regex{".*\\.game"})){
    playGame(arg1);
  }
  else if(std::regex_match(arg1, std::regex{".*\\.board"})){
    playBoard(arg1);
  }
  else{
    cerr << "unknown parameter" << endl;
    return -1;
  }
  
  return 0;
}
