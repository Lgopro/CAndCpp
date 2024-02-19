#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
#define MAGICNUM 8577438

struct Stack
{
    Vector *vector;
    int m_magic;
};



void PrintError(ADTErr _error)
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
	if(NULL == Stack->vector)
	{
		free(Stack);
		return NULL;
	}
    return Stack;
  
}

void StackDestroy(Stack* _stack)
{
	if(_stack==NULL)
	{
		printf("The was a mistake\nPlease create the stack first\n");
        return ;
	}
	if(_stack && _stack->m_magic == MAGICNUM) 
	{
		VectorDestroy(_stack->vector);
		_stack->m_magic=0;
		free(_stack);
	}
}


ADTErr StackPush (struct Stack* _stack, int  _item)
{
	if(_stack==NULL)
	{
        return ERR_NOT_INITIALIZED;
	}
	_stack->vector=ChangeSize(_stack->vector);
	return VectorAddEnd(_stack->vector,_item);
}

ADTErr StackPop(struct Stack* _stack, int* _item)
{
	
	if(NULL == _stack || NULL==_item)
	{
        return ERR_NOT_INITIALIZED;
	}
	else
	{
		return VectorDeleteEnd(_stack->vector, _item);
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

ADTErr StackPrint (Stack* _stack)
{	
	size_t index;
	index=LastIndex(_stack->vector);
	if(index==0)
	{
		return ERR_UNDERFLOW;
	}
	else
	{
		VectorPrint(_stack->vector);
		return ERR_OK;
	}
}

int GetItemToStack(struct Stack* _stack)
{
	int item;
	item=GetItem(_stack->vector);
	return item;
}

int StackIsEmpty (Stack* _stack)
{
	size_t index;
	index=LastIndex(_stack->vector);
	if(index==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
