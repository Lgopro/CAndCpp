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



Vector* Enter(Vector* _ad)
{	

	size_t initsize,blocksize;
	printf("Please enter the initual size of the AD:\n");
	scanf("%lu", &initsize);

	printf("Please enter the block size of the AD:\n");
	scanf("%lu", &blocksize);
	_ad=VectorCreate(initsize,blocksize);
	return _ad;
}

Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize)

{
	Vector* newAD=NULL;
	int* items = NULL;
 	if(NULL == (newAD=(struct Vector*)malloc(sizeof(struct Vector)*1)))
   {
   		printf("The function AD dident created\nPlease try again\n");
   		return NULL;
   }
   newAD->m_originalSize = _initialSize;
   newAD->m_blockSize = _extensionBblockSize;
   newAD->m_size = _initialSize;
   newAD->m_items = 0;
	items=(int*)malloc(sizeof(int)*newAD->m_originalSize);
   if(NULL == items)
   {
   		printf("The function meeting dident created\nPlease try again\n");
   		return NULL;
   }
   newAD->m_items = items;
   return newAD;
}
