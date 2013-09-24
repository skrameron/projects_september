CC = g++

all: lab9

lab9: lab9.o
	$(CC) -o $@ $^

lab9.o: lab9.cpp
	$(CC) -c -Wall $<

.PHONY: clean

clean:
	rm -f *.o lab9

