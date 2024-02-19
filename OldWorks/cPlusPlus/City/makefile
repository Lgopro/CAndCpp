#makefile String_t_main

TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS=  -ansi -pedantic -g3
OBJS= City_test.o


all: $(TARGET)

run:$(TARGET)
	./$(TARGET)

gdb:$(TARGET)
	gdb ./$(TARGET) -q

clean:$(TARGET)
	rm -f $(TARGET) depends $(OBJS)
	
valgrind:$(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

lib: $(LIB)	

SRCS=$(OBJS:.o=.cpp)
$(TARGET): depends $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
depends:
	$(CC) -MM -I./ $(SRCS) > depends
include depends	

