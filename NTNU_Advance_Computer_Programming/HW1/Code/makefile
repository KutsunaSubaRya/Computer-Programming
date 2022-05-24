CC= g++
CFLAGS= -Wall -Wextra -std=c++14 -O2
LDLIBS= -lm
NAMEONE= main
ONE= Main.o Maze.o Robot.o

.PHONY: all clean

all: main

main: Main.o Maze.o Robot.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)