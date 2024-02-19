
#include <stdio.h>
#include <stdlib.h> /*size_t*/
#include "ListStructs.h"

#include "ListIt.h"
#include "List.h"





static void RemoveGen(Node* _delete);
ListItr ListItr_InsertBefore(ListItr _itr, void* _element);

static void InsertGen(Node* _newNode, Node* _nextNode)
{
	_newNode->m_prev = _nextNode->m_prev;
	_newNode->m_next = _nextNode;
	_nextNode->m_prev->m_next = _newNode;
	_nextNode->m_prev = _newNode;
}

static void RemoveGen(Node* _delete)
{
	_delete->m_next->m_prev = _delete->m_prev;
	_delete->m_prev->m_next = _delete->m_next;
	free(_delete);
}


ListItr ListItr_Begin(const List* _list)
{
	if(NULL == _list)
	{
		return NULL;
	}
	return (ListItr)_list->m_head.m_next;
}

ListItr ListItr_End(const List* _list)
{
	if(NULL == _list)
	{
		return NULL;
	}
	return (ListItr)&_list->m_tail;
}

int ListItr_Equals(const ListItr _a, const ListItr _b)
{
	if( NULL == _a || NULL == _b)
	{
		return 0;
	}
	return (_a == _b);
}

ListItr ListItr_Next(ListItr _itr)
{
	if(NULL == _itr)
	{
		return NULL;
	}
	return (ListItr)((Node*) _itr)->m_next;
}
ListItr ListItr_Prev(ListItr _itr)
{
	if(NULL == _itr || (ListItr)((Node*) _itr)->m_prev == NULL)
	{
		return NULL;
	}
	if(((Node*) _itr)->m_prev->m_prev == NULL)
	{
		return _itr;
	}
	return (ListItr)((Node*) _itr)->m_prev;
}

void* ListItr_Get(ListItr _itr)
{
	if(NULL == _itr || (ListItr)((Node*) _itr)->m_next == _itr)
	{
		return NULL;
	}
	return (ListItr)((Node*) _itr)->m_data;
}


void* ListItr_Set(ListItr _itr, void* _element)
{
	void* data;
	if(NULL == _itr)
	{
		return NULL;
	}
	data = (ListItr)((Node*) _itr)->m_data;
	((Node*) _itr)->m_data = _element;
	return data;
}



ListItr ListItr_InsertBefore(ListItr _itr, void* _element)
{
	
	Node* newnode;
	if( NULL == _itr)
	{
		return NULL;
	}
	newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->m_data = _element;
	InsertGen(newnode , (Node*)_itr);
	return (ListItr)newnode;
}


void* ListItr_Remove(ListItr _itr)
{
	void* data;
	if( NULL ==  _itr)
	{
		return NULL;
	}
	data = (ListItr)((Node*) _itr)-> m_data;
	RemoveGen((Node*)_itr);
	return data;	
}
