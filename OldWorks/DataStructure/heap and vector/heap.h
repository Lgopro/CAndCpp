#ifndef _HEAP_
#define _HEAP_

typedef struct Heap Heap;
#define NOT_INIT -1

/*
Description: Function gets the vector structure and creates a heap from it
Input: The vector structure
Output: The heap struct.
Complexity: O(n).
*/
Heap* HeapBuild(Vector* _vec); 
/*
Description: Function destroyes the heap.
Input: The structure structure
Output: Void.
Complexity: O(n).
*/
void HeapDestroy(Heap* _heap);
/*
Description: Function insert a new data into the heap and rebiulds it.
Input: The heap structue and the data selected.
Output: returnes ERR_NOT_INITIALIZED if heap dont exist, ERR_NOT_ADDED is the item not added and ERR_OK if the item is added.
Complexity: O(n).
*/
ADTErr HeapInsert(Heap* _heap, int _data); 
/*
Description: Function gets the value of the heap root to the data pointer.
Input: the heap structure and the data pointer
Output: returnes ERR_NOT_INITIALIZED if heap or pointer dont exist and ERR_OK if the item value added to the pointer.
Complexity: O(1).
*/
ADTErr HeapMax(Heap* _heap, int* _data);
/*
Description: Function gets the value of the heap root to the data pointer.
Input: the heap structure and the data pointer
Output: returnes ERR_NOT_INITIALIZED if heap or pointer dont exist and ERR_OK if the item value added to the pointer.
Complexity: O(1).
*/
ADTErr HeapExtractMax(Heap* _heap, int* _data); 
/*
Description: Function calculates the number of items in the function.
Input: the heap structure .
Output: number of items of the heap or NOT_INIT if the heap dont exist.
Complexity: O(1).
*/
int HeapItemsNum(Heap* _heap);
/*
Description: Function the heap.
Input: the heap structure .
Output: Void.
Complexity: O(n).
*/
void HeapPrint(Heap* _heap);


#endif
