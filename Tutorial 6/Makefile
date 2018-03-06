CC	= gcc
CFLAGS	= -g -Wall -Wextra
CSTANDARD	= -std=c11
RM	= rm -f

default: all
all: question4 question5

question4: question4.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o question4 question4.c -pthread

question5: question5.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o question5 question5.c -pthread
