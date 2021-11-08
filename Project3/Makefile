CC = g++
CFLAGS = -g -std=c++11

all : P3Executable

OBJECTS = P3Executable.o

P3Executable.o : P3Executable.cpp
	$(CC) -c $(CFLAGS) $< -o $@

P3Executable : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f P3Executable.o
	rm -f P3Executable