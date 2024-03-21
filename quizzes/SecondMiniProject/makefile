# makefile sample

TARGET= $(NAME)
CC= g++ 
CFLAGS= -g -pthread
CFRELEASE = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
TESTDIR = 
SRCDIR = 
INC = 
NAME = UserAndServer
FILES= $(NAME).cpp $(NAME)_test.cpp
 
VLG = valgrind --leak-check=yes --track-origins=yes

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -I. -o $(TARGET) $(FILES) 
		
.PHONY: clean
clean:
	rm -f $(TARGET) *.o
	
.PHONY: release
release:
	$(CC) $(CFRELEASE) -I$(INC) -o ./bin/release/$(TARGET) $(FILES)


foo.o: $(FILES)
	$(CC) $(CFLAGS) -I$(INC) -o foo.o $(FILES)
		
.PHONY: run
run:  $(TARGET)
	 ./$(TARGET)

.PHONY: gdb
gdb:  $(TARGET)
	 gdb -tui ./$(TARGET)
	
.PHONY: vlg
vlg:  $(TARGET)
	 $(VLG) ./$(TARGET)
	 
	 
	 	 
.PHONY: debug
debug: 
	$(CC) $(CFLAGS) -I$(INC) -o ./bin/debug/$(TARGET) $(FILES)

.PHONY: all
all: debug release
	e
	
