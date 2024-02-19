
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "heap.h"




#define PARENT(i) (i-1)/2
#define LEFT(i) 2*(i)+1
#define RIGHT(i) (2*(i)+2)
#define MAGICNUM 546465
#define SMALLESTINT -2147483647
static void Heapify(Heap* _heap,int numofitems);
static void Swap(Heap* _heap, size_t _itemchange,size_t _itemfather);
struct Heap
{
	Vector* m_vec;
	size_t  m_heapSize;
	int m_magic;
};



Heap* HeapBuild(Vector* _vec)
{
	int numofitems,index;
	struct Heap* Heap=NULL;
	if(NULL == _vec)
	{
        return NULL;
	}
 	if(NULL == (Heap=(struct Heap*)malloc(sizeof(struct Heap))))
 	{
   		return NULL;
    }
    Heap->m_magic = MAGICNUM;
    Heap->m_vec = _vec;
    VectorItemsNum(_vec, &numofitems);
    Heap->m_heapSize = (size_t)numofitems;
  	index = PARENT(numofitems-1);
  	if( Heap->m_heapSize <= 1)
  	{
  		return Heap;
  	}
    while(index >= 0)
    {
    	Heapify(Heap, index);
    	index--;
    }
	return Heap;
}

int HeapItemsNum(Heap* _heap)
{
	if(NULL == _heap)
	{
        return NOT_INIT;
	}
	return (int)_heap->m_heapSize;
}

ADTErr  HeapMax(Heap* _heap, int* _data)
{
	if(_heap == NULL || _data == NULL )
	{
        return ERR_NOT_INITIALIZED;
	}
	VectorGet(_heap->m_vec, 0, _data);
	return ERR_OK;
}


static void Heapify(Heap* _heap,int _index)
{
	int father,left, right,leftindex,rightindex,parentsize;
	if(_heap==NULL)
	{
        return;
	}
	parentsize = PARENT(_heap -> m_heapSize -1);
	while(_index <= parentsize)
	{
		
		leftindex =	LEFT(_index);
		rightindex =RIGHT(_index);
		VectorGet(_heap->m_vec, _index, &father);
		VectorGet(_heap->m_vec, leftindex, &left);
		VectorGet(_heap->m_vec, rightindex, &right);
		
		if(father >= right && father >=left)
		{
			break;
		}
		if(	leftindex < _heap->m_heapSize && father < left && right <= left)
		{
			Swap(_heap,leftindex,_index);
			_index = leftindex;
		}
	
		if( rightindex < _heap->m_heapSize && father < right && left <= right)
		{
			Swap(_heap,rightindex,_index);
			_index = rightindex;
		}
	
	}
}




static void Swap(Heap* _heap, size_t _itemchange,size_t _itemfather)
{
	int change=0,father=0; 
	VectorGet(_heap->m_vec,_itemchange,&change);
	VectorGet(_heap->m_vec,_itemfather,&father);
	VectorSet(_heap->m_vec, _itemchange,father);
	VectorSet(_heap->m_vec, PARENT(_itemchange),change);

}
void HeapPrint(Heap* _heap)
{
	if(_heap==NULL)
	{
        return;
	}
	VectorPrint(_heap->m_vec);
}

void HeapDestroy(Heap* _heap)
{
	if(_heap == NULL)
	{
        return;
	}
	if(_heap && _heap->m_magic == MAGICNUM)
	{
		free(_heap);
		_heap->m_magic = 0;
	}
}


ADTErr HeapInsert(Heap* _heap, int _data)
{
	ADTErr status;
	int index;
	if(_heap == NULL)
	{
        return ERR_NOT_INITIALIZED;
	}
	status=VectorAddEnd(_heap->m_vec, _data);
	if(status == ERR_OK)
	{
		_heap->m_heapSize++;
		index = PARENT(_heap->m_heapSize-1);
		/*bubleup TODO*/
		while(index >= 0)
    	{
    		Heapify(_heap, index);
    		index--;
    	}
		return ERR_OK;
	}
	return ERR_NOT_ADDED;
}


ADTErr HeapExtractMax(Heap* _heap, int* _data)
{
	ADTErr status;
	int index;
	if(_heap == NULL || NULL == _data )
	{
        return ERR_NOT_INITIALIZED;
	}
	/*VectorGet(_heap->m_vec, 0, _data);*/
	Swap(_heap,_heap->m_heapSize,0);
	status=VectorDeleteEnd(_heap->m_vec, _data);
	if(status == ERR_OK)
	{
		_heap->m_heapSize--;
		index = PARENT(_heap->m_heapSize-1);
		/*bubleup TODO*/
		while(index >= 0)
    	{
    		Heapify(_heap, index);
    		index--;
    	}
	}
	return status;
}


