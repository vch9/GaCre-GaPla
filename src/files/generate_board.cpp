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
            if(c=='X'){
                b->setCell(i, j, new Cell(i, j, new Wall(g)));
            }
            else if(c=='-'){
                b->setCell(i, j, new Cell(i, j, new Door(g)));
            }
            else if(c=='+'){
                b->setCell(i, j, new Cell(i, j, new Door(g)));
            }
            else if(c=='$'){
                b->setCell(i, j, new Cell(i, j, new Diamond(g)));
            }
            else if(c=='*'){
                b->setCell(i, j, new Cell(i, j, new Charge(g)));
            }
            else if(c=='s'){
                b->setCell(i, j, new Cell(i, j, new Monster(g, i, j)));
            }
            else{
                b->setCell(i, j, new Cell(i, j, nullptr));
            }
            j++;
        }
    }

    b->print();

    return b;
}
