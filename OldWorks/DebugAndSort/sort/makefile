# makefile sample

TARGET= leon.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g
OBJS= vector.o sort.o sorttest.o
MATH= -lm
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(MATH)
	
sorttest.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sorttest.c	
	
vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c
	
sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c
	
clean:
	rm -f $(TARGET) $(OBJS)
