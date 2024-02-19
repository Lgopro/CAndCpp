#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"


struct Vector
{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items)   */ 
    size_t  m_size;                   /* actual allocated space for items)*/
    size_t  m_nItems;             /* actual number of items */
    size_t  m_blockSize;       /* the chunk size to be allocated when no space*/
};

struct Vector* ChangeSize(struct Vector* _vector)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return NULL;
	}
	else if(_vector->m_nItems== _vector->m_originalSize)
	{
		_vector->m_items=realloc(_vector->m_items, sizeof(int)*(_vector->m_originalSize+_vector->m_blockSize));
		_vector->m_originalSize+=_vector->m_blockSize;
		return _vector;
	}
	return _vector;
}


ADTErr VectorItemsNum(struct Vector* _vector, int* _numOfItems)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	else
	{
		_numOfItems=_vector->m_items;
		return ERR_OK;
	}


}
ADTErr VectorSet(struct Vector* _vector, size_t _index, int  _item)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	else
	{
		_vector->m_items[_index]=_item;
		return ERR_OK;
	}



}

ADTErr VectorGet(struct Vector* _vector, size_t _index, int* _item)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	else if(_vector->m_nItems==0)
	{
		
		printf("There are no items to choose from!\nPlease enter numbers to the end of the vector first\n");
		return ERR_UNDERFLOW;
	
	}
	else
	{
	_item=&_vector->m_items[_index];
	return ERR_OK;
	}
}

int GetIndex(struct Vector* _vector)
{
	int index;
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	else if(_vector->m_nItems==0)
	{
		
		printf("There are no items to choose from!\nPlease enter numbers to the end of the vector first\n");
		return ERR_UNDERFLOW;
	
	}
	do
	{
	printf("Please enter the index of the item you want to get a pointer to\n");
	scanf("%d",&index);
	}while(index<0 || index>_vector->m_nItems);
	
	return index;
	



}
ADTErr VectorDeleteEnd(struct Vector* _vector, int* _item)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	else if(_vector->m_nItems==0)
    {
    	printf("There is nothing to remove!\nPlease add an item first\n");
    	return ERR_UNDERFLOW;		
    }
	else
	{
	_item=&_vector->m_items[_vector->m_nItems];
	_vector->m_nItems--;
	return ERR_OK;
	}

}

int GetItem(struct Vector* _vector)
{
	int item;
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ERR_ALLOCATION_FAILED;
	}
	
	printf("Please enter a number for the item you want to join to the vector:\n");
	scanf("%d", &item);
	getchar();
	return item;
}
ADTErr VectorAddEnd(struct Vector* _vector,  int  _item)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        	return ERR_ALLOCATION_FAILED;
	}
	_vector->m_items[_vector->m_nItems]=_item;
	_vector->m_nItems++;
	return ERR_OK;


}
void VectorDestroy(struct Vector* _vector)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return ;
	}
	else 
	{
	    if(_vector->m_items)
	    {
	        free(_vector->m_items);
	    }
		free(_vector);
		printf("The vector was destroyed succsesfully\n");
		return ;
	}
}


void VectorPrint(struct Vector* _vector)
{
	int i;
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return;
	}
	else if(_vector->m_nItems==0)
	{
		printf("The was a mistake\nThere are no items to print\n");
        return;
	}
	
	for(i=0;i<=_vector->m_nItems;i++)
	{
		printf("The %d item is: %d\n", i,_vector->m_items[i]);
	}
	return;
}

struct Vector* Enter(struct Vector* _vector)
{	

	size_t initsize,blocksize;
	printf("Please enter the initual size of the Vector:\n");
	scanf("%lu", &initsize);
	getchar();
	printf("Please enter the block size of the Vector:\n");
	scanf("%lu", &blocksize);
	getchar();
	_vector=VectorCreate(initsize,blocksize);
	return _vector;
}

struct Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize)

{
	struct Vector* Vector=NULL;
	int* items = NULL;
 	if(NULL == (Vector=(struct Vector*)malloc(sizeof(struct Vector)*1)))
   {
   		printf("The function AD dident created\nPlease try again\n");
   		return NULL;
   }
   Vector->m_originalSize = _initialSize;
   Vector->m_blockSize = _extensionBblockSize;
   Vector->m_size = _initialSize;
   Vector->m_items = 0;
   items=(int*)malloc(sizeof(int)*Vector->m_originalSize);
   if(NULL == items)
   {
   		printf("The function items dident created\nPlease try again\n");
   		free(Vector);
   		return NULL;
   		
   }
   Vector->m_items = items;
   return Vector;
}

size_t LastIndex(struct Vector* _vector)
{
	size_t index;
	index= Vector->m_items;
	return index;
	

}


