CC      = gcc
CFLAGS  = -g -Wall -Wextra -pthread
CSTANDARD = -std=c11
BIN	= ./bin

default: all
all: question1 question2 question3 question4 question5

$(shell mkdir -p $(BIN)) # Create bin directory automatically
$(shell cp ./processes.txt $(BIN)) # Copy resources
$(shell cp ./processes2_q5.txt $(BIN)) # Copy resources
$(shell cp ./processes_q5.txt $(BIN)) # Copy resources

question1: question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question1 question1.c

question2: question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question2 question2.c

question3: question3.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question3 question3.c

question4: question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question4 question4.c

question5: question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/question5 question5.c

.phony: clean

clean:
	rm -f $(BIN)
