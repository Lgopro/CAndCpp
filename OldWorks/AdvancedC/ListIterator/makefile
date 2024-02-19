# makefile List

LIB_OBJS = ListFunctions.o List.o ListIt.o
OBJS=$(LIB_OBJS) ListFunctionTest.o ListTest.o ListItTest.o

CC= gcc
CFLAGS= -ansi -pedantic -Wall -g3 -Wconversion -fPIC
LIST_OBJS=  List.o 
LIST_IT_OBJS= ListIt.o 
LIST_FUNC_OBJS= ListFunctions.o 

all: ListTest.out ListItTest.out ListFunctionsTest.out

run: all
	./ListTest.out
	./ListItTest.out
	./ListFunctionsTest.out
# Test 1
ListTest.out: ListTest.o $(LIST_OBJS)
	$(CC) -o ListTest.out ListTest.o $(LIST_OBJS)
# Test 2
ListItTest.out: ListItTest.o $(LIST_IT_OBJS) $(LIST_OBJS)
	$(CC) -o ListItTest.out ListItTest.o $(LIST_IT_OBJS) $(LIST_OBJS)
# Test 3
ListFunctionsTest.out: ListFunctionsTest.o $(LIST_IT_OBJS) $(LIST_FUNC_OBJS) $(LIST_OBJS)
	$(CC) -o ListFunctionsTest.out ListFunctionsTest.o $(LIST_IT_OBJS) $(LIST_OBJS) $(LIST_FUNC_OBJS)
	
lib: $(LIB_OBJS)
ListFunctionTest.o: ListFunctionsTest.c ListFunctions.h List.h mu_test.h
	$(CC) $(CFLAGS) -c ListFunctionsTest.c	
	
ListTest.o: ListTest.c List.h mu_test.h
	$(CC) $(CFLAGS) -c ListTest.c

List.o: List.c List.h ListStructs.h
	$(CC) $(CFLAGS) -c List.c				

ListItTest.o: ListItTest.c ListIt.h List.h mu_test.h
	$(CC) $(CFLAGS) -c ListItTest.c

ListIt.o: ListIt.c ListIt.h List.h ListStructs.h
	$(CC) $(CFLAGS) -c ListIt.c				

clean:
	rm -f *.out *.o
