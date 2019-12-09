cc = g++
flags = --std=c++11 -Wall -g
obj = view.o control.o

build: $(obj)

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
