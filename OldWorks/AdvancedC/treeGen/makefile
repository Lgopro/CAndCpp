# makefile sample

LIB_OBJS = bintree.o
OBJS=$(LIB_OBJS) bintreetest.o



CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion -fPIC
OBJS= bintree.o  bintreetest.o 
TARGET=$(shell basename $(CURDIR))_test.out

run:$(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 

lib: $(LIB_OBJS)
	
bintree.o: bintree.c binary.h
	$(CC) $(CFLAGS) -c bintree.c
	
bintreetest.o: bintreetest.c
	$(CC) $(CFLAGS) -c bintreetest.c
	
clean:
	rm -f $(TARGET) $(OBJS)

