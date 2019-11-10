#include "game.hpp"

Game::Game(): boards(), current_board(0){

}

void Game::add_board(Board* b){
    Game::boards.push_back(b);
}

void Game::print(){
  if(Game::current_board>0 && Game::current_board<(int)Game::boards.size()){
    Game::boards.at(Game::current_board)->print();
  }
}

void Game::nextTurn() {
  if(Game::current_board>0 && Game::current_board<(int)Game::boards.size()){
    for (Elem* e : boards.at(current_board)->getElems()){
      e->takeAction();
    }
  }
}

Board* Game::getCurrentBoard(){
  if(Game::current_board>0 && Game::current_board<(int)Game::boards.size()){
    return Game::boards.at(Game::current_board);
  }
  return nullptr;
}
