cc = g++
flags = --std=c++11 -Wall -g
obj = cell.o

build: $(obj)

cell.o: cell.hpp ../elems/elem.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
