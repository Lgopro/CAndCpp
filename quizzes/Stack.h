/*
Rev: Yaron Margalit
Dev: Leonid Golovko
status: finished
date:19/04/23
*/
#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h> /* size_t, NULL */

typedef struct Stack stack_t;

/*
Description: Create the Stack struct with the capacity and element size specified.
Receive: Max capacity and element size.
Return: Pointer to the created struct.
Time complexity: O(1)
Space complexity: O(1)
*/
stack_t *StackCreate(size_t capacity, size_t element_size);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
void StackDestroy(stack_t *my_stack);
/*
Description: Push the element to the stack.
Receive: Pointer to stack and pointer to the element.
Return: void. 
Time complexity: O(1)
Space complexity: O(1)
*/
void StackPush(stack_t *my_stack, const void *element);
/*
Description: Pop the last element that entered the stack.
Receive: Pointer to stack.
Return: void. 
Time complexity: O(1)
Space complexity: O(1)
*/
void StackPop(stack_t *my_stack);
/*
Description: Get the value of the last element that was entered.
Receive: Const pointer to the stack.
Return: Last value or NULL if there are no elements in the stack. 
Time complexity: O(1)
Space complexity: O(1)
*/
void *StackPeek(const stack_t *my_stack);
/*
Description: Check if stack is empty.
Receive: Const pointer to the stack.
Return: 1 on success and 0 on fail.
Time complexity: O(1)
Space complexity: O(1)
*/
int StackIsEmpty(const stack_t *my_stack);
/*
Description: Check stack size.
Receive: Const pointer to the stack.
Return: The stack size.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t StackSize(const stack_t *my_stack);
/*
Description: Check stack capacity.
Receive: Const pointer to the stack.
Return: he stack capacity.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t StackCapacity(const stack_t *my_stack);

#endif
