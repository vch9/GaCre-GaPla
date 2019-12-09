#include "generate_board.hpp"

int GenerateBoard::getBoardLines(string path){
    ifstream ifs;
    ifs.open (path, ifstream::in);

    char lines[256];
    int acc = 0;

    while(ifs.getline(lines, 256, '\n')){
        acc++;
    }

    ifs.close();
    return acc;
}

int GenerateBoard::getBoardCols(string path){
    ifstream ifs;
    ifs.open (path, ifstream::in);

    char c;
    int acc = 0;

    while(ifs.get(c) &&  c!='\n'){
        acc++;
    }

    ifs.close();
    return acc;
}

Board* GenerateBoard::createBoard(Game* g, string path){
    int lines = GenerateBoard::getBoardLines(path);
    int cols = GenerateBoard::getBoardCols(path);
    Board* b = new Board(lines, cols);
    int i = 0, j = 0;
    char c;

    ifstream ifs;
    ifs.open (path, ifstream::in);

    while(ifs.get(c)){
        if(c=='\n'){
            i++;
            j=0;
        }
        else{
          Elem* e;
          if(c=='X'){
            e = new Wall(g, i, j);
          }
          else if(c=='-'){
            e = new Door(g, i, j, true);
          }
          else if(c=='+'){
            e = new Door(g, i, j, false);
          }
          else if(c==':'){
            e = new Quiver(g, i, j);
          }
          else if(c=='$'){
            e = new Diamond(g, i, j);
          }
          else if(c=='*'){
            e = new Charge(g, i, j);
          }
          else if(c=='s'){
            e = new Monster(g, i, j);
          }
          else{
            e = nullptr;
          }
          if(e){
            b->addElem(e);
          }
          b->setCell(i, j, new Cell(e));
          j++;
        }
    }

    return b;
}
