
TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= string.o string_test.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
string.o: string.cpp string.hpp mu_test.h
	$(CC) $(CFLAGS) -c string.cpp 

string_test.o: string_test.cpp string.hpp mu_test.h
	$(CC) $(CFLAGS) -c string_test.cpp
clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)