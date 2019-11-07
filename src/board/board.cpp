#include "board.hpp"


Board::Board(const int l, const int c): lines(l), cols(c){
    this->board = new Cell*[l*c];
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            Board::board[i*Board::cols+j] = nullptr;
        }
    }
}

void Board::setCell(const int i, const int j, Cell* c){
    Board::board[i*Board::cols+j] = c;
}

void Board::print(){
    for(int i=0; i<Board::lines; i++){
        for(int j=0; j<Board::cols; j++){
            if(Board::board[i*Board::cols+j]==nullptr){
                cout << "_";
            }
            else{
                cout << *Board::getCell(i, j);
            }
        }
        cout << endl;
    }
}

Cell* Board::getCell(const int i, const int j){
    return Board::board[i*Board::cols+j];
}