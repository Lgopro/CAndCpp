/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date: 23.05.2023
*/

#ifndef __ILRD_FSA__
#define __ILRD_FSA__

#include <stddef.h> /*NULL, size_t*/

typedef struct Fsa fsa_t;
/*
struct Fsa
{
	size_t next_available;
};
*/

/*============================================================================*/
/*
Name: FSAInit
Description: Initialize the managment of the allocated space.
Arguments: Valid pointer to ptr_to_memory, allocated_size that is not zero, 
block_size that is not zero.
Return: Pointer to the begining of the allocated space.
Time complexity: O(n)
Space complexity: O(1)
*/
fsa_t *FSAInit(void *ptr_to_memory, size_t allocated_size, size_t block_size);

/*============================================================================*/
/*
Name: FSAAlloc		
Description: Allocate information on one block of information
Arguments: Valid pointer to fsa.
Return: location of the next space that is free, NULL if there is no space free.
Time complexity: O(1)
Space complexity: O(1)
*/
void *FSAAlloc(fsa_t *fsa);

/*============================================================================*/
/*
Name: FSAFree
Description: Free allocated space.
Arguments: Valid pointer to the block_to_free and fsa.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void FSAFree(fsa_t *fsa, void *block_to_free);

/*============================================================================*/
/*
Name: FSACountFree return amount of free blocks
Description: Count free amount of bytes in the allocated space.
Arguments: Valid pointer to fsa.
Return: Amount of free bytes.
Time complexity: O(n)
Space complexity: O(1)
*/
size_t FSACountFree(const fsa_t *fsa);

/*============================================================================*/
/*
Name: FSASuggestSize
Description: Suggest the user the right size for allocation.
Arguments: size of block and amount of blocks.
Return: The suggested size.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t FSASuggestSize(size_t block_number, size_t size_of_block);



#endif /*__ILRD_FSA__*/
