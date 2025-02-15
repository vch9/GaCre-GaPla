#include "board.hpp"


Board::Board(const int l, const int c): lines(l), cols(c), elems(){
    this->board = new Cell*[l*c];
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            Board::board[i*Board::cols+j] = nullptr;
        }
    }
}

Board::~Board(){
    for(int i=0; i<Board::lines; i++){
        for(int j=0; j<Board::cols; j++){
            delete(Board::board[i*Board::cols+j]);
            Board::board[i*Board::cols+j] = nullptr;
        }
    }
    free(Board::board);
    for(int i=0; i<(int)Board::elems.size(); i++){
        delete(Board::elems.at(i));
    }

}
/* Getters */
int Board::getLines(){
  return Board::lines;
}

int Board::getCols(){
  return Board::cols;
}

Cell* Board::getCell(const int i, const int j){
    return Board::board[i*Board::cols+j];
}

vector<Elem *> Board::getElems() {
    return elems;
}

/* Setters */
void Board::addElem(Elem* e){
    Board::elems.push_back(e);
}

void Board::setCell(const int i, const int j, Cell* c){
    Board::board[i*Board::cols+j] = c;
}

void Board::setElemOnCell(const int i, const int j, Elem* e){
    Board::board[i*Board::cols+j]->setElem(e);
}

void Board::removeFromElems(Elem* e ){
    int offset = 0;
    for (int i=0; i<(int)Board::elems.size(); i++){
        Elem* aux = Board::elems.at(i);
        if(aux->getPosI()==e->getPosI() && aux->getPosJ()==e->getPosJ()){
            offset = i;
            break;
        }
    }
    Board::elems.erase(Board::elems.begin()+offset);
}

/* Methods */
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

void Board::move(int dest_i, int dest_j, Elem* e){
    Board::board[e->getPosI()*Board::cols+e->getPosJ()]->setElem(nullptr);
    Board::board[dest_i*Board::cols+dest_j]->setElem(e);
    e->setPosI(dest_i);
    e->setPosJ(dest_j);
}
