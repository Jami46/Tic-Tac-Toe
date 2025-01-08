CC = gcc
CFLAGS = -Wall

all: tic_tac_toe

tic_tac_toe: tic_tac_toe.c
	$(CC) $(CFLAGS) tic_tac_toe.c -o tic_tac_toe

clean:
	rm -f tic_tac_toe
