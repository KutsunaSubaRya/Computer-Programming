CC= g++
CFLAGS= -Wall -Wextra -std=c++17 -O2
LDLIBS= -lm
NAMEONE= main
ONE= main.o String.o

.PHONY: all clean

all: main

main: main.o String.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)