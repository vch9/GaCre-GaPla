

#ifndef GACRE_GAPLA_GAME_ENDLESS_HPP
#define GACRE_GAPLA_GAME_ENDLESS_HPP
#include <ctime>
#include "game.hpp"
#include "../files/generate_board.hpp"

class Game_endless : Game{
private:
    int seed = std::time(0);
    unsigned int currentFloor = 0;
public :
    Game_endless();

    Game_endless(vector<Board*> boards);

    Game_endless(int seed);


    int getSeed();

    /* Generate a brand new board for the next level */
    virtual void changeBoard(bool next) override;

    unsigned int getCurrentFloor();

    void incCurrentFloor();
};


#endif //GACRE_GAPLA_GAME_ENDLESS_HPP
