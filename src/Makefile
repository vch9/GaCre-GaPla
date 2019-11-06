cc = g++
flags = --std=c++11 -Wall
obj = main.o board/board.o board/cells/cell.o board/cells/elems/elem.o

objs = $(addprefix ./obj/, $(obj))

all: main

main: $(objs)
	$(cc) -o $@ $^

obj/main.o: board/board.hpp

obj/board/board.o: board/board.hpp

obj/board/cells/cell.o: board/cells/cell.hpp board/cells/elems/elem.hpp

obj/board/cells/elems/elem.o: board/cells/elems/elem.hpp

obj/%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	find . -name '*.o' -delete
	rm main
