TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= parcer_test.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
parcer_test.o: parcer_test.cpp parser.h tokanizer.h analyzer.h TException_t.h
	$(CC) $(CFLAGS) -c parcer_test.cpp


clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
