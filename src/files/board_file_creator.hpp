#ifndef GACRE_GAPLA_BOARD_FILE_CREATOR_HPP
#define GACRE_GAPLA_BOARD_FILE_CREATOR_HPP

#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum phase {
    START_DOOR, EXIT_DOOR, OTHER
};
class board_file_creator {
public:
    static void start_board_creator(std::ofstream& file_stream);

private:
    static void print_command_board(WINDOW *window, phase phase);

    static void write_board(std::ofstream &file_stream, std::vector<std::vector<char>> board);
};


#endif //GACRE_GAPLA_BOARD_FILE_CREATOR_HPP
