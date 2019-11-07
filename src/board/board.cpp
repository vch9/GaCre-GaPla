#include "board.hpp"


Board::Board(const int l, const int c): lines(l), cols(c), actionnables_elems(){
    this->board = new Cell*[l*c];
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            Board::board[i*Board::cols+j] = nullptr;
        }
    }
}

void Board::addActionnableElem(Elem* e){
    Board::actionnables_elems.push_back(e);
}

void Board::setCell(const int i, const int j, Cell* c){
    Board::board[i*Board::cols+j] = c;
}

void Board::setElemOnCell(const int i, const int j, Elem* e){
    Board::board[i*Board::cols+j]->setElem(e);
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

void Board::move(int dest_i, int dest_j, Elem* e){
    Board::board[e->getPosI()*Board::cols+e->getPosJ()]->setElem(nullptr);
    Board::board[dest_i*Board::cols+dest_j]->setElem(e);
}

void Board::elem_move(Elem* e, int dest_i, int dest_j){
    /* Inside board */
    if(dest_i>=0 || dest_i<Board::lines || dest_j>=0 || dest_j<Board::cols){
        Elem* onDest = Board::board[dest_i*Board::cols+dest_j]->getElem();

        /* If an elem is already on the cell we want to move e */
        if(onDest!=nullptr){
            onDest->onCollision(e);
            /* If onDest is not blockable */
            if(!onDest->blockable()){
                /* e overplace onDest */
                // delete(onDest);

                move(dest_i, dest_j, e);
            }
        }
        /* Else, we move to the cell */
        else{
            move(dest_i, dest_j, e);
        }
    }
}