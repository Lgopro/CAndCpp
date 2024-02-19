#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubledlinkedlist.h"
#define MAGICNUM 8577438

/*
Description: Function gets data input from user.
Input: Pointer to the original list.
Output: 0 if list not initialized or the data number added by the user.
Complexity: o(1).
*/
int GetData(struct List* _list);
/*
Description: Function print the text for each error.
Input: Error type.
Output: Void.
Complexity: o(1).
*/
void PError(ADTErr _error);


struct Node
{
	int m_data;
	Node* m_next;
	Node* m_prev;
};


struct List
{
	Node m_head;
	Node m_tail;
	int m_magic;
};
void PError(ADTErr _error)
{	
        if(_error==ERR_OK)
        {
                printf("Operation successful\n\n");
        }
        if(_error==ERR_GENERAL)
        {
                printf("General error.Please try again\n\n");
        }
        if(_error==ERR_NOT_INITIALIZED)
        {
                printf("Not initialized. Please try again\n\n");
        }
        if(_error==ERR_REALLOCATION_FAILED)
        {
                printf("Relocation failed. Please try again\n\n");
        }
        if(_error==ERR_UNDERFLOW)
        {
                printf("There is nothing to remove. Please try again\n\n");
        }
        if(_error==ERR_OVERFLOW)
        {
                printf("Cant add anymore. Please try again\n\n");
        }
        if(_error==ERR_WRONG_INDEX)
        {
                printf("Wrong index\n\n");
        }
}
List* ListCreate(void)
{
	struct List* List=NULL;
 	if(NULL == (List=(struct List*)malloc(sizeof(struct List)*1)))
 	{
   		return NULL;
    }
    List->m_head.m_prev=NULL;
    List->m_head.m_next=&List->m_tail;
    List->m_tail.m_prev=&List->m_head;
    List->m_tail.m_next=NULL;
    List->m_head.m_data=0;
    List->m_tail.m_data=0;
    List->m_magic=MAGICNUM;
	return List;
}

void ListDestroy(struct List* _list)
{
	if(_list==NULL)
	{
        return ;
	}
	if(_list && _list->m_magic == MAGICNUM)
	{
	    
		free(_list);
		_list->m_magic=0;
		return ;
	}
}

int GetData(struct List* _list)
{
	int data;
	if(_list==NULL)
	{
        return 0;
	}
	
	printf("Please enter the data number:\n");
	scanf("%d", &data);
	getchar();
	return data;
}
ADTErr ListPushHead(struct List* _list,int _data)
{
	struct Node* newhead;
	if(NULL == _list)
	{
		return ERR_NOT_INITIALIZED;
	
	}
	newhead=(struct Node*)malloc(sizeof(struct Node));
	if(NULL == newhead)
	{
		return ERR_ALLOCATION_FAILED;
	
	}
	newhead->m_data=_data;
	newhead->m_prev=&_list->m_head;
	newhead->m_next=_list->m_head.m_next;
	newhead->m_next->m_prev=newhead;
	_list->m_head.m_next=newhead;
	return ERR_OK;
}
ADTErr ListPushTail(List* _list,int _data)
{
	struct Node* newtail;
	if(NULL == _list)
	{
		return ERR_NOT_INITIALIZED;
	
	}
	newtail=(struct Node*)malloc(sizeof(struct Node));
	if(NULL == newtail)
	{
		return ERR_ALLOCATION_FAILED;
	
	}
	newtail->m_data=_data;
	newtail->m_next=&_list->m_tail;
	newtail->m_prev=_list->m_tail.m_prev;
	newtail->m_prev->m_next=newtail;
	_list->m_tail.m_prev=newtail;
	return ERR_OK;
}
ADTErr ListPopHead(List* _list,int* _data)
{
	struct Node* pophead;
	if(NULL == _list || NULL == _data)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return ERR_UNDERFLOW;
	}
	pophead=_list->m_head.m_next;
	*_data=pophead->m_data;
	pophead->m_next->m_prev=&_list->m_head;
	pophead->m_prev->m_next=_list->m_head.m_next;
	free(pophead);
	return ERR_OK;
}
ADTErr ListPopTail(List* _list,int* _data)
{
	struct Node* poptail;
	if(NULL == _list || NULL == _data)
	{
		return ERR_NOT_INITIALIZED;
	
	}
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return ERR_UNDERFLOW;
	}
	poptail=_list->m_tail.m_prev;
	*_data=poptail->m_data;
	poptail->m_next->m_prev=_list->m_tail.m_prev;
	poptail->m_prev->m_next=&_list->m_tail;
	free(poptail);
	return ERR_OK;
}


int ListIsEmtpy(List* _list)
{
	if(NULL == _list)
	{
		return NOT_INIT;
	
	}
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return EMPTY;
	}
	
		return NOT_EMPTY;
}
size_t ListCountItems(List* _list)
{
	size_t items=1;
	struct Node* counter;
	
	if(NULL == _list)
	{
		return NOT_INIT;
	}
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return ZERO_ITEMS;
	}
	counter=_list->m_head.m_next;
	while(counter->m_next!=&_list->m_tail)
	{
		items++;
		counter= counter->m_next;
	}
	return items;
}

void ListPrintf(List* _list)
{	
	struct Node* printer;
	size_t items;
	int item=0;
	if(NULL == _list)
	{
		return;
	}
	items=ListCountItems(_list);
	if(items == 0)
	{
		printf("There are no items to print!\n");
		return;
	}
	printer=_list->m_head.m_next;
	do
	{
		item++;
		printf("The %d data item in the list is: %d\n", item, printer->m_data);
		printer=printer->m_next;
	}while(printer!=&_list->m_tail);
	
	return;

}



