
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#define MAGIC 837438

struct Vector
{
	int m_magic;
    void*    *m_items;
    size_t  m_originalSize;   /* original allocated space for items)   */ 
    size_t  m_size;                   /* actual allocated space for items)*/
    size_t  m_nItems;             /* actual number of items */
    size_t  m_blockSize;       /* the chunk size to be allocated when no space*/
    
};



Vector* Vector_Create(size_t _initialCapacity, size_t _blockSize)
{

	Vector* Vector=NULL;
	void* items = NULL;
	if(_initialCapacity==0 && _blockSize==0)
	{
		return NULL;
	}
 	if(NULL == (Vector=(struct Vector*)malloc(sizeof(struct Vector)*1)))
   {
   		return NULL;
   }
   Vector->m_originalSize = _initialCapacity;
   Vector->m_blockSize = _blockSize;
   Vector->m_size = _initialCapacity;
   Vector->m_nItems = 0;
   Vector->m_magic = MAGIC;
   items=(void**)malloc(sizeof(void*)*Vector->m_originalSize);
   if(NULL == items)
   {
   		free(Vector);
   		return NULL;
   }
   Vector->m_items = items;
   return Vector;
}



void Vector_Destroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
	int i;

	if(NULL != *_vector && _vector && (*_vector)->m_magic == MAGIC)
	{
		for(i=0; i< (*_vector)->m_nItems && NULL != _elementDestroy ;i++)
		{
			(*_elementDestroy)((*_vector)->m_items[i]);
			
		}
	
	(*_vector)->m_magic = 0;
	free((*_vector)->m_items);
	free(*_vector);
	*_vector= NULL;
	_vector= NULL;
	}
}


Vector_Result Vector_Append(Vector* _vector, void* _item)
{
	if(_vector == NULL || _item == NULL)
	{
        return VECTOR_UNITIALIZED_ERROR;
	}
	if(_vector->m_nItems == _vector->m_originalSize)
	{
		_vector->m_items=(void**)realloc(_vector->m_items, sizeof(void*)*(_vector->m_originalSize+_vector->m_blockSize));
		_vector->m_originalSize+=_vector->m_blockSize;
	}
	_vector->m_items[_vector->m_nItems]=_item;
	_vector->m_nItems++;
	return VECTOR_SUCCESS;
}


Vector_Result Vector_Remove(Vector* _vector, void** _pValue)
{

	if(NULL ==_vector )
	{
        return VECTOR_UNITIALIZED_ERROR;
	}
	if(NULL == _pValue )
	{
        return ERR_NOT_INITIALIZED;
	}
	else if(_vector->m_nItems == 0)
    {
    	return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;		
    }
	
	*_pValue=_vector->m_items[_vector->m_nItems-1];
	_vector->m_nItems--;
	return VECTOR_SUCCESS;
}


Vector_Result Vector_Get(const Vector* _vector, size_t _index, void** _pValue)
{
	if(_vector == NULL)
	{
        return VECTOR_UNITIALIZED_ERROR;
	}
	if(_pValue == NULL)
	{
		 return ERR_NOT_INITIALIZED;
	}
	else if(_vector->m_nItems==0)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	
	*_pValue=_vector->m_items[_index];
	return VECTOR_SUCCESS;

}


Vector_Result Vector_Set(Vector* _vector, size_t _index, void*  _value)
{
	if(_vector == NULL)
	{
        return VECTOR_UNITIALIZED_ERROR;
	}
	if(_value == NULL)
	{
		 return ERR_NOT_INITIALIZED;
	}
	else if(_vector->m_originalSize > _index)
	{
		_vector->m_items[_index]=_value;
		return VECTOR_SUCCESS;
	}
	
	return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
}


size_t Vector_Size(const Vector* _vector)
{
	if(NULL == _vector)
	{
        return 0;
	}
	return _vector->m_nItems;
}

size_t Vector_Capacity(const Vector* _vector)
{
	if(NULL == _vector)
	{
        return 0;
	}
	 return _vector->m_size;
}


size_t Vector_ForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	size_t i;
	void* elem;
	if(NULL == _vector)
	{
        return 0;
	}
	for(i = 1; i <= Vector_Size(_vector); ++i)
	{
    	Vector_Get(_vector, i-1, &elem);
        if(_action(elem, i, _context) == 0)
        {
			break;	
		}
    } 
	return i;
	



}
