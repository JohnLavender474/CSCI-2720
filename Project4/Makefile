CC = g++
CFLAGS = -g -std=c++11

all : main

OBJECTS = main.o

main.o : main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f main.o
	rm -f main