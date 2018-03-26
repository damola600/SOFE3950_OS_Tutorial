CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

default: all
all: question4 question5

question4: question4.o
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 -fopenmp question4.c 

question5: question5.o
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5 -fopenmp question5.c -lm

.PHONY: clean

clean:
	rm -f $(BIN)