CC = g++
CFLAGS = -g

all : main

OBJECTS = main.o SortedList.o Passenger.o Flight.o GoAir.o

SortedList.o : SortedList.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Passenger.o : Passenger.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Flight.o : Flight.cpp
	$(CC) -c $(CFLAGS) $< -o $@

GoAir.o : GoAir.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main.o : main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f Node.o
	rm -f SortedList.o
	rm -f Passenger.o
	rm -f Flight.o
	rm -f GoAir.o
	rm -f main.o
	rm -f main
