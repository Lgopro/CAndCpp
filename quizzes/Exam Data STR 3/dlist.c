
/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 07/05/2023
*/



#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/


#include "dlist.h"

#define FOUND 1
#define FAIL 0
#define SUCCESS 1
#define TRUE 1
struct Node
{
	void *data;
	node_t *next;
	node_t *previous;
};

struct DList
{
	node_t head;
	node_t tail;
};


static void ChangePlaces(dlist_iter_t node1, dlist_iter_t node2)
{
	node1->previous = node2->previous; 
	node2->previous->next = node1;
}

static void Remove(dlist_iter_t where)
{

	dlist_iter_t to_remove = where;
	where->previous->next = where->next;
	where->next->previous = where->previous;

	free(to_remove);

}


static void Insert(dlist_iter_t where, dlist_iter_t new_node)
{

	new_node->previous = where->previous;
	new_node->next = where;
	where->previous->next = new_node;
	where->previous = new_node;

}

dlist_t *DListCreate(void)
{
	
	
	dlist_t *list = (dlist_t *)malloc(sizeof(dlist_t));
	
	if(NULL == list)
	{
		return NULL;	
	}
	
	list->head.data = NULL;
	list->head.next = &list->tail;
	list->head.previous = NULL;
	
	list->tail.data = NULL;
	list->tail.next = NULL;
	list->tail.previous = &list->head;
	return (list);
}

void DListDestroy(dlist_t *list)
{
	
	dlist_iter_t iterator_current = NULL;
	dlist_iter_t iterator_next = NULL;
	
	assert(NULL != list);
	
	iterator_current = list->head.next;
	iterator_next = list->head.next;
	
	if(DListIsEmpty((const dlist_t *)list))
	{
		free(list);
		list = NULL;
		return;
	}

	while(NULL != iterator_current->next)
	{
		iterator_next = iterator_current->next;
		
		free(iterator_current);
		
		iterator_current = iterator_next;
	}
	
	free(list);
	list = NULL;


}


size_t DListSize(const dlist_t *list)
{
	
	dlist_iter_t iterator_current = NULL;
	size_t counter = 0;
	assert(NULL != list);
	
	iterator_current = list->head.next;

	while(&list->tail != iterator_current)
	{
		++counter;
		iterator_current = iterator_current->next;
	}

	return (counter);

}

dlist_iter_t DListNext(dlist_iter_t current)
{	
	assert(NULL != current);
	
	return (current->next);

}

dlist_iter_t DListPrev(dlist_iter_t current)
{	
	assert(NULL != current);
	
	return (current->previous);
}

int DListIsEmpty(const dlist_t *list)
{

	assert(NULL != list);

	return (list->head.next == &list->tail);
}

void DListSetData(dlist_iter_t current, void *data)
{
	assert(NULL != current);

	current->data = data;
}



void *DListGetData(dlist_iter_t current)
{

	assert(NULL != current);
	
	return (current->data);

}


int DListIsEqual(dlist_iter_t iter1 , dlist_iter_t iter2)
{

	assert(NULL != iter1);
	assert(NULL != iter2);

	return (iter1 == iter2);

}



dlist_iter_t DListBegin(const dlist_t *list)
{

	assert(NULL != list);
	
	return (list->head.next);
}


dlist_iter_t DListEnd(const dlist_t *list)
{
	
	assert(NULL != list);
	
	return ((dlist_iter_t)&list->tail);

}



dlist_iter_t DListInsert(dlist_iter_t where, void *data)
{

	dlist_iter_t new_node = NULL;
	
	assert(NULL != where);
	
	new_node = (node_t *)malloc(sizeof(node_t));
	
	if(NULL == new_node)
	{
		while(NULL != where->next)
		{
			where = where->next;
		}
		return (where);
	}

	new_node->data = data;
	
	
	Insert(where, new_node);
	
	return (new_node); 

 
}

dlist_iter_t DListPushBack(dlist_t *list, void *data) 
{
	dlist_iter_t result = NULL;
	
	result = DListInsert(&list->tail, data);
	
	return (result);
}

dlist_iter_t DListPushFront(dlist_t *list, void *data) 
{
	dlist_iter_t result = NULL;
	
	result = DListInsert(list->head.next, data);
	
	return (result);

}



dlist_iter_t DListRemove(dlist_iter_t current)
{

	dlist_iter_t next_iter = NULL;
	
	assert(NULL != current);

	next_iter = current->next;
	
	Remove(current);
	
	return (next_iter);

}


void *DListPopFront(dlist_t *list)
{
	void *deleted_data = NULL;
	
	assert(NULL != list);
	
	if(DListIsEmpty(list))
	{
		return NULL;
	}
	
	deleted_data = list->head.next->data;
	
	DListRemove(list->head.next);
	
	return (deleted_data);

}




void *DListPopBack(dlist_t *list)
{

	void *deleted_data = NULL;
	
	assert(NULL != list);
	
	if(DListIsEmpty(list))
	{
		return NULL;
	}
	
	deleted_data = list->tail.previous->data;
	
	DListRemove(list->tail.previous);
	
	return (deleted_data);


}




dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, int (*match_func)(void *data, const void *param), const void *param) 
{


	int status = 0;
	
	assert(NULL != from);
	assert(NULL != to);
	
	while(from != to)
	{
		status = match_func(from->data, param);
		
		if(FOUND == status)  
		{
			return (from);
		}
		
		from = from->next;
	}
	
	return (to);
}




int DListForEach(dlist_iter_t from, dlist_iter_t to, int(*action_func)(void *data, void *param), void *action_param)
{


	dlist_iter_t runner = from;
	int status = 0;
	
	assert(NULL != from);
	assert(NULL != to);
	
	while(runner != to)
	{
		status = action_func(runner->data, action_param);
		if(status)
		{
			return (status);
		
		}
		runner = runner->next;
	}

	return (status);


}


int DListMultiFind(dlist_iter_t from, dlist_iter_t to, int (*match_func)(void *data, const void *param), const void *param, dlist_t *output_list)
{

	
	int status = 0;
	int return_value = FAIL;
	dlist_iter_t status_push_back = NULL;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	assert(NULL != output_list);

	while(from != to)
	{
		status = match_func(from->data, param);
		
		if(SUCCESS == status)  /*TRUE */
		{
			status_push_back = DListPushBack(output_list, from->data); 
			if(NULL == status_push_back)
			{
				return FAIL;
			
			}
			return_value = SUCCESS;
		}
		
		from = from->next;
	}
	
	return (return_value);

}



dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to)
{

	
	dlist_iter_t from_prev = from->previous;
	
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != where);
	
	ChangePlaces(from, where);
	
	ChangePlaces(where, to);
	
	from_prev->next = to;
	to->previous = from_prev;
	
	return (from);
}



