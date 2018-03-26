CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell cp ./processes_q2.txt $(BIN)) # Copy resources
<<<<<<< HEAD
=======
$(shell cp ./processes_tree.txt $(BIN)) # Copy resources
>>>>>>> a42c71b347f635f125c9fb910bf4203549379d6a

default: all
all: process question2 question1

<<<<<<< HEAD
question1: question1.o
	$(CC) $(CFLAGS) $(CSTANDARD) question1.o -o $(BIN)/question1 proc_tree.c

question1.o: question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -c question1.c

=======
>>>>>>> a42c71b347f635f125c9fb910bf4203549379d6a
process: sigtrap.c
	$(CC) $(CFLAGS) -std=gnu99 -o $(BIN)/process sigtrap.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 Question2.c

<<<<<<< HEAD
.PHONY: clean

clean:
	rm -f $(BIN)
=======
question1: question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 question1.c proc_tree.c

.PHONY: clean

clean:
	rm -f $(BIN)
>>>>>>> a42c71b347f635f125c9fb910bf4203549379d6a
