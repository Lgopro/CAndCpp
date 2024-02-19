
TARGET= car.out
CC= g++
CFLAGS= -ansi -pedantic -Wall -g
OBJS= String.o Car.o Bus.o Private.o test.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
String.o: String.cpp StringT.h
	$(CC) $(CFLAGS) -c String.cpp

Car.o: Car.cpp StringT.h Car.h
	$(CC) $(CFLAGS) -c Car.cpp
	
Bus.o: Bus.cpp Bus.h Car.h
	$(CC) $(CFLAGS) -c Bus.cpp
	
Private.o: Private.cpp Private.h Car.h
	$(CC) $(CFLAGS) -c Private.cpp
	
test.o: Bus.h Private.h test.cpp	
	$(CC) $(CFLAGS) -c test.cpp	
clean:
	rm -f $(TARGET) $(OBJS)


run:  $(TARGET)
	 ./$(TARGET)


gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
