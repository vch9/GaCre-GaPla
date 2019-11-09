#include "game.hpp"

Game::Game(): boards(), current_board(0){

}

void Game::add_board(Board* b){
    Game::boards.push_back(b);
}

void Game::print(){
    Game::boards.at(Game::current_board)->print();
}

void Game::nextTurn() {
    for (Elem* e : boards.at(current_board)->getElems()){
        e->takeAction();
    }
}

Board* Game::getCurrentBoard(){
  return Game::boards.at(Game::current_board);
}
