cc = g++
flags = --std=c++11 -Wall
obj = main.o board/board.o cells/cell.o elems/elem.o

objs = $(addprefix ./obj/, $(obj))

all: main

main: $(objs)
	$(cc) -o $@ $^

obj/main.o: board/board.hpp

obj/board/board.o: board/board.hpp

obj/cells/cell.o: cells/cell.hpp elems/elem.hpp

obj/elems/elem.o: elems/elem.hpp

obj/%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	find . -name '*.o' -delete
	rm main
