CC = g++

all: p3

p3: p3.o
	$(CC) -o $@ $^

p3.o: p3.cpp
	$(CC) -c -Wall $<

.PHONY: clean

clean:
	rm -f *.o p3

