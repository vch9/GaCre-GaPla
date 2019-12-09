cc = g++
flags = --std=c++11 -Wall -g
obj = view.o control.o

build: $(obj)

view.o: view.hpp ../board/board.hpp ../cells/cell.hpp ../elems/elem.hpp

control.o: control.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
