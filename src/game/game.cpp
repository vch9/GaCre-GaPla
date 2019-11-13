#include "game.hpp"

/* Constructors */
Game::Game(): boards(), current_board(0){

}

Game::Game(vector<Board*> boards){
  Game::boards=boards;
  Game::current_board = 0;
}

/* Setters */
void Game::addBoard(Board* b){
    Game::boards.push_back(b);
}

void Game::setPlayer(Elem* e){
  Game::player = e;
}

/* Getters */
Board* Game::getCurrentBoard(){
  if(Game::current_board>=0 && Game::current_board<(int)Game::boards.size()){
    return Game::boards.at(Game::current_board);
  }
  return nullptr;
}

/* Methods */

/* private */
bool Game::finish(){
  return Game::current_board>=(int)Game::boards.size();
}

bool Game::boardOver(){
  return false;
}

void Game::print(){
  if(Game::current_board>=0 && Game::current_board<(int)Game::boards.size()){
    Game::boards.at(Game::current_board)->print();
  }
  cout << "Niveau " << Game::current_board+1 << endl;
  Game::player->print();

}

void Game::nextTurn() {
  if(Game::current_board>=0 && Game::current_board<(int)Game::boards.size()){
    for (Elem* e : boards.at(current_board)->getElems()){
      e->takeAction();
    }
  }
}

void Game::setPlayerSpawn(bool entry){
  Board* b = Game::boards.at(Game::current_board);
  for (Elem* e: b->getElems()){
    if(e->getSymb()=="-" || e->getSymb()=="+"){
      Door* door = (Door*) e;

      /* Algorithm to find the spawn position depending on the entry door or exit door */
      if( (entry && !door->isDoorExit()) || (!entry && door->isDoorExit()) ){
        int lines = b->getLines();
        int dest_i, dest_j;
        if(door->getPosI()==0){
            /* 
            XX+XXX
            X J  X
            XXXXXX
            */
            dest_i = 1;
            dest_j = door->getPosJ();
        }
        else if(door->getPosJ()==0){
            /* 
            XXXXXX
            +J   X
            XXXXXX
            */
            dest_j = 1;
            dest_i = door->getPosI();
        }
        else if(door->getPosI() == lines-1){
            /*
            XXXXXX
            X J  X
            XX+XXX 
            */
            
            dest_i = lines - 2;
            dest_j = door->getPosJ();
        }
        else{
            /*
            XXXXXX
            X   J+
            xXXXXX
            */
            dest_i = door->getPosI();
            dest_j = door->getPosJ()-2;
        }
        Game::player->setPosI(dest_i);
        Game::player->setPosJ(dest_j);
      }
    }
  }
  b->setElemOnCell(Game::player->getPosI(), Game::player->getPosJ(), Game::player);
}

void Game::remove_door(){
  int pos_i, pos_j;
  Door* door;
  if(Game::current_board>=0 && Game::current_board<(int)Game::boards.size()){
    for (Elem* e : boards.at(current_board)->getElems()){
      if(e->getSymb()=="-"){
        door = (Door*) e;
        if(!door->isDoorExit()){ /* Opening door */
          pos_i = door->getPosI();
          pos_j = door->getPosJ();
        }
      }
    }
  }
  // delete(door);
  Game::boards.at(0)->setElemOnCell(pos_i, pos_j, new Wall(this, pos_i, pos_j));
}

/* public */
void Game::play(){
  if(Game::current_board>=(int)Game::boards.size()){
    cout << "No more boards to play" << endl;
  }
  setPlayerSpawn(true);
  /* we remove the entry door on the first board */
  remove_door();

  /* while !finish iterates on the boards */
  while(!finish()){

    Game::boards.at(Game::current_board)->addElem(Game::player);

    /* while !boardOver iterates on the board */
    int aux_board = Game::current_board;
    while(aux_board==Game::current_board){
      print();
      nextTurn();
    }

  }

  cout << "Congratulations you beat the game" << endl;
}

void Game::openDoors(){
   Board* b = Game::boards.at(Game::current_board);
  for (Elem* e: b->getElems()){
    if(e->getSymb()=="-"){
      Door* door = (Door*) e;
      door->open();
    }
  }
}

void Game::changeBoard(bool next){
  /* We remove the player from board->elems() */
  Game::boards.at(Game::current_board)->removeFromElems(Game::player);
  
  /* We take back the player from the current board */
  Game::boards.at(Game::current_board)->setElemOnCell(Game::player->getPosI(), Game::player->getPosJ(), nullptr);
  

  if(next){
    Game::current_board++;
    if(Game::current_board<(int)Game::boards.size()){
      setPlayerSpawn(true);
    }
  }
  else{
    Game::current_board--;
    setPlayerSpawn(false);
  }
}