#include <stdio.h>
#include <stdlib.h>
#include "MemoryMappingFull.h"

int global_var = 5;
const int const_global_var = 5;
static int static_global = 5;
const static int const_static_global = 5;

static void StaticFunction()
{
	printf("hello");
}

extern void ExternFunction();

void Func()
{
	int* p_heap_var = (int*)malloc(sizeof(int));
	const int const_local_var = 5;
	int local_var = 5;
	static int static_local = 5;
	const static int const_static_local = 5;
	char *string_literal = "hello";
	const char *const_string_literal = "bbbb";	
	
	
}




