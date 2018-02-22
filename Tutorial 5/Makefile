CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

default: all
all: question1 question2 question3 question4 question5

question1: Question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 Question1.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 Question2.c

question3: Question3.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question3 Question3.c

question4: Question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 Question4.c

question5: Question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5 Question5.c -lm

.PHONY: clean

clean:
	rm -f $(BIN)

$(shell mkdir -p $(BIN)) # Create bin directory automatically
