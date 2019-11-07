cc = g++
flags = --std=c++11 -Wall -g
obj = main.o board/board.o cells/cell.o \
elems/elem.o elems/wall.o elems/door.o elems/diamond.o elems/charge.o \
elems/moving/movingElem.o elems/moving/player.o elems/moving/monster.o \
files/generate_board.o \
game/game.o

objs = $(addprefix ./obj/, $(obj))

all: main

main: $(objs)
	$(cc) -o $@ $^

obj/main.o: board/board.hpp cells/cell.hpp elems/elem.hpp elems/wall.hpp

obj/board/board.o: board/board.hpp elems/elem.hpp

obj/cells/cell.o: cells/cell.hpp elems/elem.hpp

obj/elems/elem.o: elems/elem.hpp game/game.hpp
obj/elems/wall.o: elems/elem.hpp elems/wall.hpp
obj/elems/door.o: elems/elem.hpp elems/door.hpp
obj/elems/diamond.o: elems/elem.hpp elems/door.hpp elems/moving/player.hpp
obj/elems/charge.o: elems/elem.hpp elems/charge.hpp elems/moving/player.hpp

obj/elems/moving/movingElem.o: elems/elem.hpp elems/moving/movingElem.hpp
obj/elems/moving/player.o: elems/moving/movingElem.hpp elems/moving/player.hpp
obj/elems/moving/monster.o: elems/moving/movingElem.hpp elems/moving/monster.hpp

obj/files/generate_board.o: files/generate_board.hpp cells/cell.hpp board/board.hpp game/game.hpp \
elems/wall.hpp elems/charge.hpp elems/diamond.hpp elems/door.hpp elems/moving/player.hpp elems/moving/monster.hpp


obj/game/game.o: game/game.hpp board/board.hpp elems/elem.hpp

obj/%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	find . -name '*.o' -delete
	rm main
