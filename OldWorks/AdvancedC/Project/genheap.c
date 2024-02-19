#include <stdio.h>
#include <stdlib.h> /* malloc and free*/
#include <string.h>
#include "heap.h"
#include "vector.h"
static void Heapify(Heap* _heap,int _index, LessThanComparator _pfLess);
static void BubleUp(Heap* _heap,int _index, LessThanComparator _pfLess);
#define MAGIC 837438



#define PARENT(i) (i-1)/2
#define LEFT(i) 2*(i)+1
#define RIGHT(i) (2*(i)+2)
#define MAGICNUM 546465
#define SMALLESTINT -2147483647

struct Heap
{
	int m_magic;
	Vector* m_vec;
	size_t  m_heapSize;
	LessThanComparator m_func;
};
static void Swap(void* _elem1,void* _elem2, size_t _size)
{
	void* swap = malloc(_size);
	memcpy(swap, _elem1, _size);
	memcpy(_elem1, _elem2, _size);
	memcpy(_elem2, swap, _size);
	free(swap);
}

Heap* Heap_Build(Vector* _vector, LessThanComparator _pfLess)
{
	int numofitems,index;
	struct Heap* Heap=NULL;
	if(NULL == _vector)
	{
        return NULL;
	}
 	if(NULL == (Heap=(struct Heap*)malloc(sizeof(struct Heap))))
 	{
   		return NULL;
    }
    Heap->m_magic = MAGICNUM;
    Heap->m_vec = _vector;
    Heap->m_func = _pfLess;
    Heap->m_heapSize=Vector_Size(_vector);
    numofitems= Vector_Size(_vector);
  	index = PARENT(numofitems-1);
  	if( Heap->m_heapSize <= 1)
  	{
  		return Heap;
  	}
    while(index >= 0)
    {
    	Heapify(Heap, index, _pfLess);
    	index--;
    }
	return Heap;

}

static void Heapify(Heap* _heap,int _index, LessThanComparator _pfLess)
{
	int leftindex,rightindex,parentsize,numofitems;
	void* left = NULL;
	void* right = NULL;
	void* father = NULL;
	if(_heap==NULL)
	{
        return;
	}
	numofitems= Vector_Size(_heap->m_vec);
	parentsize = PARENT(numofitems -1);
	while(_index <= parentsize)
	{
		
		leftindex =	LEFT(_index);
		rightindex = RIGHT(_index);
		Vector_Get(_heap->m_vec, _index, &father);
		Vector_Get(_heap->m_vec, leftindex, &left);
		Vector_Get(_heap->m_vec, rightindex, &right);
		
		
		if(/*father >= right*/ _pfLess(father,right) && /*father >=left*/ _pfLess(father,left))
		{
			break;
		}
		if(	leftindex < _heap->m_heapSize && /*father < left*/ _pfLess(left,father) && /*right <= left*/ _pfLess(left,right))
		{
			/*SwapPtr(&left, &father);*/
			Swap(left,father, sizeof(int));
			_index = leftindex;
		}
	
		if( rightindex < _heap->m_heapSize && /*father < right*/ _pfLess(right,father) && _pfLess(right,left))
		{
			/*SwapPtr(&right, &father);*/
			Swap(right,father, sizeof(int));
			_index = rightindex;
		}
	
	}
}

Vector* Heap_Destroy(Heap** _heap)
{
	Vector* vec;
	if(_heap == NULL && (*_heap)->m_magic != MAGICNUM)
	{
        return NULL;
	}
	if(_heap && (*_heap)->m_magic == MAGICNUM)
	{
		vec = (*_heap)->m_vec;
		(*_heap)->m_magic = 0;
		free(*_heap);
	}
	return vec;

}

const void* Heap_Peek(const Heap* _heap)
{
	void* data;
	if(_heap == NULL || _heap->m_heapSize == 0)
	{
        return NULL;
	}
	Vector_Get(_heap->m_vec, 0, &data);
	return (const void*)data;

}

size_t Heap_Size(const Heap* _heap)
{
	if(NULL == _heap)
	{
		return 0;
		
	}
	return Vector_Size(_heap->m_vec);
}

Heap_ResultCode Heap_Insert(Heap* _heap, void* _element)
{
	size_t size;
	if(_heap == NULL)
	{
        return HEAP_NOT_INITIALIZED;
	}
	Vector_Append(_heap->m_vec , _element);
	size=Heap_Size(_heap);
	_heap->m_heapSize++;
	BubleUp(_heap, size-1, _heap->m_func);
	
	return HEAP_SUCCESS;
}


static void BubleUp(Heap* _heap,int _index, LessThanComparator _pfLess)
{
	void* son = NULL;
	void* father = NULL;
	int indexfath;
	indexfath = PARENT(_index);
	Vector_Get(_heap->m_vec, _index, &son);
	Vector_Get(_heap->m_vec, indexfath, &father);
	while( indexfath >= 0)
	{
		if(	_pfLess(son,father) )
		{
			Swap(son,father, sizeof(int));
			Vector_Get(_heap->m_vec, indexfath, &son);
			_index = indexfath;
			indexfath = PARENT(_index);
			Vector_Get(_heap->m_vec, indexfath, &father);
		}
		else
		{
			break;
		}	
	}
	return;
}


void* Heap_Extract(Heap* _heap)
{
	void* data = NULL;
	void* smallest = NULL;
	int father;
	Vector_Result status;
	if(_heap == NULL || _heap->m_heapSize == 0)
	{
        return NULL;
	}
	Vector_Get(_heap->m_vec, 0, &data);
	status = Vector_Get(_heap->m_vec, _heap->m_heapSize-1, &smallest);
	if(status == VECTOR_SUCCESS)
	{
		Swap(data, smallest, sizeof(int));
		 Vector_Remove(_heap->m_vec, &smallest);
		_heap->m_heapSize--;
		father=PARENT(_heap->m_heapSize-1);
    	Heapify(_heap, father, _heap->m_func );
	}
	return data;




}

