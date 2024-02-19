# makefile hash map

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 
OBJS= client.o 

all: $(TARGET)
	
run:$(TARGET)
	./$(TARGET)
	
gdb:$(TARGET)
	gdb ./$(TARGET) -q

clean:$(TARGET)
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

client.o: client.c  
	$(CC) $(CFLAGS) -c client.c

#genvec.o: genvec.c vector.h 
	#$(CC) $(CFLAGS) -c genvec.c	
	

