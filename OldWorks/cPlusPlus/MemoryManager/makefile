TARGET= $(shell basename $(CURDIR))_test.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= Manager.o Page.o Pool.o Test.o 
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	


Manager.o: Manager.cpp Manager.h
	$(CC) $(CFLAGS) -c Manager.cpp
	
Page.o: Page.cpp Page.h Manager.h
	$(CC) $(CFLAGS) -c Page.cpp
	
Pool.o: Pool.cpp Pool.h Manager.h
	$(CC) $(CFLAGS) -c Pool.cpp
	
Test.o: Page.h Pool.h Test.cpp	
	$(CC) $(CFLAGS) -c Test.cpp	
clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
