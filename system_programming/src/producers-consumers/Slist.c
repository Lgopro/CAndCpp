/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 1/05/2023
*/



#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/



#include "Slist.h"

struct Node
{
	void *value;
	node_t *next;
};

struct SList
{
	node_t *head;
	node_t *tail;
};


slist_t *SListCreate()
{
	node_t *dummy = NULL;
	slist_t *list = (slist_t *)malloc(sizeof(slist_t));
	
	if(NULL == list)
	{
		return NULL;
	}
	
	dummy = (node_t*)malloc(sizeof(node_t));
	
	if(NULL == dummy)
	{
		free(list);
		return NULL;
	}
	
	dummy->next = NULL;
	dummy->value = &(list->tail);
	
	list->head = dummy;
	list->tail = dummy;
	
	
	return (list);
}


void SListDestroy(slist_t *list)
{
	iter_t iterator_current = list->head;
	iter_t iterator_next = list->head;
	
	assert(NULL != list);
	
	while(NULL != iterator_current)
	{
		iterator_next = iterator_current->next;
		
		free(iterator_current);
		
		iterator_current = iterator_next;
	}
	
	free(list);
	list = NULL;
}


iter_t SListFind(iter_t from, iter_t to, const void *value, is_match_t matcher)
{
	int status = 0;
	
	assert(NULL != from);
	assert(NULL != to);
	
	while(from != to)
	{
		status = matcher(from->value, (void *)value);
		
		if(1 == status)  
		{
			return from;
		}
		
		from = from->next;
	}
	
	return (to);
}


iter_t SListInsert(iter_t where, void *value)
{
	iter_t new_node = NULL;
	
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

	new_node->next = where->next;
	new_node->value = where->value;
	
	where->value = value;
	where->next = new_node;
	
	if(NULL == new_node->next)
	{
		*(node_t **)new_node->value = new_node;
	}
	
	return (where);
}


iter_t SListRemove(iter_t where)
{
	iter_t temp = where->next->next;
	
	assert(NULL != where);
	
	where->value = where->next->value;
	
	free(where->next);
	
	where->next = temp;
	
	if(NULL == where->next)
	{
		*(node_t **)where->value = where;
	}
	
	return (where);
}
int Count(void *value1, void *value2)
{
	++*(int *)value2;
	(void)value1;
	return 0;
}

size_t SListCount(const slist_t *list) 
{
	size_t counter = 0;
	
	iter_t iterator = list->head;
	iter_t iterator2 = list->tail;
	
	assert(NULL != list);
	
	SListForEach(iterator,  iterator2, Count, (void *)&counter);
	
	return (counter);
}


iter_t SListEnd(const slist_t *list)
{
	assert(NULL != list);
	
	return (list->tail);
}


iter_t SListBegin(const slist_t *list)
{
	assert(NULL != list);
	
	return (list->head);
}


int SListForEach(iter_t from, iter_t to, action_t action, void *param)  
{
	iter_t temp = from;
	int status = 0;
	assert(NULL != from);
	assert(NULL != to);
	
	while(temp != to)
	{
		status = action(temp->value, param);
		if(status)
		{
			return (status);
		
		}
		temp = temp->next;
	}
	
	return (status);
}


void SListSet(iter_t where, void *value)
{
	assert(NULL != where);
	
	
	where->value = value;
}

void *SListGet(iter_t where)
{
	assert(NULL != where);
	
	return (where->value);
}


iter_t SListNext(iter_t where)
{
	assert(NULL != where);
	
	return (where->next);
}

int SListIterIsEqual(iter_t iter1 , iter_t iter2)
{
	assert(NULL != iter1);
	assert(NULL != iter2);
	
	return (iter1 == iter2) ? 0 : 1;
}

void ListAppend(slist_t *dest, slist_t *src)
{
	iter_t location = NULL;
	iter_t location2 = NULL;
	iter_t location3 = NULL;
	iter_t dummy_src = SListEnd((const slist_t *)src);
	iter_t dummy_dest = SListEnd((const slist_t *)dest);
	void *dummy_src_value = dummy_src->value;
	void *dummy_dest_value = dummy_dest->value;
	
	assert(NULL != dest);
	assert(NULL != src);

	
	location = SListEnd((const slist_t *)dest);
	location2 = SListBegin((const slist_t *)src);
	
	location->value = location2->value;
	location->next = location2->next;
	
	location3 = SListEnd((const slist_t *)src);
	location3->value = dummy_dest_value;
	
	dest->tail = location3;
	
	src->head = location2;
	src->tail = location2;
	
	location2->value = dummy_src_value;
	location2->next = NULL;
}

