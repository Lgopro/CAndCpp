# makefile sample

TARGET= myshell.out
CC= gcc
CFLAGS= -ansi -pedantic -Wall -g
OBJS= Shell.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
Shell.o: Shell.c 
	$(CC) $(CFLAGS) -c Shell.c 
	
	
clean:
	rm -f $(TARGET) $(OBJS)
