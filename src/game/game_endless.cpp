
#include "game_endless.hpp"

Game_endless::Game_endless() : Game(){srand(seed);}

Game_endless::Game_endless(vector<Board*> boards) : Game(boards){srand(seed);}

Game_endless::Game_endless(int seed) : Game_endless()  {
    seed = int(seed);
    srand(seed);
}

void Game_endless::changeBoard(bool next){
    if(next) this->addBoard(GenerateBoard::createRandomBoard(this, ++currentFloor));

    Game::changeBoard(next);
}

int Game_endless::getSeed() {
    return seed;
}

unsigned int Game_endless::getCurrentFloor() {
    return currentFloor;
}

void Game_endless::incCurrentFloor() {
    ++currentFloor;
}

