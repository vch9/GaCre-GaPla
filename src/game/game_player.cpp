#include <iostream>
#include <string>
#include <regex>
#include <tuple>

#include "../game/game.hpp"
#include "../board/board.hpp"
#include "../files/generate_board.hpp"
#include "game_endless.hpp"
using namespace std;

string askForName();

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

int play(Game* g, vector<Board*> boards, string score){
  Elem* player = new Player(g, 1, 100);
  for(int i=0; i<(int)boards.size(); i++){
    g->addBoard(boards.at(i));
  }
  g->setPlayer(player);
  int sc = g->play(score);
  delete(g);
  return sc;
  
}

vector<pair<string, int>> convert_scores_to_vec(string scores){
  vector<pair<string, int>> vects;

  std::istringstream ss(scores);
  std::string token;

  vector<string> tokens;
  while(std::getline(ss, token, '\n')){
    tokens.push_back(token);
  }

  
  for(int i=1; i<6; i++){
    std::istringstream ss(tokens.at(i));
    std::getline(ss, token, ':');
    string id = token;
    std::getline(ss, token, '\n');
    if(token[0]!='$'){
      vects.push_back(make_pair(id, std::stoi(token)));
    }else{
      vects.push_back(make_pair("N/A", -1));
    }
  }
  
  return vects;
}

vector<pair<string, int>> insert_scores(vector<pair<string, int>> vects, int new_score, string name){
  int k = 4;
  while(new_score > vects.at(k).second){
    k--;
    if (k<0){
      break;
    }
  }

  if(k!=4){
    k++;
    string tmp_id = vects.at(k).first;
    int tmp_i = vects.at(k).second;
    vects.at(k) = make_pair("$ "+name, new_score);
    for(int i=k+1; i<5; i++){
      string tmp2_id = vects.at(i).first;
      int tmp2_i = vects.at(i).second;
      vects.at(i) = make_pair(tmp_id, tmp_i);
      tmp_id = tmp2_id;
      tmp_i = tmp2_i;
    }
  }

  return vects;
}

string convert_vec_to_scores(vector<pair<string, int>> vects){
  string score = "$ Leaderboard\n";
  for(int i=0; i<5; i++){
    if(vects.at(i).first[0] == '$'){
      score += vects.at(i).first + ":" + to_string(vects.at(i).second);
    } else {
      score += "$ "+vects.at(i).first;
    }
    if(i!=4){
      score += "\n";
    }
  }
  return score;
}

void update_score(string game, string scores, int new_score, string pseudo){
  vector<pair<string, int>> vec = convert_scores_to_vec(scores);
  vec = insert_scores(vec, new_score, pseudo);
  scores = convert_vec_to_scores(vec);

  string file_text = "";
  ifstream ifs;
  ifs.open(game, ifstream::in);
  char buf[256];
  bool first = true;
  while(ifs.getline(buf, 256)){
    if(buf[0]=='$'){
      file_text += "\n";
      break;
    }
    if(!first){
      file_text += "\n";
    }
    first = false;
    file_text += std::string(buf);
    
  }
  
  ofstream outfile;
  file_text += scores;
  
  outfile.open(game);
  outfile << file_text << endl;
  
  outfile.close();
}

void playGame(string game){
  game = "./games/"+game;
  if(!fileExists(game)){
    cerr << game << " does not exist" << endl;
    return;
  }

  string pseudo = askForName();

  Game* g = new Game();
  vector<Board*> boards;
  
  ifstream ifs;
  ifs.open (game, ifstream::in);

  char buf[256];
  string str;

  string scores = "";
  
  while(ifs.getline(buf, 256)){
    if(buf[0]!='#' && buf[0]!='$'){
      str = std::string(buf);
      boards.push_back(GenerateBoard::createBoard(g, str));
    }
    if(buf[0]=='$'){
      scores += std::string(buf) + "\n";
    }
  }
  int new_score = play(g, boards, scores);

  update_score(game, scores, new_score, pseudo);

  ifs.close();
  
}

string askForName() {
    cout << "Enter your name: " << endl;
    string pseudo;
    getline(cin, pseudo);
    return pseudo;
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
  play(game, boards, "");
}

void playEndless(string s_seed) {
    Game_endless* game;
    if(s_seed.compare("") != 0){
        try {

            int seed = std::stoi(s_seed);
            game = new Game_endless(seed);
        }catch(std::invalid_argument const &e){
            std::cerr << "Bad input. The seed must be a number"<<endl;
        }
    } else  game = new Game_endless();

    Board * first_board = GenerateBoard::createRandomBoard(game, 0);

    vector<Board*> boards;
    boards.push_back(first_board);


    play((Game*) game,boards , askForName());
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
  else if (arg1.compare("endless") == 0){
      if(argc > 2 ){
          playEndless(string(argv[2]));
      }
      playEndless("");
  }
  else{
    cerr << "unknown parameter" << endl;
    return -1;
  }
  
  return 0;
}
