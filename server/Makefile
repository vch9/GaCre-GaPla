cc = g++
flags = --std=c++11 -Wall -g
obj = server.o

server: $(obj)
	mkdir -p games/
	mkdir -p boards/
	$(cc) $(flags) -o server $^

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
	rm server
