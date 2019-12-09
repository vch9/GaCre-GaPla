cc = g++
LIBS = -lncurses
FLAGS = --std=c++11 -Wall
obj = main_game_creator.o game_file_creator.o board_file_creator.o generate_board.o

gc : $(obj)
	mkdir -p ../../boards/
	mkdir -p ../../games/
	$(cc) -o $@ main_game_creator.o game_file_creator.o board_file_creator.o  $(LIBS) $(FLAGS)

main_game_creator.o: game_file_creator.hpp board_file_creator.hpp

game_file_creator.o: game_file_creator.hpp

board_file_creator.o: board_file_creator.hpp

generate_board.o: generate_board.hpp ../game/game.hpp ../board/board.hpp ../cells/cell.hpp \
../elems/wall.hpp ../elems/charge.hpp ../elems/diamond.hpp ../elems/door.hpp ../elems/player.hpp \
../elems/monster.hpp ../elems/quiver.hpp ../elems/trap.hpp

%.o: %.cpp
	$(cc) $(FLAGS) -o $@ -c $<
clean:
	rm *.o
	rm gc
