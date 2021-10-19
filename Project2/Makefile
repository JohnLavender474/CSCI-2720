CC = g++
CFLAGS = -g -Wall -pedantic

VPATH = ./src/first_dir : ./src/second_dir : ./src/third_dir
SRC = $(wildcard *.cpp)
OBJ = $(SRC : .cpp = .o)
BIN = my_bin

all : $(BIN)

$(BIN) : $(OBJ)

clean:
	rm -f *.o
	rm -f $(BIN)


