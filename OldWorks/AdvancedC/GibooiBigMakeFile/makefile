# Directories to use for the library creation:

DIRS =  GenericVector Heapgeneric genDoubleLinkedList GenQueue treeGen IteratorList hashopen ListIterator

# Object files to use for the library creation:

LIB_OBJS= GenericVector/genvec.o  Heapgeneric/genheap.o genDoubleLinkedList/genlist.o GenQueue/genqueue.o treeGen/bintree.o IteratorList/ListIt.o hashopen/HashMap.o ListIterator/ListFunctions.o

# Path to the target library:

LIB_PATH=lib

LIB=$(LIB_PATH)/libDS.a

##########################################

# no need to change under this line

.PHONY: clean dirs_make

# Create the static library as archive file:

$(LIB): dirs_make
	mkdir -p $(LIB_PATH)
	ar -rcs $(LIB) $(LIB_OBJS)

# Make all folders by target clean:

clean:
	rm -f $(LIB)
	$(shell for dir in $(DIRS); do \
	echo "make clean -C $$dir;"; \
	done)

# Make all folders by target lib:

dirs_make:
	$(shell for dir in $(DIRS); do \
	echo "make lib -C $$dir;"; \
	done)
