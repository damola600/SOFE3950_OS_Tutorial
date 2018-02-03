CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
RM      = rm -f
BIN	= ./bin

default: all
all: question1 question2 question3

question1: Question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 Question1.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 Question2.c

question3: Question3.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question3 Question3.c

.PHONY: clean

clean:
	$(RM) $(BIN)

$(shell mkdir -p $(BIN)) # Create bin directory if it doesnot exist
