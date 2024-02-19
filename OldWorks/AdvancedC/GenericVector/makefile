# makefile sample

LIB_OBJS = genvec.o

OBJS=$(LIB_OBJS) vectortest.o


TARGET= vector.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g -fPIC
OBJS= genvec.o  vectortest.o 
LDFLAGS=-L$(LIB_DIR) -lDS -Wl,-rpath=$(CURDIR)/../lib
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)
	
lib: $(LIB_OBJS)
genvec.o: genvec.c vector.h
	$(CC) $(CFLAGS) -c genvec.c

	
vectortest.o: vectortest.c
	$(CC) $(CFLAGS) -c vectortest.c
	
clean:
	rm -f $(TARGET) $(OBJS)
	

run:$(TARGET)
	./$(TARGET)
	

