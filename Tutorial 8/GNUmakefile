CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell cp ./processes_q2.txt $(BIN)) # Copy resources
$(shell cp ./processes_tree.txt $(BIN)) # Copy resources

default: all
all: process question2 question1

process: sigtrap.c
	$(CC) $(CFLAGS) -std=gnu99 -o $(BIN)/process sigtrap.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 Question2.c

question1: question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 question1.c proc_tree.c

.PHONY: clean

clean:
	rm -f $(BIN)
