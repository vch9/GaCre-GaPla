#include "board_file_creator.hpp"


#define MAX_HEIGHT 50
#define MAX_WIDTH 50

void print_tab (WINDOW *,std::vector<std::vector<char>> tab,int i, int j);

phase operator++(phase& p ){
    switch (p){
        case START_DOOR:
            return p=  EXIT_DOOR;
        default:
            return p = OTHER;
    }
}
void board_file_creator::start_board_creator(std::ofstream& file_stream) {
//    NCURSES CONFIGURATION
    initscr();

    int height(0), width(0);
    char s_height [200];
    char s_width [200] ;
    while(( height < 1 || width <1 || height > MAX_HEIGHT || width > MAX_WIDTH)){
        clear();
        printw( "BOARD CREATOR\n\n");
        printw( "Board height ?\n");
        refresh();
        getstr(s_height);
        clear();
        printw( "BOARD CREATOR\n\n");
        printw( "Board width ?\n");
        refresh();
        getstr(s_width);

        std::string str_height(s_height), str_width(s_width);
        try {
            height = std::stoi(str_height);
            width = std::stoi(str_width);

        }catch(std::exception const & e) {
            refresh();
        };
    }
//    initializing default board
    std::vector<char> row(width, 'X');
    std::vector<std::vector<char>> board(height, row );
    for (int k = 1; k < height-1; ++k) {
        for (int i = 1; i < width - 1; ++i) {
            board[k][i] = ' ';
        }
    }
    clear();
    refresh();


//    Start editing board
    noecho();
    cbreak();

    WINDOW * board_window ;
    WINDOW * command_window ;

    board_window = newwin(height, width, 3, 10);
    command_window = newwin(12, 23, width+3+1, 10);

    wrefresh(command_window);
    phase currentPhase = START_DOOR;
    print_command_board(command_window,currentPhase);

    int i(0), j(0);
    int exit_i(0), exit_j(0), start_i(0), start_j(0);
    print_tab(board_window, board, i, j);
    bool finished(false);
    keypad(board_window, TRUE);
    while(!finished){
        bool is_on_corner = (i == 0 && j == 0) || (i== height -1 && j == width-1) || (i == 0 && j == width-1) || (i== height -1 && j == 0);
        bool is_on_edge = (i == height - 1 || j == width - 1 || i == 0 || j == 0);
        bool is_overlap_doors = (i == exit_i && j == exit_j) || (i == start_i && j == start_j);
        int ch = wgetch(board_window);
//      Navigation :
        switch(ch) {
            case KEY_UP:
                i--;
                break;
            case KEY_DOWN:
                i++;
                break;
            case KEY_LEFT:
                j--;
                break;
            case KEY_RIGHT:
                j++;
                break;
            case '\n':

                switch(currentPhase) {
                    case START_DOOR:
                        if (is_on_edge && !is_on_corner) {
                            board[i][j] = '+';
                            start_i = i;
                            start_j = j;
                            ++currentPhase;
                        }
                        break;
                    case EXIT_DOOR:
                        if (is_on_edge && (i!= start_i || j!= start_j) &&  !is_on_corner) {
                            board[i][j] = '-';
                            exit_i = i;
                            exit_j = j;
                            ++currentPhase;
                        }
                        break;
                    case OTHER:
                        break;
                }
                break;


        }
//        Editing board :
        switch(currentPhase){
            case OTHER:
                if(!is_overlap_doors && !is_on_edge)
                switch (ch){
                    case  'd':
                        board[i][j] = '$';
                        break;
                    case 's':
                        board[i][j] = 's';
                        break;
                    case '*':
                        board[i][j] = '*';
                        break;
                    case 'x':
                        board[i][j] = 'X';
                        break;
                    case 'e':
                        board[i][j] = ' ';
                        break;
                    case 'q':
                        finished = true;
                        break;
                    case ':':
                        board[i][j] = ':';
                        break
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        if(i >= height) i = height-1;
        if(j >= width) j = width-1;
        if(i< 0) i = 0;
        if(j< 0) j = 0;
        wclear(board_window);
        wclear(command_window);
        print_command_board(command_window,currentPhase);
        print_tab(board_window, board , i , j);
    }
    endwin();
    write_board(file_stream, board);
}

void board_file_creator::print_command_board(WINDOW *window, phase phase) {
    mvwprintw(window,1,1,"Move the cursor with \n ARROWS");
    switch(phase){
        case START_DOOR:
            mvwprintw(window,4,1,"Place the front door\n ENTER to confirm");
            break;
        case EXIT_DOOR:
            mvwprintw(window,4,1,"Place the exit door\n ENTER to confirm");
            break;
        case OTHER:
            mvwprintw(window,4,1,"Place items\n"
                           " D -> DIAMOND\n"
                           " S -> MONSTER\n"
                           " * -> TELEPORTER\n"
                           " X -> WALL\n"
                           " E -> VOID\n"
                           " Q to close the editor"
                           );

    }
    box(window, 0,0);
    wrefresh(window);
}

void board_file_creator::write_board(std::ofstream &file_stream, std::vector<std::vector<char>> board) {
    for (const std::vector<char> &line : board) {
        std::string _line(line.begin(),line.end());
        file_stream << _line<< std::endl;;
    }
}

void print_tab (WINDOW * window,std::vector<std::vector<char>> tab,int i_highlight, int j_highlight){
    int height(tab.size()), width(tab[0].size());
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(i == i_highlight && j == j_highlight){
                mvwaddch(window,i,j,tab[i][j]|A_REVERSE);
            }else {
                mvwaddch(window,i,j,tab[i][j]);
            }
        }
    }
    wrefresh(window);
}
