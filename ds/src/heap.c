/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 20/06/2023
*/
#include "heap.h"

#define FAIL -1
#define SUCCESS 0


#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <string.h> /**/



static void HeapifyDown(heap_t *heap, size_t index);
static void GenericSwap(void *var1, void *var2, size_t size_of_element);
static void HeapifyUp(heap_t *heap);
static void GetRightLocation(heap_t *heap, size_t index);


heap_t *HeapCreate(int (*compare)(const void*, const void*))
{
    heap_t *heap = NULL;

    assert(compare);

    heap = (heap_t *)malloc(sizeof(heap_t));
    if(NULL == heap)
    {
        return (NULL);
    }

    heap->arr = DVectorCreate(sizeof(void *), 100);
    if(NULL == heap->arr)
    {
        free(heap);
        return (NULL);
    }
    heap->compare = compare;

    return (heap);
}


void HeapDestroy(heap_t *heap)
{
    assert(heap);

    DVectorDestroy(heap->arr);
    free(heap);
    heap = NULL;
}


int HeapIsEmpty(const heap_t *heap)
{
    assert(heap);
    return (0 == DVectorSize(heap->arr));
}

size_t HeapSize(const heap_t *heap)
{
    assert(heap);
    return (DVectorSize(heap->arr));
}

void *HeapPeek(const heap_t *heap)
{
     assert(heap);
     if(HeapIsEmpty(heap))
     {
        return NULL;
     }
     return (*(void **)DVectorGetAccessToElement(heap->arr, 0));
}


int HeapPush(heap_t *heap, const void *data)
{
    int status = 0;
    

    assert(heap);
    assert(data);

    status = DVectorPushBack(heap->arr, &data);
    if(0 != status)
    {
        return (FAIL);
    }
    HeapifyUp(heap);
    
    return (SUCCESS);
}


static void HeapifyUp(heap_t *heap)
{
    size_t index = 0;
    
    index = HeapSize(heap);
    GetRightLocation(heap,  index - 1);
}


static void GetRightLocation(heap_t *heap, size_t index)
{
    size_t parent_index = 0;

    if(0 == index)
    {
        return;
    }
    parent_index = (index - 1) / 2;
    if(0 < heap->compare(*(void **)DVectorGetAccessToElement(heap->arr, index), 
                         *(void **)DVectorGetAccessToElement(heap->arr, parent_index)))
    {
        return;
    }
    else
    {
        GenericSwap(DVectorGetAccessToElement(heap->arr, index), 
                    DVectorGetAccessToElement(heap->arr, parent_index), sizeof(void *));
        GetRightLocation(heap, parent_index);
    }
}

void HeapPop(heap_t *heap)
{
    void *first_element = NULL;
    void *last_element = NULL;

    assert(heap);
    if(HeapIsEmpty(heap))
    {
        return;
    }
    else if(1 == HeapSize(heap))
    {
        DVectorPopBack(heap->arr);
        return;
    }
    else
    {
        first_element = DVectorGetAccessToElement(heap->arr, 0);
        last_element = DVectorGetAccessToElement(heap->arr, HeapSize(heap) - 1);
        GenericSwap(first_element, last_element, sizeof(void *));
        DVectorPopBack(heap->arr);
        HeapifyDown(heap, 0);
    }
}
static void HeapifyDown(heap_t *heap, size_t index)
{
    void * child_left = NULL;
    void * child_right = NULL;
    size_t child_left_index = index * 2 + 1;
    size_t child_right_index = index * 2 + 2;

    if(child_left_index >= HeapSize(heap))
    {
        child_left = NULL;
    }
    else
    {
        child_left = DVectorGetAccessToElement(heap->arr, child_left_index);
    }
    if(child_right_index >= HeapSize(heap))
    {
        child_right = NULL;
    }
    else
    {
        child_right = DVectorGetAccessToElement(heap->arr, index * 2 + 2);
    }

    if(NULL == child_left && NULL == child_right)
    {
        return;
    }
    if(NULL != child_left && NULL == child_right)
    {
        if(0 < heap->compare(*(void **)DVectorGetAccessToElement(heap->arr, index),
                            *(void **)DVectorGetAccessToElement(heap->arr, child_left_index)))
        {
            GenericSwap(DVectorGetAccessToElement(heap->arr, child_left_index), 
                        DVectorGetAccessToElement(heap->arr, index), sizeof(void *));
            return;
        }
    }
    else
    {
        if(0 < heap->compare(*(void **)DVectorGetAccessToElement(heap->arr, child_left_index), 
                             *(void **)DVectorGetAccessToElement(heap->arr, child_right_index)))
        {
            if(0 < heap->compare(*(void **)DVectorGetAccessToElement(heap->arr, child_right_index), 
                                 *(void **)DVectorGetAccessToElement(heap->arr, index)))
            {
                return;
            }
            else
            {
                GenericSwap(DVectorGetAccessToElement(heap->arr, index), 
                            DVectorGetAccessToElement(heap->arr, child_right_index), sizeof(void *));
                HeapifyDown(heap, child_right_index);
            }
        }
        else
        {
            if(0 < heap->compare(*(void **)DVectorGetAccessToElement(heap->arr, child_left_index), 
                                 *(void **)DVectorGetAccessToElement(heap->arr, index)))
            {
                return;
            }
            else
            {
                GenericSwap(DVectorGetAccessToElement(heap->arr, index), 
                            DVectorGetAccessToElement(heap->arr, child_left_index), sizeof(void *));
                HeapifyDown(heap , child_left_index);
            }
        }
    }

} 


static void GenericSwap(void *var1, void *var2, size_t size_of_element)
{
	size_t i = 0;
    char temp = 0;
    (void)size_of_element;
	
	assert(var1);
	assert(var2);

	assert(0 < size_of_element);
	while(i < size_of_element)
	{
		temp = *(((char *)var1) + i);
		*(((char *)var1) + i) = *(((char *)var2) +i);
		*(((char *)var2) +i) = temp;
		++i;
	}
}




void *HeapRemove(heap_t *heap, void *data, int(*is_match)(const void *, const void *))
{
    size_t size = 0;
    size_t i = 0;
    int status = 0;
    assert(heap);
	assert(data);
    assert(is_match);

    size = HeapSize((const heap_t *)heap);
   
    for(i = 0; i < size; ++i)
    {
        if(1 == is_match(*(void **)DVectorGetAccessToElement(heap->arr, i) , data))
        {
            GenericSwap(DVectorGetAccessToElement(heap->arr, size - 1), 
                        DVectorGetAccessToElement(heap->arr, i), sizeof(void *));
            status = DVectorPopBack(heap->arr);
            if(0 == status)
            {
                HeapifyDown(heap , i);
                return (data);
            }
        }
    }
    return (NULL);
}
