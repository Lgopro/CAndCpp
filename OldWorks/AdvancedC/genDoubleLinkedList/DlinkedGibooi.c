#include <stdio.h>
#include <stdlib.h> /*size_t*/
#include "list.h"
#define MAGICNUM 8577438
typedef struct Node Node;
static void RemoveGen(Node* _delete);
static void InsertGen(Node* _newNode, Node* _nextNode);
struct Node
{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};


struct List
{
	int m_magic;
	Node m_head;
	Node m_tail;
	
};

static void RemoveGen(Node* _delete)
{
	_delete->m_next->m_prev = _delete->m_prev;
	_delete->m_prev->m_next = _delete->m_next;
	free(_delete);
}

static void InsertGen(Node* _newNode, Node* _nextNode)
{
	_newNode->m_prev = _nextNode->m_prev;
	_newNode->m_next = _nextNode;
	_nextNode->m_prev->m_next = _newNode;
	_nextNode->m_prev = _newNode;
	
}


List* List_Create(void)
{
	List* List = NULL;
 	if(NULL == (List=(struct List*)malloc(sizeof(struct List))))
 	{
   		return NULL;
    }
    List->m_head.m_prev = NULL;
    List->m_head.m_next = &List->m_tail;
    List->m_tail.m_prev = &List->m_head;
    List->m_tail.m_next = NULL;
    List->m_head.m_data = NULL;
    List->m_tail.m_data = NULL;
    List->m_magic = MAGICNUM;
	return List;
}


void List_Destroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	size_t i,size;
	struct Node* counter;
	if( (*_pList) == NULL || NULL == _pList )
	{
        return ;
	}
	counter = (*_pList)->m_head.m_next;
	size = List_Size(*_pList);
	if((*_pList) && (*_pList)->m_magic == MAGICNUM)
	{
		if(NULL != _elementDestroy)
		{
			for(i=0; i< size  ;i++)
			{
				
				(*_elementDestroy)((counter)->m_data);
				counter = counter->m_next;
				free(counter->m_prev);
			}
		}
	    (*_pList)->m_magic=0;
		free(*_pList);
		*_pList = NULL;
		return ;
	}
}

size_t List_Size(const List* _list)
{
	size_t items=0;
	struct Node* counter;
	
	if(NULL == _list)
	{
		return 0;
	}
	if(_list->m_head.m_next == &_list->m_tail)
	{
		return 0;
	}
	counter = _list->m_head.m_next;
	while(counter != &_list->m_tail)
	{
		items++;
		counter = counter->m_next;
	}
	return items;
}


List_Result List_PushHead(List* _list, void* _item)
{
	struct Node* newhead;
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	newhead=(struct Node*)malloc(sizeof(struct Node));
	if(NULL == newhead)
	{
		return LIST_ALLOCATION_ERROR;
	}
	newhead->m_data = _item;
	/*newhead->m_prev = &_list->m_head;
	newhead->m_next =_list->m_head.m_next;
	newhead->m_next->m_prev = newhead;
	_list->m_head.m_next = newhead;*/
	InsertGen( newhead, _list->m_head.m_next);
	
	return LIST_SUCCESS;
}


List_Result List_PushTail(List* _list, void* _item)
{
	struct Node* newtail;
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	newtail=(struct Node*)malloc(sizeof(struct Node));
	if(NULL == newtail)
	{
		return LIST_ALLOCATION_ERROR;
	}
	newtail->m_data = _item;
	/*newtail->m_next = &_list->m_tail;
	newtail->m_prev = _list->m_tail.m_prev;
	newtail->m_prev->m_next = newtail;
	_list->m_tail.m_prev = newtail;*/
	InsertGen( newtail, &_list->m_tail);
	return LIST_SUCCESS;
}


List_Result List_PopHead(List* _list, void** _pItem)
{
	struct Node* pophead;
	if(NULL == _list )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(_list->m_head.m_next == &_list->m_tail)
	{
		return LIST_UNDERFLOW;
	}
	pophead = (struct Node*)malloc(sizeof(struct Node));
	
	pophead = _list->m_head.m_next;
	*_pItem = pophead->m_data;
	/*pophead->m_next->m_prev = &_list->m_head;
	pophead->m_prev->m_next = pophead->m_next;*/
	RemoveGen(pophead);
	/*free(pophead);*/
	return LIST_SUCCESS;
}

List_Result List_PopTail(List* _list, void** _pItem)
{
	struct Node* poptail;
	if(NULL == _list )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return LIST_UNDERFLOW;
	}
	poptail = _list->m_tail.m_prev;
	*_pItem = poptail->m_data;
	/*poptail->m_next->m_prev = poptail->m_prev;
	poptail->m_prev->m_next = &_list->m_tail;
	free(poptail);*/
	RemoveGen(poptail);
	return LIST_SUCCESS;

}



