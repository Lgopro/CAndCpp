#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"


struct Stack
{
    Vector *vector;
    int m_magic;
};


struct Stack* EnterVariables(struct Stack* _stack)
{	

	size_t initsize,blocksize;
	printf("Please enter the initual size of the stack:\n");
	scanf("%lu", &initsize);
	getchar();
	printf("Please enter the block size of the stack:\n");
	scanf("%lu", &blocksize);
	getchar();
	_stack=StackCreate(initsize,blocksize);
	return _stack;
}



struct Stack* StackCreate (size_t _size, size_t _blockSize)
{
	struct Stack* Stack=NULL;
	if(NULL == (Stack=(struct Stack*)malloc(sizeof(struct Stack)*1)))
   	{
   		printf("The function Stack dident created\nPlease try again\n");
   		return NULL;
   	}
   	Stack->vector=VectorCreate(_size, _blockSize);
    return Stack;
  
}

void StackDestroy(Stack* _stack)
{
	if(_stack==NULL)
	{
		printf("The was a mistake\nPlease create the stack first\n");
        return ;
	}
	else 
	{
		VectorDestroy(_stack->vector);
		free(_stack);
		return;
	}
}


ADTErr StackPush (struct Stack* _stack, int  _item)
{
	if(_stack==NULL)
	{
        return ERR_NOT_INITIALIZED;
	}
	else
	{
		VectorAddEnd(_stack->vector,_item);
		return ERR_OK;
	}
}

ADTErr StackPop(Stack* _stack, int* _item)
{
	ADTErr error;
	if(_stack==NULL)
	{
        return ERR_NOT_INITIALIZED;
	}
	else
	{
		error=VectorDeleteEnd(_stack->vector, _item);
		return error;
	}
}
ADTErr StackTop (Stack* _stack, int* _item)
{
	size_t index;
	if(_stack==NULL)
	{
        return ERR_NOT_INITIALIZED;
	}
	else
	{
		index=LastIndex(_stack->vector);
		VectorGet(_stack->vector,index,_item);
		return ERR_OK;
	}
	





}




