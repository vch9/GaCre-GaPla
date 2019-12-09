LIBS = -lncurses
FLAGS = --std=c++11 -Wall


creator : game_file_creator.o board_file_creator.o
	g++ main_game_creator.cpp game_file_creator.cpp board_file_creator.cpp $(LIBS) $(FLAGS) -o gc

game_file_creator.o: game_file_creator.hpp
	g++ -c game_file_creator.cpp -o game_file_creator.o

board_file_creator.o: board_file_creator.hpp
	g++ -c board_file_creator.cpp -o board_file_creator.o

