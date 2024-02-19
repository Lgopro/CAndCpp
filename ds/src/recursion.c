/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 11/06/2023
*/

#include <assert.h> /*assert*/
#include <string.h> /*strncmp*/


#include "recursion.h"


struct Node
{
	void *data;
	Node *next;
};


int FibonacciRecurcive(int element_index)
{

	if(1 >= element_index)
	{
		return element_index;
	}
	return (FibonacciRecurcive(element_index - 1) + FibonacciRecurcive(element_index - 2));
}


int FibonacciIterative(int element_index)
{
	int current_iter = 1;
	int prev_iter = 0;
	int result = 0;
	int i = 0;
	for(i = 2; i <= element_index; ++i)
	{
		result = current_iter + prev_iter;
		prev_iter = current_iter;
		current_iter = result;
	}
	return (result);
}


size_t Strlen(const char *s)
{
	size_t counter = 0;
	assert(s);
	
    if('\0' != *(s + 1))
    {
		counter = Strlen((s + 1));  
    }
    return (counter + 1);
}



int StrCmp(const char *s1, const char *s2)
{
	int status = 0;
	assert(s1);
	assert(s2);
	if('\0' == *s1 && '\0' == *s2)
	{
		return (0);
	}
	if(*s1 == *s2)
	{
		status = StrCmp((char *)(s1 + 1), (char *)(s2 + 1));
		return (status);
	}
	
	if(('\0' == *s1 && '\0' != *s2))
	{
		return (-1);
	}
	else if(('\0' != *s1 && '\0' == *s2))
	{
		return (1);
	}
	
	return (*s1 - *s2); /*TODO change in 78 and 82*/
}
char *StrCat(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	if('\0' == *dest)
	{
		StrCpy(dest, src);
		return (dest);
	}
	StrCat(dest + 1 ,src);
	return (dest);

}
char *StrStr(const char *haystack, const char *needle)
{
	
    assert(haystack);
    assert(needle);

    if('\0' == *haystack)
	{
		return NULL;
	}
    if(0 == strncmp(haystack, needle, Strlen(needle) - 1))
	{
		return (char *)haystack;
	}
	
    return StrStr(haystack + 1, needle);
}


char *StrCpy(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	if('\0' != *src)
	{
		StrCpy(dest + 1, src + 1);
	}
	*dest = *src;
	return ((char *)src);
}

Node* FlipList(Node* node)
{
	Node* temp = NULL;
	assert(node);
	
	if(NULL == node->next)
	{
		return (node);
	}
	temp = FlipList(node->next);
	node->next->next = node;
	node->next = NULL;
	return (temp);
}


void SortedStackInsert(stack_t *stack, int element)
{
	int value = 0;
   
    if (StackIsEmpty((const stack_t *)stack) || element < *(int *)StackPeek((const stack_t *)stack))
    {
        StackPush(stack, (const void *)&element);
        return;
    }
    
    value = *(int *)StackPeek((const stack_t *)stack);
    StackPop(stack);
    SortedStackInsert(stack, element);
    StackPush(stack, (const void *)&value);
}
 


void Sort(stack_t *stack)
{
	int value = 0;
    
    if (StackIsEmpty((const stack_t *)stack)) 
    {
        return;
    }
    value = *(int *)StackPeek((const stack_t *)stack);
    StackPop(stack);
    Sort(stack);
    SortedStackInsert(stack, value);
}
