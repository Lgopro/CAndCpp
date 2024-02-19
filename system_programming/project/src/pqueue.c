/*
Rev: Maria Ponomariov.
Dev: Leonid Golovko
status: finished
date: 17/05/2023
*/


#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "pqueue.h"

#define SUCCESS (0)
 
#define FAIL (1) 

struct PQueue
{
	sort_list_t *list;
};





pq_t *PQCreate(int (*compare)(const void *,const void *))
{

	pq_t *pq = NULL;
	
	assert(NULL != compare);
	
	pq =(pq_t *)malloc(sizeof(pq_t));
	if(NULL == pq)
	{
		return (NULL);
	}
	
	pq->list = SortListCreate((int (*)(void *,const void *))compare);
	if(NULL == pq->list)
	{
		free(pq);
		return (NULL);
	}	

	return (pq);
}


void PQDestroy(pq_t *pq)
{

	assert(NULL != pq);
	
	SortListDestroy(pq->list);

	free(pq);
	pq = NULL;
}



int PQEnqueue(pq_t *pq, void *data)
{

	assert(NULL != pq);
	assert(NULL != data);
	
	if(SortListIsEqual(SortListEnd((const sort_list_t *)pq->list) , 
									SortListInsert(pq->list, data)))
	{
		return (FAIL);
	}
	return (SUCCESS);
}



void *PQDequeue(pq_t *pq)
{
	assert(NULL != pq);
	
	
	return (SortListPopFront(pq->list));
}


void *PQErase(pq_t *pq, int (*is_match)(const void *, const void *), void *param)
{
	sort_iter_t iter;
	
	assert(NULL != pq);
	assert(NULL != param);
	assert(NULL != is_match);
	iter = SortListFindIf(SortListBegin((const sort_list_t *)pq->list), 
						  SortListEnd((const sort_list_t *)pq->list), 
						  (int (*)(void *,const void *))is_match, param);
	
	if(SortListIsEqual(SortListEnd((const sort_list_t *)pq->list) , iter))
	{
		return NULL;
	}
	SortListRemove(iter);
	return param;
}


void PQClear(pq_t *pq)
{
	assert(NULL != pq);
	
	while(!PQIsEmpty((const pq_t *)pq))
	{
		PQDequeue(pq);
	}

}

size_t PQSize(const pq_t *pq)
{
	assert(NULL != pq);
	
	return (SortListSize((const sort_list_t *)pq->list));
}

int PQIsEmpty(const pq_t *pq)
{
	assert(NULL != pq);
	
	return (SortListIsEmpty((sort_list_t *)pq->list));

}

void *PQPeek(const pq_t *pq)
{
	assert(NULL != pq);
	
	if(0 < PQSize(pq))
	{
		return (SortListGetData(SortListBegin((const sort_list_t *)pq->list)));
	}
	
	return (NULL);
	

}
