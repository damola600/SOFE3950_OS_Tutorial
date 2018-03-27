CC      = gcc
CFLAGS  = -g -Wall -Wextra
LFLAGS = -lm -fopenmp
CSTANDARD = -std=gnu99
BIN	= ./bin

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell cp ./calculations.txt $(BIN)) # Copy resources for question 5

default: all
all: question4 question5 demo1 demo2

question4: question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 question4.c $(LFLAGS)

question5: question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5  question5.c $(LFLAGS)

demo1: demo1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/demo1  demo1.c $(LFLAGS)

demo2: demo2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/demo2  demo2.c $(LFLAGS)

.PHONY: clean

clean:
	rm -f $(BIN)
