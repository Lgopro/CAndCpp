TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= VirtIO_test.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
VirtIO_test.o: VirtIO_test.cpp VirtIO_t.h TException_t.h binIO_t.h asciiIO_t.h
	$(CC) $(CFLAGS) -c VirtIO_test.cpp


clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
