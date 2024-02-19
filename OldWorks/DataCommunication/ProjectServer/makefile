# makefile hash map

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion
OBJS= server.o genvec.o servertest.o

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

server.o: server.c server.h 
	$(CC) $(CFLAGS) -c server.c

genvec.o: genvec.c vector.h 
	$(CC) $(CFLAGS) -c genvec.c	
	
servertest.o: servertest.c server.h vector.h mu_test.h
	$(CC) $(CFLAGS) -c servertest.c
