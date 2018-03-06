CC      = gcc
CFLAGS  = -g -Wall -Wextra -pthread
CSTANDARD = -std=c11
BIN	= ./bin

default: all
all: question1 question2 question3 question4 question5

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell mv numbers.txt $(BIN)) # Copy resources
$(shell mv sum.txt $(BIN))

question1: Question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 Question1.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 Question2.c

question3: Question3.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question3 Question3.c

question4: question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 question4.c

question5: question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5 question5.c

.phony: clean

clean:
	rm -f $(BIN)
