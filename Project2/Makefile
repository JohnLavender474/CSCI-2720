CC = g++
CFLAGS = -g -std=c++11

all : T3Solver

OBJECTS = T3SolverImplementation.o T3Solver.o

T3SolverImplementation.o : T3SolverImplementation.cpp
	$(CC) -c $(CFLAGS) $< -o $@

T3Solver.o : T3Solver.cpp
	$(CC) -c $(CFLAGS) $< -o $@

T3Solver : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f T3SolverImplementation.o
	rm -f T3Solver.o
	rm -f T3Solver