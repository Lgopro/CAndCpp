TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= testContainer.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
testContainer.o: testContainer.cpp List_h.h Vector_t.h Container_t.h
	$(CC) $(CFLAGS) -c testContainer.cpp

clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
