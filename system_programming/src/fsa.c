/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date: 23.05.2023
*/
#include <assert.h> /*assert*/


#include "fsa.h"

#define WORD (sizeof(size_t))
#define EMPTY (0)


struct Fsa
{
	size_t next_available;
};

static size_t RealSizeOfBlock(size_t size_of_block);
static void LoopInitialize(void *current_location, size_t allocated_size, size_t block_size, size_t location);


fsa_t *FSAInit(void *ptr_to_memory, size_t allocated_size, size_t block_size)
{
	fsa_t *fsa = NULL;   
	size_t location = 0;
	
	void *current_location = NULL;
	
	assert(NULL != ptr_to_memory);
	assert(0 < allocated_size);
	assert(0 < block_size);
	assert(0 == *(size_t *)&ptr_to_memory % sizeof(size_t));
	
	current_location = ptr_to_memory;
	
	fsa = (fsa_t *)current_location;
	
	fsa->next_available = sizeof(fsa); 
	
	
	*(size_t *)ptr_to_memory = fsa->next_available;
	
	current_location = (char *)current_location + sizeof(fsa_t);
	
	block_size = RealSizeOfBlock(block_size);
	
	location = fsa->next_available + block_size; 
	
	*(size_t *)current_location = location;
	
	LoopInitialize(current_location, allocated_size, block_size, location);
	return fsa;
}


size_t FSACountFree(const fsa_t *fsa)
{
	void *current_location = NULL;
	size_t size_of_block = 0;
	size_t counter = 1;
	
	assert(NULL != fsa);
	
	current_location = (void *)fsa;
	
	current_location = (char *)current_location + fsa->next_available;

	size_of_block = *(size_t *)current_location - fsa->next_available;
	
	while(0 != *(size_t *)current_location)
	{	
		++counter;
		current_location = (char *)current_location + size_of_block;
	}	
	++counter;
	return counter;

}


void *FSAAlloc(fsa_t *fsa)
{
	
	void *current_location = NULL;
	
	assert(NULL != fsa);
	
	if(0 == fsa->next_available)
	{
		return (void *)fsa;
	}
	
	current_location = (void *)fsa;
	
	fsa->next_available = *(size_t *)((char *)current_location + fsa->next_available);
	
	return ((void *)((char *)current_location + fsa->next_available));
}

void FSAFree(fsa_t *fsa, void *block_to_free)
{
	size_t temp = 0;
	
	assert(NULL != fsa);
	
	temp = fsa->next_available;
	
	fsa->next_available = *(size_t *)&block_to_free - *(size_t *)&fsa;
	
	*(size_t *)block_to_free = temp;
	
}


size_t FSASuggestSize(size_t block_number, size_t size_of_block)
{
	assert(0 != block_number);
	assert(0 != size_of_block);
	
	return (block_number * RealSizeOfBlock(size_of_block) + WORD);
}



static size_t RealSizeOfBlock(size_t size_of_block)
{
	return (size_of_block + (WORD - size_of_block % WORD));
}


static void LoopInitialize(void *current_location, size_t allocated_size, size_t block_size, size_t location)
{
	
	while(location < allocated_size - block_size)
	{
		
		current_location = (char *)current_location + block_size;
		
		location += block_size;
		
		*(size_t *)current_location = location;
	
	}

	*(size_t *)current_location = EMPTY; 
}



