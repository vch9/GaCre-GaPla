cc = g++
flags = --std=c++11 -Wall -g
libs = -lncurses
obj = game_player.o game.o
links = \
../actions/health.o ../actions/move.o \
../board/board.o \
../cells/cell.o \
../common/dijkstra.o \
../elems/arrow.o ../elems/charge.o ../elems/diamond.o \
../elems/door.o ../elems/elem.o ../elems/monster.o \
../elems/quiver.o ../elems/wall.o ../elems/player.o \
../files/generate_board.o \
../view/control.o ../view/view.o

gp: $(obj)
	$(cc) $(flags) -o gp $^ $(links) $(libs)

game_player.o: ../game/game.hpp ../board/board.hpp ../files/generate_board.hpp

game.o: game.hpp ../board/board.hpp ../elems/door.hpp ../elems/wall.hpp ../actions/health.hpp ../view/view.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
	rm gp
