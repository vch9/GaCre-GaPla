cc = g++
flags = --std=c++11 -Wall -g
obj = move.o health.o

build: $(obj)

move.o: move.hpp ../elems/elem.hpp ../game/game.hpp ../board/board.hpp

health.o: health.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
