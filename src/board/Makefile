cc = g++
flags = --std=c++11 -Wall -g
obj = board.o

build: $(obj)

board.o: board.hpp ../cells/cell.hpp ../elems/elem.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
