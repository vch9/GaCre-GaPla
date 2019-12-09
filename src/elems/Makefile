cc = g++
flags = --std=c++11 -Wall -g
obj = elem.o wall.o door.o diamond.o charge.o arrow.o player.o monster.o

build: $(obj)

arrow.o: arrow.hpp player.hpp monster.hpp ../actions/move.hpp ../actions/health.hpp

charge.o: charge.hpp elem.hpp player.hpp

diamond.o: diamond.hpp elem.hpp player.hpp

door.o: door.hpp elem.hpp ../game/game.hpp

elem.o: elem.hpp

monster.o: monster.hpp elem.hpp player.hpp ../game/game.hpp ../actions/move.hpp ../actions/health.hpp ../common/dijkstra.hpp ../view/view.hpp

player.o: player.hpp elem.hpp arrow.hpp ../actions/move.hpp ../actions/health.hpp ../view/control.hpp ../view/view.hpp

quiver.o: quiver.hpp elem.hpp player.hpp

wall.o: wall.hpp elem.hpp

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
