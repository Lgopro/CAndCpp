# makefile List

LIB_OBJS = List.o ListIt.o
OBJS=$(LIB_OBJS) ListTest.o


CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion -fPIC
LIST_OBJS=  List.o 
LIST_IT_OBJS= ListIt.o 

all: ListTest.out ListTestIt.out

run: ListTest.out ListTestIt.out
	./ListTest.out
	./ListItTest.out

ListTest.out: ListTest.o $(LIST_OBJS)
	$(CC) -o ListTest.out ListTest.o $(LIST_OBJS)

ListTest.o: ListTest.c List.h
	$(CC) $(CFLAGS) -c ListTest.c

List.o: List.c List.h ListStructs.h
	$(CC) $(CFLAGS) -c List.c				

ListTestIt.out: ListItTest.o $(LIST_IT_OBJS) $(LIST_OBJS)
	$(CC) -o ListItTest.out ListItTest.o $(LIST_IT_OBJS) $(LIST_OBJS)

lib: $(LIB_OBJS)

ListItTest.o: ListItTest.c ListIt.h List.h
	$(CC) $(CFLAGS) -c ListItTest.c

ListIt.o: ListIt.c ListIt.h List.h ListStructs.h
	$(CC) $(CFLAGS) -c ListIt.c				

clean:
	rm -f *.out *.o
