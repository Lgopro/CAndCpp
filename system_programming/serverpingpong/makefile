# makefile sample

TARGET= $(NAME)
CC= gcc 
CFLAGS= -pthread -std=c89 -Wall -Wextra -g
CFRELEASE = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
TESTDIR = ./test/
SRCDIR = ./src/
INC = ./include
NAME = Server
FILES= $(TESTDIR)$(NAME)_test.c $(SRCDIR)$(NAME).c 
VLG = valgrind --leak-check=yes --track-origins=yes

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(FILES)
		
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
	
