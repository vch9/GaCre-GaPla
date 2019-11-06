cc = g++
flags = --std=c++11 -Wall
obj = main.o cells/cell.o
objs = $(addprefix ./obj/, $(obj))

all: main

main: $(objs)
	$(cc) -o $@ $^

obj/main.o: cells/cell.hpp

obj/cells/cell.o: cells/cell.hpp

obj/%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	find . -name '*.o' -delete
	rm main
