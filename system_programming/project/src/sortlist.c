
/*
Rev: Greg Markovsky
Dev: Leonid Golovko
status: finished
date: 09/05/2023
*/

#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/

#include "sortlist.h"

struct SortList
{
	dlist_t *list;
	compare_t compare;
};

typedef struct IsMatchParam
{
	void *data;
	compare_t cmp;
}is_match_param_t;


static int Compare(void *value1, const void *value2)
{
	return (*(int *)value1 - *(int *)value2);

}

static int MatchFor(void *value1, const void *value2)
{
	return (*(int *)value1 == *(int *)value2);

}


static dlist_iter_t GetDListIter(sort_iter_t iterator)
{
	return iterator.iter;
}

static int IsToInsert(void *data, const void *param)
{
	compare_t cmp = ((is_match_param_t *)param)->cmp;
	void *param_data = ((is_match_param_t *)param)->data;
	return (0 <= cmp(data, param_data));	
}

static sort_iter_t GetSortListIter(dlist_iter_t iterator, sort_list_t *list)
{
	sort_iter_t iterator_sort;
	
	iterator_sort.iter = iterator; 
	
	#ifndef NDEBUG
	
	iterator_sort.list = list;
	
	#endif /*NDEBUG*/
	
	(void)list;
	return iterator_sort;
}

static sort_iter_t GetSortListIterRelease(dlist_iter_t iterator)
{
	sort_iter_t iterator_sort;
	
	iterator_sort.iter = iterator; 

	return iterator_sort;
}


sort_list_t *SortListCreate(compare_t cmp)
{
	sort_list_t *list_sort = NULL;
	
	assert(NULL != cmp);
	
	list_sort = (sort_list_t *)malloc(sizeof(sort_list_t));
	if(NULL == list_sort)
	{
		return NULL;
	}
	
	list_sort->list = DListCreate();
	if(NULL == list_sort->list)
	{
		free(list_sort);
		return NULL;
	}
	
	list_sort->compare = cmp;
	
	return (list_sort);
}


void SortListDestroy(sort_list_t *list)
{
	assert(NULL != list);
	assert(NULL != list->list);
	
	DListDestroy(list->list);
	list->list = NULL;
	
	free(list);
}



sort_iter_t SortListInsert(sort_list_t *list, void *data) 
{	
	sort_iter_t where;
	sort_iter_t status;
	is_match_param_t param = {0};
	
	assert(NULL != list);
	
	param.data = data;
	param.cmp = list->compare;
	
	where = SortListFindIf(SortListBegin(list),
	                       SortListEnd(list), 
	                       IsToInsert, &param);
	
	status.iter = DListInsert(GetDListIter(where), data);
	
	#ifndef NDEBUG
	
	status.list = list;
	
	#endif /*NDEBUG*/
	if(NULL == status.iter)
	{
		return status;
	}
		
	return status;
}


int SortListIsEqual(sort_iter_t iter1 , sort_iter_t iter2)
{

	return DListIsEqual(GetDListIter(iter1) , GetDListIter(iter2));
	
}

sort_iter_t SortListBegin(const sort_list_t *list)
{
	
	assert(NULL != list);

	return  GetSortListIter(DListBegin((const dlist_t *)list->list), 
	                       (sort_list_t *)list);
}

sort_iter_t SortListEnd(const sort_list_t *list)
{
	assert(NULL != list);

	return  GetSortListIter(DListEnd((const dlist_t *)list->list), 
						   (sort_list_t *)list);
}

sort_iter_t SortListNext(sort_iter_t current)
{
	assert(NULL != current.iter);

	#ifndef NDEBUG
	return GetSortListIter(DListNext(GetDListIter(current)), current.list);
	#endif /*NDEBUG*/
	
	return GetSortListIterRelease(DListNext(GetDListIter(current)));
}


sort_iter_t SortListPrev(sort_iter_t current)
{
	assert(NULL != current.iter);
	
	#ifndef NDEBUG
	return GetSortListIter(DListPrev(GetDListIter(current)), current.list);
	#endif /*NDEBUG*/
	
	return GetSortListIterRelease(DListPrev(GetDListIter(current)));
}

size_t SortListSize(const sort_list_t *list)
{

	assert(NULL != list);
	
	return DListSize((const dlist_t *)list->list);
}

int SortListIsEmpty(sort_list_t *list)
{

	assert(NULL != list);
	
	return DListIsEmpty((const dlist_t *)list->list); 

}


