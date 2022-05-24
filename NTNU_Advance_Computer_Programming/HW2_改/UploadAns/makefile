CC= g++
CFLAGS= -Wall -Wextra -std=c++14 -O2
LDLIBS= -lm
NAMEONE= main
ONE= Main.o

.PHONY: all clean

all: Main

main: Main.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)