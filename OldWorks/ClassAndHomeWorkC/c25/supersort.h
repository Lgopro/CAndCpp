#ifndef _ROUND_
#define _ROUND_


/*
Description: Function swap between the two elemnts.
Input: Two void pointers and a size of the variable to swap.
Output: void.
Complexity: O(1)
*/
void Swap(void* _elem1,void* _elem2, size_t _size);
/*
Description: Function compare between two elements.
Input: Two void pointers .
Output: 1 if element 1 bigger then element 2 and 0 if not.
Complexity: O(1)
*/
int Compare(const void* _elem1,const void* _elem2);
/*
Description: Function sort the needed data structure.
Input: The array of the elements to sort,amount of elements, element size and needed function to compare.
Output: 1 if sorted.
Complexity: O(n)
*/
int sort(void* _elements,size_t _elementsCount,size_t _elementSize,int (*_less)(const void*, const void*));





#endif
