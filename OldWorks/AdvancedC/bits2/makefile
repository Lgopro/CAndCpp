# makefile hash map

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion
OBJS= Bit.o BitTest.o

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

BitTest.o: BitTest.c mu_test.h Bit.h
	$(CC) $(CFLAGS) -c BitTest.c

Bit.o: Bit.c Bit.h
	$(CC) $(CFLAGS) -c Bit.c
