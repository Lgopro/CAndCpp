# makefile sample


LIB_OBJS = genheap.o genvec.o
OBJS=$(LIB_OBJS) testgenheap.o


TARGET= heap.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g -fPIC
OBJS= genvec.o  testgenheap.o genheap.o
LDFLAGS=-L$(LIB_DIR) -lDS -Wl,-rpath=$(CURDIR)/../lib
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
	
lib: $(LIB_OBJS)

genvec.o: genvec.c vector.h
	$(CC) $(CFLAGS) -c genvec.c

genheap.o: genheap.c heap.h
	$(CC) $(CFLAGS) -c genheap.c
	
testgenheap.o: testgenheap.c
	$(CC) $(CFLAGS) -c testgenheap.c
	
clean:
	rm -f $(TARGET) $(OBJS)

run:$(TARGET)
	./$(TARGET)