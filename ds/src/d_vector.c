/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 25/04/2023
*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <string.h> /*memcpy*/

#define SHRINK_VALUE 125/100
#define QUARTER 25/100

#include "d_vector.h"


typedef enum Vector_Result 
{
	VECTOR_FAIL = -1,
	VECTOR_SUCCESS
	
} Vector_Result;

struct DVector
{
    size_t size;
    size_t capacity;
    size_t element_size;
    char *base_ptr;
};


static char *Resize(dvector_t* vector, size_t new_size)
{
	char *new_container = NULL;
	
	assert(NULL != vector);
	assert(0 < new_size);
	
	
	new_container = realloc(vector->base_ptr, (vector->element_size * new_size)); 
	if(NULL == new_container)
	{
		return NULL;
	}
	vector->base_ptr = new_container;
	vector->capacity = new_size;
	return vector->base_ptr;
}

dvector_t *DVectorCreate(size_t element_size, size_t capacity)
{
	dvector_t* vector = (dvector_t*)malloc(sizeof(dvector_t));
	
	assert(0 < capacity);
	assert(0 < element_size);
	
	
	if(NULL == vector)
	{
		return NULL;
	}
	vector->base_ptr = (char *)malloc(sizeof(char) * capacity * element_size);
	if(NULL == vector->base_ptr)
	{
		free(vector);
		return NULL;
	}
	vector->size = 0;
	vector->capacity = capacity;
	vector->element_size = element_size;
	return vector;
}

void DVectorDestroy(dvector_t* vector)
{
	assert(NULL != vector);
	
	free(vector->base_ptr);
	free(vector);
	vector = NULL;
}

size_t DVectorSize(const dvector_t *vector)
{
	assert(NULL != vector);
	return vector->size;
}


size_t DVectorCapacity(const dvector_t *vector)
{
	assert(NULL != vector);
	return vector->capacity;
}

int DVectorPushBack(dvector_t* vector, const void *element)
{
	char *realoc_check = NULL;
	
	assert(NULL != vector);
	if(vector->size == vector->capacity)
	{
		realoc_check = Resize(vector, vector->capacity * 2);
		if(NULL == realoc_check)
		{
			return VECTOR_FAIL;
		}
	}
	realoc_check = vector->base_ptr + (vector->size * vector->element_size);
	memcpy(realoc_check, element, vector->element_size);
	++vector->size;
	return VECTOR_SUCCESS;
}


int DVectorReserve(dvector_t* vector, size_t new_capacity)
{
	char *realoc_check = NULL;
	
	assert(NULL != vector);
	
	if(new_capacity > vector->capacity)
	{
		realoc_check = Resize(vector, new_capacity);
		if(NULL == realoc_check)
		{
			return VECTOR_FAIL;
		}
	}
		return VECTOR_SUCCESS;
	
}


int DVectorPopBack(dvector_t* vector)
{
	char *realoc_check = NULL;
	
	assert(NULL != vector);
	
	if(vector->size <= vector->capacity * QUARTER)
	{
		realoc_check = Resize(vector, vector->capacity / 2);
		if(NULL == realoc_check)
		{
			return VECTOR_FAIL;
		}
	}
	--vector->size;
	return VECTOR_SUCCESS;
}

int DVectorShrink(dvector_t* vector)
{
	char *realoc_check = NULL;
	assert(NULL != vector);
	
	if(vector->size * SHRINK_VALUE < vector->capacity)
	{
		realoc_check = Resize(vector, vector->size * SHRINK_VALUE);
		if(NULL == realoc_check)
		{
			return VECTOR_FAIL;
		}
		
	}
	return VECTOR_SUCCESS;
}


void *DVectorGetAccessToElement(const dvector_t *vector, size_t index)
{
	
	char * begin = vector->base_ptr;
	
	assert(NULL != vector);
	assert(index < vector->size);
	
	begin = begin + (index * vector->element_size);
	
	return (void *)begin;
}





