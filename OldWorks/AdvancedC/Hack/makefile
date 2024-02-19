# makefile hash map

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion 
OBJS= Stackhacking.o 

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

Stackhacking.o: Stackhacking.c 
	$(CC) $(CFLAGS) -c Stackhacking.c

	
	

