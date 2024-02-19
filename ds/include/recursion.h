/*
Rev: 
Dev: Leonid Golovko
status: finished
date: 11/06/2023
*/
#ifndef __RECURSION_H__
#define __RECURSION_H__



#include <stddef.h> /*size_t*/

#include "Stack.h"




typedef struct Node Node;

/*
Description: Sort the Stack from the smallest value to the biggest.
Receive: Valid pointer to the stack.
Return: void.
Time complexity: O(n)
Space complexity: O(n)
*/
void Sort(stack_t *stack);

/*
Description: Imploy the strcat function in a recursive way. 
Copy src to the end of dest.
Receive: Valid pointer to dest and src.
Return: char * to the begining of dest.
Time complexity: O(n)
Space complexity: O(n)
*/
char *StrCat(char *dest, const char *src);
/*
Description: Find the needle in the haystack.
Receive: Valid pointer to haystack and needle.
Return: char * on the play needle begin in haystack and NULL if not found.
Time complexity: O(1)
Space complexity: O(n)
*/
char *StrStr(const char *haystack, const char *needle);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
char *StrCpy(char *dest, const char *src);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
Node* FlipList(Node* node);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t Strlen(const char *s);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
int FibonacciRecurcive(int element_index);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
int FibonacciIterative(int element_index);
/*
Description: Destroy the created struct.
Receive: Pointer to the struct.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
int StrCmp(const char *s1, const char *s2);
#endif /* __RECURSION_H__ */
