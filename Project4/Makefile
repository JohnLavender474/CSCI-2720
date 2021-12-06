CC = g++
CFLAGS = -g -std=c++11

all : US_Graph_Program

OBJECTS = US_Graph_Program.o

US_Graph_Program.o : US_Graph_Program.cpp
	$(CC) -c $(CFLAGS) $< -o $@

US_Graph_Program : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f US_Graph_Program.o
	rm -f US_Graph_Program