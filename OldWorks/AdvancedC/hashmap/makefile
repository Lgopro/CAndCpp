# makefile hash map

TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion 
OBJS= HashMapTest.o HashMap.o List.o ListIt.o ListFunc.o

all: $(TARGET)
	
run:$(TARGET)
	./$(TARGET)
	
gdb:$(TARGET)
	gdb ./$(TARGET) -q

clean:$(TARGET)
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

HashMapTest.o: HashMapTest.c mu_test.h
	$(CC) $(CFLAGS) -c HashMapTest.c

HashMap.o: HashMap.c HashMap.h 
	$(CC) $(CFLAGS) -c HashMap.c	
	
List.o: List.c List.h ListStructs.h
	$(CC) $(CFLAGS) -c List.c				

ListIt.o: ListIt.c ListIt.h List.h ListStructs.h
	$(CC) $(CFLAGS) -c ListIt.c	

ListFunc.o: ListFunc.c ListFunc.h List.h 	
	$(CC) $(CFLAGS) -c ListFunc.c