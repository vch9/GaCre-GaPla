#ifndef GAME
#define GAME

#include <vector>
#include <iostream>
#include "../board/board.hpp"
#include "../elems/door.hpp"
#include "../elems/wall.hpp"

using namespace std;

class Board;
class Elem;

class Game{
    private:
        vector<Board*> boards;
        int current_board;
        Elem* player;

        /* return true if the game is over (user played all boards) */
        bool finish();

        /* return true if the board is over */
        bool boardOver();

        /* Print the actual state of the game */
        void print();

        /* Call takeAction on every elems on the current board played */
        void nextTurn();

        /* Decide where the player will spawn, based on the doors */
        void setPlayerSpawn(bool entry);

        /* Remove the spawning door if we're on the first board */
        void remove_door();

    public:
        /* Constructors */
        Game();
        Game(vector<Board*> boards);

        /* Destructors */
        virtual ~Game();

        /* Setters */
        void addBoard(Board*);
        void setPlayer(Elem*);

        /* Getters */    
        Board* getCurrentBoard();
        Elem* getPlayer();

        /* Methods */

        /* Start the game, calls itself recursively until the game is over */
        void play();

        /* Open all doors (when the player collects a diamond) */
        void openDoors();

        /* If next is true, we go to the next board, else we go to the previous one */
        void changeBoard(bool next);
};

#endif
