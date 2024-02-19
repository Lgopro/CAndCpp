# makefile mymalloc

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion
OBJS= MyMalloc.o MyMallocTest.o

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

MyMallocTest.o: MyMallocTest.c mu_test.h MyMalloc.h
	$(CC) $(CFLAGS) -c MyMallocTest.c

MyMalloc.o: MyMalloc.c MyMalloc.h
	$(CC) $(CFLAGS) -c MyMalloc.c
