#EECS 348 MAKE file for nfl 

CC = gcc
CFLAGS = -std=c17

nfl: nfl_score.c
	$(CC) $(CFLAGS) -o nfl nfl_score.c
clean:
	rm -f nfl