void *SortListGetData(sort_iter_t current)
{
	assert(NULL != current.iter);
	
	return DListGetData(GetDListIter(current));

}


void *SortListPopFront(sort_list_t *list)
{

	assert(NULL != list);

	return DListPopFront(list->list);

}



void *SortListPopBack(sort_list_t *list)
{

	assert(NULL != list);

	return DListPopBack(list->list);

}




sort_iter_t SortListRemove(sort_iter_t current)
{

	assert(NULL != current.iter);

	#ifndef NDEBUG
	return GetSortListIter(DListRemove(GetDListIter(current)), current.list);
	#endif /*NDEBUG*/
	
	return GetSortListIterRelease(DListRemove(GetDListIter(current)));
}


sort_iter_t SortListFind(sort_iter_t from, sort_iter_t to, sort_list_t *list, 
						 void *param)
{
	sort_iter_t return_node;
	assert(NULL != from.iter);
	assert(NULL != to.iter);
	assert(NULL != param);
	assert(NULL != list);

	#ifndef NDEBUG
	
		if(from.list == to.list)
		{
			return GetSortListIter(DListFind(GetDListIter(from), 
								   GetDListIter(to),  MatchFor, 
								   (const void *)param), from.list);
		}
		
		return_node.iter = NULL;
		return_node.list = NULL;
		return return_node;
		
	
	#endif /*NDEBUG*/
	(void)return_node;
	(void)list;
	return GetSortListIterRelease(DListFind(GetDListIter(from), GetDListIter(to), 
						   MatchFor, (const void *)param)); /*look for the MatchFor and not list->compare*/
}


int SortListForEach(sort_iter_t from, sort_iter_t to, action_t action, 
				    void *action_param)
{
	
	assert(NULL != from.iter);
	assert(NULL != to.iter);
	
	#ifndef NDEBUG
	
		if(from.list == to.list)
		{
			return DListForEach(GetDListIter(from), GetDListIter(to), action, 
								action_param);
		}
		
		return 1;
		
	
	#endif /*NDEBUG*/

	return DListForEach(GetDListIter(from), GetDListIter(to), action, 
						action_param);
}



sort_iter_t SortListFindIf(sort_iter_t from, sort_iter_t to, is_match_t is_match, void *param)
{
	
	sort_iter_t return_node = from;
	
	assert(NULL != from.iter); 
	assert(NULL != to.iter);
	assert(NULL != param);
		
	#ifndef NDEBUG
	assert(from.list == to.list);
	#endif /*NDEBUG*/
	
	while(!SortListIsEqual(return_node , to) && 
	      !is_match(SortListGetData(return_node) , param))
	{
		return_node = SortListNext(return_node);
	}
	
	return return_node;
		
}


void SortListMerge(sort_list_t *dest, sort_list_t *src)
{
	void *data = NULL;
	sort_iter_t runner_src;
	sort_iter_t runner_dest;
	sort_iter_t from;
	assert(NULL != dest);
	assert(NULL != src);
	
	runner_dest = SortListBegin((const sort_list_t *)dest);
	runner_src = SortListBegin((const sort_list_t *)src);
	
	while(GetDListIter(runner_src) != 
		  GetDListIter(SortListEnd((const sort_list_t *)src)))
	{
		from = runner_src;
		while((0 > Compare(SortListGetData(runner_dest), 
			  (const void *)SortListGetData(runner_src))) && 
			  (GetDListIter(runner_dest) != 
			  GetDListIter(SortListEnd((const sort_list_t *)dest))))
		{
			runner_dest = SortListNext(runner_dest);
	
			if(GetDListIter(runner_dest) == 
			   GetDListIter(SortListEnd((const sort_list_t *)dest)))
			{
				
				DListSplice(GetDListIter(runner_dest), GetDListIter(from), 
							GetDListIter(SortListEnd((const sort_list_t *)src)));
				return;
			}
		}
		while(0 <= Compare(SortListGetData(runner_dest), 
			 (const void *)SortListGetData(runner_src)) && 
			 GetDListIter(runner_src) != 
			 GetDListIter(SortListEnd((const sort_list_t *)src)))
		{
			runner_src = SortListNext(runner_src);
			
		}
		if(SortListIsEqual(runner_src , SortListNext(from)))
		{
			
			data = SortListPopFront(src);
			SortListInsert(dest, data);
		}
		else
		{
			
			DListSplice(GetDListIter(runner_dest), GetDListIter(from), 
			GetDListIter(runner_src));
		}
	
	}
}
