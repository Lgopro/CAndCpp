# makefile sample

TARGET= $(NAME)
CC= g++ -std=c++2a 
CFLAGS= -g -pthread
CFRELEASE = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
TESTDIR = ./test/
SRCDIR = ./src/
INC = ./include
NAME = input_mediator
FILES= $(TESTDIR)$(NAME)_test.cpp $(SRCDIR)$(NAME).cpp $(SRCDIR)framework.cpp $(SRCDIR)thread_pool.cpp $(SRCDIR)reactor.cpp $(SRCDIR)asyncinjection.cpp $(SRCDIR)scheduler.cpp $(SRCDIR)handleton_inst.cpp $(SRCDIR)tp_task.cpp $(SRCDIR)i_command.cpp $(SRCDIR)i_listener.cpp $(SRCDIR)raid_manager.cpp $(SRCDIR)minnionproxy.cpp $(SRCDIR)UDPsocket.cpp $(SRCDIR)messageheader.cpp $(SRCDIR)NBDproxy.cpp $(SRCDIR)uid_map.cpp 
VLG = valgrind --leak-check=yes --track-origins=yes

$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(FILES) -ldl -lrt
		
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
	
