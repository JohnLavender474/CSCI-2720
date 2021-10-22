CC = g++
CFLAGS = -g -std=c++11

all : test

OBJECTS = test.o T3Solver.o

T3Solver.o : T3Solver.cpp
	$(CC) -c $(CFLAGS) $< -o $@

test.o : test.cpp
	$(CC) -c $(CFLAGS) $< -o $@

test : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f T3Solver.o
	rm -f test.o
	rm -f ./test