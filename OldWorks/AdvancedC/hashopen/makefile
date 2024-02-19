# makefile hash map

LIB_OBJS = HashMap.o
OBJS=$(LIB_OBJS) HashMapTest.o


TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion -fPIC
OBJS= HashMapTest.o HashMap.o 
LDFLAGS=-L$(LIB_DIR) -lDS -Wl,-rpath=$(CURDIR)/../lib
all: $(TARGET)
	
run:$(TARGET)
	./$(TARGET)
	
gdb:$(TARGET)
	gdb ./$(TARGET) -q

clean:$(TARGET)
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

lib: $(LIB_OBJS)
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

HashMapTest.o: HashMapTest.c mu_test.h HashMap.h 
	$(CC) $(CFLAGS) -c HashMapTest.c

HashMap.o: HashMap.c HashMap.h 
	$(CC) $(CFLAGS) -c HashMap.c	
	

