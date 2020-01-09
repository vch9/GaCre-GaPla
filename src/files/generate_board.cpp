
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
          else if(c=='o'){
            e = new Trap(g, i, j);
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



void add_to_elems(map<std::pair<int, int>, Elem *> &elems, Elem *e);
void remove_from_elems(map<std::pair<int, int>, Elem *> &elems, int i, int j);
void generateWalls(Game_endless *pGame, Board *pBoard, map<std::pair<int, int>, Elem *> &elems);
void recDivision(Game *game, Board *board, int i_top, int i_bottom, int j_left, int j_right, int obstacleRate,
                map<std::pair<int, int>,  Elem *> &elems);
void generateElems(Game_endless *pEndless, Board *pBoard, map<std::pair<int, int>, Elem *> &elems);
pair<pair<int, int>, pair<int, int>>
generateDoors(Game_endless *g, Board *board, map<std::pair<int, int>, Elem *> &elems, int obstacleRate);

Board* GenerateBoard::createRandomBoard(Game_endless *g, int currentFloor) {
    enum room_size{
        BIG, NORMAL, TINY
    };
    enum room_type{
        LOOT, CLASSIC
    };

    Board * board;

    /* Each size probabilities are equally distributed (1/3)*/
    auto size = static_cast<room_size>((currentFloor + std::rand() ) % TINY);

    switch (size){
        case BIG:
            board = new Board(20 + (rand() % 5),20 + (rand() % 5));
            break;
        case NORMAL:
            board = new Board(10 + (rand() % 5),10 + (rand() % 5));
            break;
        case TINY:
            board = new Board(7 + (rand() % 3),7 + (rand() % 3));
            break;
    }
    std::map<std::pair<int,int>,Elem*> elems ;

    for (int i = 0; i < board->getLines(); ++i) {
        for (int j = 0; j < board->getCols(); ++j) {
            Elem* e = nullptr;
            board->setCell(i,j,new Cell(e));
        }
    }

    pair<pair<int,int>,pair<int,int>> door_coord;

    generateWalls(g, board, elems);

    door_coord = generateDoors(g, board, elems, 1);

    generateElems(g, board, elems);
    /*Filling the board*/
    for (auto const e : elems){
        auto coord = e.first;
        Elem * el = e.second;
        if(el) {
            board->addElem(el);
        }
        board->setElemOnCell(coord.first,coord.second,el);
    }

    return board;
}

void add_to_elems(map<std::pair<int, int>, Elem *> &elems, Elem *e) {
    int start_i(e->getPosI()), start_j(e->getPosJ());
    if(elems.find({start_i,start_j})!=elems.end()){
        elems.erase({start_i,start_j});
    }
    elems.insert({make_pair(start_i,start_j),e});
}


void remove_from_elems(map<std::pair<int, int>, Elem *> &elems, int i, int j) {
    elems.erase({i,j});
}
void recDivision(Game *game, Board *board, int i_top, int i_bottom, int j_left, int j_right, int obstacleRate,
                 map<std::pair<int, int>,  Elem *> &elems) {
    if((i_bottom-i_top) <2 || (j_right-j_left) <2) return;

    int verticalDivision = rand()%(j_right-j_left + 1) + j_left;
    int horizontalDivision = rand()%(i_bottom-i_top + 1) + i_top;

    /*Drawing walls*/
    if(rand()% obstacleRate == 0) {
        for (int j = j_left; j < j_right+1; ++j) {
            Elem* e = (rand()% 5 == 0) ? (Elem*)(new Trap(game, horizontalDivision,j) ): (Elem*)(new Wall(game, horizontalDivision,j));
            add_to_elems(elems,e);
        }
        for (int i = i_top; i < i_bottom+1; ++i) {
            Elem* e = (rand()% 5 == 0) ? (Elem*)(new Trap(game, i,verticalDivision) ): (Elem*)(new Wall(game, i,verticalDivision));
            add_to_elems(elems,e);
        }
    }

    /*Making holes*/
    int iHoleCoord = rand()%(i_bottom-i_top + 1) + i_top;
    {
        remove_from_elems(elems,iHoleCoord,verticalDivision);
        remove_from_elems(elems,iHoleCoord+1,verticalDivision);
        remove_from_elems(elems,iHoleCoord-1,verticalDivision);
    }
    int jHoleCoord = rand()%(j_right-j_left + 1) + j_left;
    {
        remove_from_elems(elems,horizontalDivision,jHoleCoord);
        remove_from_elems(elems,horizontalDivision,jHoleCoord+1);
        remove_from_elems(elems,horizontalDivision,jHoleCoord-1);
    }

    recDivision(game, board, i_top, horizontalDivision, j_left, verticalDivision, obstacleRate,elems);
    recDivision(game, board, i_top, horizontalDivision, verticalDivision, j_right, obstacleRate,elems);

    recDivision(game, board, horizontalDivision, i_bottom, j_left, verticalDivision, obstacleRate,
                elems);
    recDivision(game, board, horizontalDivision, i_bottom, verticalDivision, j_right, obstacleRate,
                elems);
}
void generateWalls(Game_endless *pGame, Board *pBoard, map<std::pair<int, int>, Elem *> &elems) {
    Game* game = (Game*) pGame;

    elems.clear();
    recDivision(game, pBoard, 1, pBoard->getLines() - 2, 1, pBoard->getCols() - 2, 2, elems);
    for (int i = 0; i < pBoard->getLines(); ++i) {
        for (int j = 0; j < pBoard->getCols(); ++j) {
            bool is_on_edge = (i == pBoard->getLines() - 1 || j == pBoard->getCols() - 1 || i == 0 || j == 0);
            if (is_on_edge) {
                Wall *w = new Wall(game, i, j);
                add_to_elems(elems, w);
            }
        }
    }


}

void generateElems(Game_endless *pEndless, Board *pBoard, map<std::pair<int, int>, Elem *> &elems) {
    /*Adjust the difficulty in fuction of the current floor number*/

    int monsterNb = (pBoard->getCols()*pBoard->getLines())/200 + pEndless->getCurrentFloor() + (rand()%2);
    int arrowsNb = (pBoard->getCols()*pBoard->getLines())/50 - pEndless->getCurrentFloor()/2 + (rand()%2);
    int diamondNb = 1 + rand() % 3;
    int chargeNb = rand()%3;
    int i(0), j(0);
    while(monsterNb>0){
//       We create a safe area around the player at the top
        i = rand()%(pBoard->getLines()-1-3 + 1) + 3;
        j = rand()%(pBoard->getCols()-1 - 1)+1;

        if(elems.find({i,j}) == elems.end()){
            add_to_elems(elems,new Monster((Game*)pEndless,i,j));
            --monsterNb;
        }
    }
    while(arrowsNb>0){
//       We create a safe area around the player at the top
        i = rand()%(pBoard->getLines()-1-2 + 1) + 2;
        j = rand()%(pBoard->getCols()-1 - 1)+1;

        if(elems.find({i,j}) == elems.end()){
            add_to_elems(elems,new Quiver((Game*)pEndless,i,j));
            --arrowsNb;
        }
    }
    while(diamondNb > 0){
//       We create a safe area around the player at the top
        i = rand()%(pBoard->getLines()-1-4 + 1) + 4;
        j = rand()%(pBoard->getCols()-1 - 1)+1;

        if(elems.find({i,j}) == elems.end()){
            add_to_elems(elems, new Diamond((Game*)pEndless,i,j));
            --diamondNb;
        }
    }
    while(chargeNb>0){
//      Create a safe area around the player at the top
        i = rand()%(pBoard->getLines()-1-4 + 1) + 4;
        j = rand()%(pBoard->getCols()-1 - 1)+1;

        if(elems.find({i,j}) == elems.end()){
            add_to_elems(elems,new Charge((Game*)pEndless,i,j));
            --chargeNb;
        }
    }
}
pair<pair<int, int>, pair<int, int>>
generateDoors(Game_endless *g, Board *board, map<std::pair<int, int>, Elem *> &elems, int obstacleRate) {
    int start_i(0), start_j(board->getCols()/2);
    add_to_elems(elems, new Door((Game*)g, start_i,start_j, true ));

    int t = rand() % 3;
    int dest_i, dest_j;
    if(t == 0 ) {
        dest_i = board->getLines() - 1;
        dest_j = board->getCols() / 2;
    }
    else if (t == 1) {
        dest_i = board->getLines() / 2;
        dest_j = 0;
    }
    else {
        dest_i = board->getLines() / 2;
        dest_j = board->getCols() - 1;
    }
    Door *eDoor = new Door((Game *) g, dest_i, dest_j, false);
    add_to_elems(elems,eDoor);

    /*Create some space around the player and the destination*/
    for (int i = -4; i < 5; ++i) {
        for (int j = -4; j < 5; ++j) {
            if(i == 0 && j == 0) break;
            int new_dest_i = dest_i + i;
            int new_dest_j = dest_j + j;

            int new_start_i = start_i + i;
            int new_start_j = start_j + j;

            if(new_dest_i > 0 && new_dest_i < (board->getLines() - 2) && new_dest_j > 0 && new_dest_j < (board->getCols()-2))
                remove_from_elems(elems, new_dest_i, new_dest_j );
            if(new_start_i > 0 && new_start_i < (board->getLines() - 2) && new_start_j > 0 && new_start_j < (board->getCols()-2))
                remove_from_elems(elems, new_start_i, new_start_j );
        }
    }

    pair<int,int> start = {start_i,start_j};
    pair<int,int> dest = {dest_i,dest_j};
    return {start,dest};
}