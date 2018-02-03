CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
RM      = rm -f

default: all

all: question1 question2

question1: Question1.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o question1 Question1.c

question2: Question2.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o question2 Question2.c

clean veryclean:
	$(RM) question2 question1
