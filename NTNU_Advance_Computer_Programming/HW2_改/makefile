CC= g++
CFLAGS= -Wall -Wextra -std=c++14 -O2
LDLIBS= -lm
NAMEONE= main
ONE= main.o

.PHONY: all clean

all: main

main: main.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)