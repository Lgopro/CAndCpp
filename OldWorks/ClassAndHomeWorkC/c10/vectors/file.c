#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define EXIT 0
#define CREATE_VECTOR 1
#define DESTROY_VECTOR 2
#define ADD_ITEM_TO_END_OF_VECTOR 3
#define REMOVE_LAST_ITEM 4
#define GET_ITEM_TO_POINTER 5
#define GET_ITEM_IN_VECTOR_TO_INDEX 6
#define GET_POINTER_ARRAY_TO_POINTER_ARRAY 7

struct Vector
{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items)   */ 
    size_t  m_size;                   /* actual allocated space for items)*/
    size_t  m_nItems;             /* actual number of items */
    size_t  m_blockSize;       /* the chunk size to be allocated when no space*/
};




typedef enum
{
    
    ERR_OK,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
           
    ERR_STACK_BBBBB = 30
    
  
}ADTErr ;


struct Vector* Enter(struct Vector* _vector);
struct Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize);
void VectorPrint(struct Vector* _vector);
int Printmenu(void);
void VectorDestroy(struct Vector* _vector);
ADTErr VectorAddEnd(struct Vector *_vector,  int  _item);
int GetItem(struct Vector* _vector);
ADTErr VectorDeleteEnd(struct Vector* _vector, int* _item);
ADTErr VectorGet(struct Vector* _vector, size_t _index, int* _item);
int GetIndex(struct Vector* _vector);
ADTErr VectorSet(struct Vector* _vector, size_t _index, int  _item);
ADTErr VectorItemsNum(struct Vector* _vector, int* _numOfItems);
struct Vector* ChangeSize(struct Vector* _vector);


struct Vector* ChangeSize(struct Vector* _vector)
{
	if(_vector==NULL)
	{
		printf("The was a mistake\nPlease create the vector first\n");
        return NULL;
	}
	else
	{
		_vector->m_items=realloc(_vector->m_items, sizeof(int)*(_vector->m_originalSize+_vector->m_blockSize));
		_vector->m_originalSize+=_vector->m_blockSize;
		return _vector;
	}
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
	}while(index<1 || index>_vector->m_nItems);
	
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
	_vector->m_items[_vector->m_nItems+1]=_item;
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
	
	for(i=1;i<=_vector->m_nItems;i++)
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
   		printf("The function meeting dident created\nPlease try again\n");
   		return NULL;
   }
   Vector->m_items = items;
   return Vector;
}





int main()
{
 	
	struct Vector* Vector=NULL;
    int num,item,itemdel,index,getitemfvec,numofitems[1000];
	do
	{
		num=Printmenu();
    switch(num)
    {
    	case CREATE_VECTOR:
    		if(NULL != Vector)
        	{
         		printf("The vector already created. you can destroy vector to create a new one.\n\n"); 
        	}
        	else
        	{
           		Vector=Enter(Vector);
           		
        	}
   		break;
    	case DESTROY_VECTOR:
    		if(Vector==NULL)
        	{
         		printf("\nPlease add an vector first.\n\n"); 
        	}
        	else
        	{
        		VectorDestroy(Vector);
        		Vector=NULL;
    		}
    	break;
    	case ADD_ITEM_TO_END_OF_VECTOR:
    		if(Vector->m_nItems== Vector->m_originalSize-1)
    		{
    			Vector=ChangeSize(Vector);
    		}
    		item=GetItem(Vector);
    		VectorAddEnd(Vector, item);
    	break;
    	case REMOVE_LAST_ITEM:
    		VectorDeleteEnd(Vector,&itemdel);
    	break;
    	
    	case GET_ITEM_TO_POINTER:
    		index=GetIndex(Vector);
    		VectorGet(Vector, index, &getitemfvec);
    	break;
    	case GET_ITEM_IN_VECTOR_TO_INDEX:
    		index=GetIndex(Vector);
    		item=GetItem(Vector);
    		VectorSet(Vector,index,item);
    	break;
    	case GET_POINTER_ARRAY_TO_POINTER_ARRAY:
    		VectorItemsNum(Vector, numofitems);
    	
    	break;
    }
    }while(num!=EXIT); 
    return 0;
}
int Printmenu(void)
{
   int num;
   do
   {
       printf("Please enter one of the folloing options\n");
       printf("1)Create vector\n");
       printf("2)destroy vector\n");
       printf("3)Add item to the end of the vector\n");
       printf("4)Delete last item from vector\n");
       printf("5)Get part of a vector array to a variable \n");
       printf("6)Get selected number to the vector index selected\n");
       printf("7)Get a pointer from vector to array\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>7);
    return num;
}
