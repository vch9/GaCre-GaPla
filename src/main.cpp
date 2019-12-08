using namespace std;
#include <iostream>
#include "game/game.hpp"
#include "board/board.hpp"
#include "files/generate_board.hpp"
#include "actions/health.hpp"

int main(){
    string path1 = "../files/example.board";
    string path2 = "../files/example2.board";

    Game* game = new Game();

    Board* b1 = GenerateBoard::createBoard(game, path1);
    Board* b2 = GenerateBoard::createBoard(game, path2);

    Elem* player = new Player(game, 1, 100);

    game->addBoard(b1);
    game->addBoard(b2);

    game->setPlayer(player);

    game->play();

    delete(game);
}
