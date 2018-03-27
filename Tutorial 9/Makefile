CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell cp ./calculations.txt $(BIN)) # Copy resources for question 5

default: all
all: question4 question5

question4: question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 -fopenmp question4.c

question5: question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5 -fopenmp question5.c -lm

.PHONY: clean

clean:
	rm -f $(BIN)
