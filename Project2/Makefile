CC = g++
CFLAGS = -g -std=c++11

all : test

OBJECTS = test.o

test.o : test.cpp
	$(CC) -c $(CFLAGS) $< -o $@

test : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f test.o
	rm -f ./test