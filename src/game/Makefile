cc = g++
flags = --std=c++11 -Wall -g
obj = game.o game_player.o

all: build gp

build: $(obj)

gp:
	$(cc) $(flags) -o gp game_player.o

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
	rm gp
