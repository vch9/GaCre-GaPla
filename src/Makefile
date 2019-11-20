cc = g++
flags = --std=c++11 -Wall -ggdb3
obj = \
main.o board/board.o cells/cell.o \
elems/elem.o elems/wall.o elems/door.o elems/diamond.o elems/charge.o \
elems/player.o elems/monster.o \
actions/move.o actions/health.o actions/damage.o \
files/generate_board.o \
common/dijkstra.o \
view/view.o view/control.o \
game/game.o

objs = $(addprefix ./obj/, $(obj))

libs = -lncurses

MKDIR_OBJ = mkdir -p obj/ obj/actions obj/board obj/cells obj/elems obj/files obj/game obj/common obj/view

all: directories main

directories:
	${MKDIR_OBJ}

main: $(objs)
	$(cc) -o $@ $^ $(flags) $(libs)

obj/main.o: board/board.hpp cells/cell.hpp elems/elem.hpp elems/wall.hpp view/view.hpp

obj/board/board.o: board/board.hpp elems/elem.hpp

obj/cells/cell.o: cells/cell.hpp elems/elem.hpp

obj/elems/elem.o: elems/elem.hpp game/game.hpp
obj/elems/wall.o: elems/elem.hpp elems/wall.hpp
obj/elems/door.o: elems/elem.hpp elems/door.hpp
obj/elems/diamond.o: elems/elem.hpp elems/door.hpp elems/player.hpp
obj/elems/charge.o: elems/elem.hpp elems/charge.hpp elems/player.hpp

obj/actions/action.o: actions/action.hpp game/game.hpp elems/elem.hpp

obj/elems/moving/movingElem.o: elems/elem.hpp
obj/elems/player.o: elems/elem.hpp elems/player.hpp actions/move.hpp actions/health.hpp view/control.hpp
obj/elems/monster.o: elems/elem.hpp elems/monster.hpp actions/move.hpp common/dijkstra.hpp

obj/actions/move.o: actions/move.hpp elems/elem.hpp game/game.hpp board/board.hpp
obj/actions/health.o: actions/health.hpp
obj/actions/damage.o: actions/damage.hpp actions/health.hpp elems/elem.hpp

obj/files/generate_board.o: files/generate_board.hpp cells/cell.hpp board/board.hpp game/game.hpp \
elems/wall.hpp elems/charge.hpp elems/diamond.hpp elems/door.hpp elems/player.hpp elems/monster.hpp

obj/common/dijkstra.o: common/dijkstra.hpp board/board.hpp cells/cell.hpp

obj/view/view.o: view/view.hpp board/board.hpp cells/cell.hpp elems/elem.hpp
obj/view/control.o: view/control.hpp

obj/game/game.o: game/game.hpp board/board.hpp elems/elem.hpp elems/door.hpp view/view.hpp

obj/%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	find . -name '*.o' -delete
	rm main
