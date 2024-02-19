/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 20/06/2023
*/
#include "heap.h"
#include "pqueue.h"


#include <assert.h>
#include <stdlib.h>


struct PQueue
{
	heap_t *heap;
};

pq_t *PQCreate(int (*compare)(const void *,const void *))
{
    pq_t *queue = NULL;

    assert(compare);

    queue = (pq_t *)malloc(sizeof(pq_t));
    if(NULL == queue)
    {
        return NULL;
    }
    queue->heap = HeapCreate(compare);
     if(NULL == queue->heap)
    {
        free(queue);
        return NULL;
    }
    return queue;
}

void PQDestroy(pq_t *pq)
{
    assert(pq);
    HeapDestroy(pq->heap);
    free(pq);
    pq = NULL;
}

int PQEnqueue(pq_t *pq, void *data)
{
    assert(pq);
    assert(data);

    return HeapPush(pq->heap, (const void *)data);
}

void *PQDequeue(pq_t *pq)
{
    void *data = NULL;
    assert(pq);
    data = HeapPeek(pq->heap);
    HeapPop(pq->heap);
    return data;
}

void *PQPeek(const pq_t *pq)
{
    assert(pq);
    return HeapPeek(pq->heap);
}

void *PQErase(pq_t *pq, int (*is_match)(const void *, const void *), void *param)
{
    size_t size_before = 0;
    size_t size_after = 0;

    assert(pq);
    assert(is_match);

    size_before = HeapSize((const heap_t *)pq->heap);
    HeapRemove(pq->heap, param, is_match);
    size_after = HeapSize((const heap_t *)pq->heap);
    if(size_before == size_after)
    {
        return NULL;
    }
    return param;
}

void PQClear(pq_t *pq)
{

    assert(pq);

    while(1 != HeapIsEmpty((const heap_t *)pq->heap))
    {
        HeapPop(pq->heap);
    }
}

size_t PQSize(const pq_t *pq)
{
    assert(pq);
    return HeapSize((const heap_t *)pq->heap);
}

int PQIsEmpty(const pq_t *pq)
{
    assert(pq);
    return HeapIsEmpty((const heap_t *)pq->heap);
}

