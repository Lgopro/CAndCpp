# makefile sample

TARGET= list.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g
OBJS= genlist.o  genlisttest.o 
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
genlist.o: genlist.c list.h
	$(CC) $(CFLAGS) -c genlist.c

	
genlisttest.o: genlisttest.c
	$(CC) $(CFLAGS) -c genlisttest.c
	
clean:
	rm -f $(TARGET) $(OBJS)
