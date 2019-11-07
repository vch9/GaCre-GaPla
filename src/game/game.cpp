#include "game.hpp"

Game::Game(): boards(), current_board(0){

}

void Game::add_board(Board* b){
    Game::boards.push_back(b);
}

void Game::print(){
    Game::boards.at(Game::current_board)->print();
}

void Game::elem_move(Elem* e, int dest_i, int dest_j){
    Game::boards.at(Game::current_board)->elem_move(e, dest_i, dest_j);
}