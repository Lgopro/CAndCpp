# makefile sample

TARGET= ProjectHearts.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g
OBJS= deck.o  game.o player.o round.o ui.o main.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

	
deck.o: deck.c deck.h
	$(CC) $(CFLAGS) -c deck.c
	

	
game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c
	
player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c
	
round.o: round.c round.h
	$(CC) $(CFLAGS) -c round.c
	
ui.o: ui.c ui.h
	$(CC) $(CFLAGS) -c ui.c
	
clean:
	rm -f $(TARGET) $(OBJS)
