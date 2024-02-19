# makefile hash map

LIB_OBJS = HashMap.o
OBJS=$(LIB_OBJS) HashMapTest.o


TARGET= $(shell basename $(CURDIR))_test.out
CC= gcc
CFLAGS=  -pedantic -Wall -g3 -Wconversion
OBJS= TimeTest.o Time.o task.o taskExcutor.o
LIB_DIR=$(CURDIR)/../lib
LDFLAGS=-L$(LIB_DIR) -lDS -Wl,-rpath=$(LIB_DIR)
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



SRCS=$(OBJS:.o=.c)

$(TARGET): depends $(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)
	
depends: 
		$(CC) -MM -I./ $(SRCS) > depends
		
include depends