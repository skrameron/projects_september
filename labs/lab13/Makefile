CC = g++

all: lab13

lab13: lab13.o
	$(CC) -o $@ $^

lab13.o: lab13.cpp
	$(CC) -c -Wall $<

.PHONY: clean

clean:
	rm -f *.o lab13

