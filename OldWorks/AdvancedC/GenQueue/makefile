# makefile sample

LIB_OBJS = genqueue.o
OBJS=$(LIB_OBJS) testqueue.o

TARGET= queue.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g -fPIC
OBJS= genqueue.o  testqueue.o 
LDFLAGS=-L$(LIB_DIR) -lDS -Wl,-rpath=$(CURDIR)/../lib
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
	
lib: $(LIB_OBJS)

genqueue.o: genqueue.c queue.h
	$(CC) $(CFLAGS) -c genqueue.c
	
testqueue.o: testqueue.c
	$(CC) $(CFLAGS) -c testqueue.c
	
clean:
	rm -f $(TARGET) $(OBJS)
