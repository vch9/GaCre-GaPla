#include "view.hpp"

void View::init(){
  initscr();
}

void View::printBoard(Board* b){
  for(int i=0; i<b->getLines(); i++){
    for(int j=0; j<b->getCols(); j++){
      move(i, j);
      Cell* c = b->getCell(i, j);
      Elem* e = c->getElem();
      if(e!=nullptr){
        char c = e->getSymb()[0];
        addch(c);
      }
    }
  }
  printw("\n");
}

void View::clear_window(){
  clear();
}

void View::print(string message){
  /* convert string to char[] */
  char m[message.size() + 1];
  strcpy(m, message.c_str());

  printw(m);
}

void View::close(Board* b, string message){
  clear();

  printBoard(b);
  print(message);

  getch();
  endwin();
}
