cc = g++
flags = --std=c++11 -Wall -g
obj = client.o

client: $(obj)
	$(cc) $(flags) -o client $^

%.o: %.cpp
	$(cc) $(flags) -o $@ -c $<

clean:
	rm *.o
	rm client
