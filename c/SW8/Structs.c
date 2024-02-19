/*
Rev: Amitai Bar
Dev: Leonid Golovko
status: finished
date:04/04/23
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*free*/
#include <string.h> /*strcpy*/
#include <assert.h> /*assert*/
#include "Structs.h"



/****************************************************************/
static int PrintInt(element_t *element)
{
	assert(NULL != element);
	printf("The value is: %d\n", *(int *)(&(element->val)));
	return 1;

}
/****************************************************************/
static int PrintFloat(element_t *element)
{
	assert(NULL != element);
	printf("The value is: %f\n", *(float *)(&(element->val)));
	return 1;

}
/****************************************************************/
static int PrintString(element_t *element)
{
	assert(NULL != element);
	puts((char *)element->val);
	return 1;

}
/****************************************************************/
static int AddInt(element_t *element, int num_to_add)
{
	
	int *ptr = (int *)&(element->val);
	assert(NULL != element);
	*ptr += num_to_add;
	

	
	return 1;

}
/****************************************************************/
static int AddFloat(element_t *element, int num_to_add)
{
	
	float *ptr = (float *)&(element->val);
	assert(NULL != element);
	*ptr += num_to_add;
	
	
	return 1;
}
/****************************************************************/
static int AddString(element_t *element, int num_to_add)
{
	
	size_t size = strlen((char *)element->val);
	char add_int[10] = { 0 };
	void* tmp = NULL;
	tmp = realloc(element->val, size + 10);
	element->val = tmp;
	assert(NULL != element);
	sprintf(add_int, "%d", num_to_add);
	strcat((char *)element->val, add_int);
	return 1;
}

/****************************************************************/
static int CleanInt(element_t *element)
{
	assert(NULL != element);
	element->val = NULL;
	return 1;

}
/****************************************************************/
static int CleanFloat(element_t *element)
{
	assert(NULL != element);
	element->val = NULL;
	return 1;

}
/****************************************************************/
static int CleanString(element_t *element)
{
	assert(NULL != element);
	free(element->val);
	return 1;

}
/****************************************************************/
void Print(element_t *arr, size_t size)
{
	size_t i = 0;
	assert(NULL != arr);
	for(i = 0; i < size; ++i)
	{
		arr[i].print(&arr[i]);
	}

}
/****************************************************************/

void CleanUpAll(element_t *arr, size_t size)
{
	size_t i = 0;
	assert(NULL != arr);
	for(i = 0; i < size; ++i)
	{
		arr[i].clean(&arr[i]);
	}
}
/****************************************************************/
int AddAll(element_t *arr, size_t size, int num)
{
	size_t i = 0;
	assert(NULL != arr);
	for(i = 0; i < size; ++i)
	{
		if(0 == arr[i].add(&arr[i], num))
		{
			return 0;
		}
	}
	return 1;
}
/****************************************************************/
int CreateInt(element_t *element, int num)
{
	assert(NULL != element);
	*((int *)&element->val) = num;
	element->add = AddInt;
	element->print = PrintInt;
	element->clean = CleanInt;
	return 1;

}
/****************************************************************/
int CreateFloat(element_t *element, float num)
{
	assert(NULL != element);
	*((float *)&(element->val)) = num;
	element->add = AddFloat;
	element->print = PrintFloat;
	element->clean = CleanFloat;
	return 1;

}
/****************************************************************/
int CreateString(element_t *element, char *str)
{
	assert(NULL != element);
	assert(NULL != str);
	element->val = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy((char *)(element->val), (const char *)str);
	element->add = AddString;
	element->print = PrintString;
	element->clean = CleanString;
	return 1;

}

/****************************************************************/

