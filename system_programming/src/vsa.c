/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 24.05.23
*/
#include <stdio.h>
#include <assert.h> /*assert*/


#define DEADBEEF (0xDEADBEEF)
#define MAX (9223372036854775805)
#define WORD (sizeof(size_t))
#define STRUCT_SIZE (sizeof(blk_hdr_t))
#define END (0)
#define FLIP (-1)
#define ABS(x) ((x < 0) ? x * (-1) : x)

#include "vsa.h"

typedef struct blk_hdr
{
	long size_of_chunk; 
	
	#ifndef NDEBUG
	long magic_num;
	#endif /*NDEBUG*/
}blk_hdr_t;


static void Defragmantation(char *current_location, char *next_location, long amount_of_bytes);
static size_t RealSizeOfBlock(size_t size_of_block);



vsa_t *VSAInit(void *allocated_memory, size_t allocated_size)
{
	blk_hdr_t *chunk = NULL;
	blk_hdr_t *chunk_end = NULL;
	char *begin = NULL;
	
	assert(NULL != allocated_memory);
	assert(2 * sizeof(blk_hdr_t) < allocated_size);
	begin = allocated_memory;
	chunk = (blk_hdr_t *)allocated_memory;
	chunk->size_of_chunk = allocated_size - 2 * STRUCT_SIZE;
	
	#ifndef NDEBUG
	chunk->magic_num = DEADBEEF;
	#endif /*NDEBUG*/

	allocated_memory = (char *)allocated_memory + allocated_size - STRUCT_SIZE;
	
	chunk_end = (blk_hdr_t *)allocated_memory;
	
	chunk_end->size_of_chunk = END; 
	
	#ifndef NDEBUG
	chunk_end->magic_num = DEADBEEF;
	#endif /*NDEBUG*/
	
	allocated_memory = begin;
	return (vsa_t *)chunk;
}


void *VSAAlloc(vsa_t *vsa, size_t num_of_bytes) 
{
	blk_hdr_t *chunk = NULL;
	
	char *runner = NULL;
	long jump_next = 0;
	long place_left_after_allocation = 0;
	long size = (long)RealSizeOfBlock(num_of_bytes);
	char *runner_defragmantation = NULL;
	long value = 0;
	
	assert(NULL != vsa);
	
	
	num_of_bytes = RealSizeOfBlock(num_of_bytes);
	
	runner_defragmantation = (char *)vsa;
	value = *(long *)runner_defragmantation;
	
	runner = (char *)vsa;
	
	Defragmantation(runner_defragmantation, (runner_defragmantation + ABS(value)
	+ STRUCT_SIZE), (long)num_of_bytes);
	
	while(0 != *(long *)runner)
	{
		jump_next = *(long *)runner;
		
		if((long)num_of_bytes + (long)STRUCT_SIZE <= jump_next)
		{
			place_left_after_allocation = *(long *)runner - num_of_bytes 
			- STRUCT_SIZE; 
			
			*(long *)runner = -size;
			
			runner = runner + STRUCT_SIZE + num_of_bytes;
		
			chunk = (blk_hdr_t *)runner;
			chunk->size_of_chunk = place_left_after_allocation;
			
			#ifndef NDEBUG
			chunk->magic_num = DEADBEEF;
			#endif /*NDEBUG*/
			
			return (runner - num_of_bytes);
			
		}
		else if(0 == *(long *)(runner + ABS(jump_next) + STRUCT_SIZE) && (long)num_of_bytes <= jump_next)
		{
			chunk = (blk_hdr_t *)runner;
			chunk->size_of_chunk = -jump_next;
			
			#ifndef NDEBUG
			chunk->magic_num = DEADBEEF;
			#endif 
		
			return (runner + STRUCT_SIZE);
		}
		jump_next = ABS(jump_next);
		runner = runner + jump_next + STRUCT_SIZE;
	}
	
	return NULL;
}

void VSAFree(void *block_to_free)
{
	
	long amount_of_bytes_to_release = 0;
	assert(block_to_free);
	#ifndef NDEBUG	
	assert(DEADBEEF == *(long *)((char *)block_to_free - sizeof(long)));
	#endif /*NDEBUG*/
	
	amount_of_bytes_to_release = *(long *)((char *)block_to_free - STRUCT_SIZE);
	
	if(NULL == block_to_free)
	{
		return;
	}
	
	if(0 > *(long *)((char *)block_to_free - STRUCT_SIZE))
	{
		*(long *)((char *)block_to_free - STRUCT_SIZE) = amount_of_bytes_to_release * FLIP; 
	}
	
}

size_t VSAGetLargestChunkAvailable(vsa_t *vsa)
{
	long largest_chunk = 0;
	long jump_next = 0;
	char *runner = NULL;
	char *runner_defragmantation = NULL;
	assert(NULL != vsa);
	
	runner = (char *)vsa;
	runner_defragmantation = (char *)vsa;
	long value = *(long *)runner_defragmantation;
	if(0 > value)
	{
		Defragmantation(runner_defragmantation, (runner_defragmantation + value 
		* (-1) + STRUCT_SIZE), MAX);
	}
	else
	{
		Defragmantation(runner_defragmantation, (runner_defragmantation + value 
		+ STRUCT_SIZE), MAX);
	}
	while(0 != *(long *)runner)
	{
		jump_next = *(long *)runner;
		
		if(jump_next > largest_chunk)
		{
			largest_chunk = jump_next;
		}
		if(0 > jump_next)
		{
			jump_next *= -1;
			runner = runner + jump_next + STRUCT_SIZE;
		}
		else
		{
			runner = runner + jump_next + STRUCT_SIZE;
		}
	}
	
	return largest_chunk;
}





static void Defragmantation(char *current_location, char *next_location, long amount_of_bytes)
{
	long current_size = *(long *)current_location;
	long next_size = *(long *)next_location;
	
	while(0 != *(long *)next_location && *(long *)current_location < amount_of_bytes)
	{
		current_size = *(long *)current_location;
		next_size = *(long *)next_location;
		
		if(*(long *)current_location > 0 && *(long *)next_location > 0)
		{
			*(long *)current_location = current_size + next_size + STRUCT_SIZE;
			current_size = *(long *)current_location;
			next_location = (next_location + next_size +  STRUCT_SIZE);
		}
		else
		{
			current_location = (current_location + ABS(current_size) +  STRUCT_SIZE);
			next_location = (next_location + ABS(next_size) +  STRUCT_SIZE);
		}
		
	}
	
}


static size_t RealSizeOfBlock(size_t size_of_block)
{
	if(0 == size_of_block % WORD)
	{
		return size_of_block;
	}
	return size_of_block + (WORD - size_of_block % WORD);
}
