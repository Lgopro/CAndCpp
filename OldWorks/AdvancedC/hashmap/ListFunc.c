

#include <stdio.h>
#include <stdlib.h> /*size_t*/
#include "ListFunc.h"

static ListItr Merge(ListItr _destBegin, ListItr _merge);




static void Swap(ListItr _one, ListItr _two)
{
	void* swap1;
	void* swap2;
	swap1 = ListItr_Get(_one);
	swap2 = ListItr_Get(_two);
	ListItr_Set(_one, swap2);
	ListItr_Set(_two, swap1);
}

/*void Swap(void* _elem1,void* _elem2, size_t _size)
{
	void* swap = malloc(_size);
	memcpy(swap, _elem1, _size);
	memcpy(_elem1, _elem2, _size);
	memcpy(_elem2, swap, _size);
	free(swap);
}*/


ListItr ListItr_FindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	void* data;
	if(NULL == _begin || NULL == _end || _predicate == NULL || _context == NULL)
	{
		return NULL;
	}
	
	while(_begin != _end)
	{
		data = ListItr_Get(_begin);
		if(_predicate(data ,_context))
		{
			return _begin;
		}
		_begin = ListItr_Next(_begin);
	}

	return _end;
}

size_t ListItr_CountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	size_t counter=0;
	if(NULL == _begin || NULL == _end || _predicate == NULL || _context == NULL)
	{
		return 0;
	}
	
	while(_begin != _end)
	{
		if(_predicate(ListItr_Get(_begin),_context))
		{
			counter++;
		}
		_begin = ListItr_Next(_begin);
	}

	return counter;
}


ListItr ListItr_ForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{

	if(NULL == _begin || NULL == _end || _action == NULL || _context == NULL)
	{
		return NULL;
	}
	while(_begin != _end)
	{
		if(_action(ListItr_Get(_begin),_context))
		{
			return _begin;
		}
		_begin = ListItr_Next(_begin);
	}
	return _end;
}


void ListItr_Sort(ListItr _begin, ListItr _end, LessFunction _less)
{

	int swapped;
	ListItr ptr1,next;
	
	if(NULL == _begin || NULL == _end || NULL == _less)
	{
		return;
	}
	 do
    { 
        swapped = 0; 
        ptr1 = _begin; 
  
        while (ListItr_Next( ptr1) != _end ) 
        { 
            if (_less(ListItr_Get(ptr1), ListItr_Get(ListItr_Next( ptr1 )))) 
            {  
            	next = ListItr_Next( ptr1 );
                Swap(ptr1, next); 
                swapped = 1; 
            }
            
            ptr1 = ListItr_Next( ptr1 ); 
        } 
       
         _end = ListItr_Prev(_end);
    } 
    while (swapped); 

}


ListItr ListItr_Splice(ListItr _dest, ListItr _begin, ListItr _end)
{
	ListItr currentNode,try;
	currentNode = _begin;
	if(NULL == _begin || NULL == _end || NULL == _dest)
	{
		return NULL;
	}
	while(currentNode != ListItr_Next(_end))
	{
		try=ListItr_InsertBefore(_dest, ListItr_Get(currentNode));
		printf("%d\n", *(int*)ListItr_Get(currentNode));
		/*if( ListItr_Next(currentNode) == _end)
		{
			ListItr_Remove(currentNode);
			break;
		}
		else
		{*/
			Swap(try, currentNode);
			currentNode = ListItr_Next(currentNode);
			
			ListItr_Remove(ListItr_Prev(currentNode));
		/*}*/
	}
	return _end;
}



ListItr ListItr_Merge(ListItr _destBegin, ListItr _firstBegin, ListItr _firstEnd, ListItr _secondBegin, ListItr _secondEnd, LessFunction _less)
{
	if(NULL == _destBegin || NULL == _firstBegin || NULL == _firstEnd || NULL == _secondBegin || NULL == _secondEnd || NULL == _less)
	{
		return NULL;
	}
	while((_firstBegin != _firstEnd) && (_secondBegin != _secondEnd))
	{
		if(_less(ListItr_Get(_firstBegin),ListItr_Get(_secondBegin)))
		{
			_firstBegin =  Merge(_destBegin, _firstBegin);
		}
		else
		{
			_secondBegin = Merge(_destBegin, _secondBegin);
		}
	}
		while((_firstBegin == _firstEnd) && (_secondBegin != _secondEnd))
		{
			_secondBegin = Merge(_destBegin, _secondBegin);
		}
		while((_firstBegin != _firstEnd) && (_secondBegin == _secondEnd))
		{
			_firstBegin =  Merge(_destBegin, _firstBegin);
		}
		return _destBegin;
}

static ListItr Merge(ListItr _destBegin, ListItr _merge)
{
	ListItr_InsertBefore(_destBegin, ListItr_Get(_merge));
	_merge = ListItr_Next( _merge );
	ListItr_Remove(ListItr_Prev(_merge));
	return _merge;
}

