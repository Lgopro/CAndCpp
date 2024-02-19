
TARGET= string.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= String.o  StringTest.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
String.o: String.cpp StringT.h
	$(CC) $(CFLAGS) -c String.cpp

StringTest.o: StringTest.cpp StringT.h mu_test.h
	$(CC) $(CFLAGS) -c StringTest.cpp
	
clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)