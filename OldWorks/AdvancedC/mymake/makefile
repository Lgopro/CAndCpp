


CC = gcc  # C compiler
CFLAGS = -fPIC -Wall  -g3 -pedantic -ansi  # C flags
LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
TARGET_LIB = libDS.so  # target lib

SRCS = GenericVector/genvec.c  Heapgeneric/genheap.c genDoubleLinkedList/genlist.c GenQueue/genqueue.c treeGen/bintree.c IteratorList/ListIt.c hashopen/HashMap.c ListIterator/ListFunctions.c  # source files
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	mkdir -p lib
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c):%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c)
