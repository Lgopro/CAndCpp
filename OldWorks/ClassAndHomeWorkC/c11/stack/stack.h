#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define EXIT 0
#define CREATE_STACK 1
#define DESTROY_STACK 2
#define ADD_ITEM_TO_END_OF_STACK 3
#define REMOVE_LAST_ITEM_FROM_STACK 4
#define GET_ITEM_TO_POINTER 5
#define CHECK_IF_STACK_IS_EMPTY 6
#define PRINT_ALL_STACK 7
typedef struct Stack Stack;



/*
Description: Function get the initual size and the block size of the vector and then goes to the function VectorCreate.
Input: The sctructure of the vector.
Output: The sctructure of the vector that created or NULL if not created.
*/
struct Stack* StackCreate (size_t _size, size_t _blockSize);
void StackDestroy(Stack* _stack);
ADTErr StackPush (Stack* _stack, int  _item);
ADTErr StackPop (Stack* _stack, int* _item);
ADTErr StackTop (Stack* _stack, int* _item);
int StackIsEmpty (Stack* _stack);
void StackPrint (Stack *_stack);
struct Stack* EnterVariables(struct Stack* _stack);

