cc = g++
flags = --std=c++11 -Wall -g
obj = dijkstra.o

build: $(obj)

dijkstra.o: dijkstra.hpp ../board/board.hpp ../cells/cell.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
