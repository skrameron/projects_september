CC = g++

all: p1

p1: p1.o
	$(CC) -o $@ $^

p1.o: p1.cpp
	$(CC) -c -Wall $<

.PHONY: clean

clean:
	rm -f *.o p1

