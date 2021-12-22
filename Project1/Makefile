CC = g++
CFLAGS = -g

all : GoAirProgram

OBJECTS = GoAirProgram.o GoAirImplementation.o SortedList.o Passenger.o Flight.o BookingNum.o

SortedList.o : SortedList.cpp
	$(CC) -c $(CFLAGS) $< -o $@

BookingNum.o : BookingNum.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Passenger.o : Passenger.cpp
	$(CC) -c $(CFLAGS) $< -o $@

Flight.o : Flight.cpp
	$(CC) -c $(CFLAGS) $< -o $@

GoAirImplementation.o : GoAirImplementation.cpp
	$(CC) -c $(CFLAGS) $< -o $@

GoAirProgram.o : GoAirProgram.cpp
	$(CC) -c $(CFLAGS) $< -o $@

GoAirProgram : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f Node.o
	rm -f SortedList.o
	rm -f Passenger.o
	rm -f Flight.o
	rm -f GoAirImplementation.o
	rm -f GoAirProgram.o
	rm -f GoAirProgram
