
#include <stdlib.h> /*size*/




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
Description: Function get the error and prints the needed text.
Input: Error.
Output:void.
*/
void PrintError(ADTErr _error);
/*
Description: Function get the initual size and the block size of the stack and create it.
Input: Initual size and block size of the stack.
Output: The sctructure of the stack that created or NULL if not created.
*/
struct Stack* StackCreate (size_t _size, size_t _blockSize);
/*
Description: Function get the stack structure and free the stack.
Input: Stack structure.
Output: Void.
*/
void StackDestroy(Stack* _stack);
/*
Description: Function get item selected to the end of the stack.
Input: Stack structure and integer to get to the end of stack.
Output: ERR_OK if the push is successful and ERR_NOT_INITIALIZED if not.
*/
ADTErr StackPush (Stack* _stack, int  _item);
/*
Description: Function get item selected from the end of the stack.
Input: Stack structure and integer to get of the end of stack.
Output: ERR_OK if the push is successful and ERR_NOT_INITIALIZED if not.
*/
ADTErr StackPop (Stack* _stack, int* _item);
/*
Description: Function get apointer to item selected from the end of the stack.
Input: Stack structure and pointer to integer to get of the end of stack.
Output: ERR_OK if the push is successful and ERR_NOT_INITIALIZED if not.
*/
ADTErr StackTop (Stack* _stack, int* _item);
/*
Description: Function check if the stack is empty or not.
Input: The sctructure of the stack.
Output: Returns 1 if stack is empty and 0 if its not.
*/
int StackIsEmpty (Stack* _stack);
/*
Description: Function print the stack.
Input: The sctructure of the stack.
Output: Returns 1 if stack is empty and 0 if its not.
*/
ADTErr StackPrint (Stack *_stack);
/*
Description: Function gets value size and block size of the stack.
Input: The sctructure of the stack.
Output: Returns the structer of the creted stack with the selected value and block size.
*/
struct Stack* EnterVariables(struct Stack* _stack);
/*
Description: Function gets item the user inputs.
Input: The sctructure of the stack.
Output: Returns the value of the item inputed.
*/
int GetItemToStack(struct Stack* _stack);

