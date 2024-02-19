#include <stdio.h>
#include <stdlib.h>
#include "MemoryMappingFull.h"

int global_explicit = 5;
const int const_global_explicit = 5;
static int static_global_explicit = 5;
const static int const_static_global_explicit = 5;

static void StaticFunctionExplicit()
{
	printf("hello");
}

extern void ExternFunctionExplicit();

void FuncExplicit()
{
	int* p_heap_explicit = (int*)malloc(sizeof(int));
	const int const_local_explicit = 5;
	int local_explicit= 5;
	static int static_local_explicit = 5;
	const static int const_static_local_explicit = 5;
	char *string_literal_explicit = "hello";
	const char *const_string_literal_explicit = "nice";	
	
	printf("\nAddresses for explicit library: \n");
	printf("p_heap address: %p\n", p_heap_explicit);
	printf("const_local address: %p\n", &const_local_explicit);
	printf("static_local address: %p\n", &static_local_explicit);
	printf("const_static_local address: %p\n", &const_static_local_explicit);
	printf("string_literal address: %p\n", string_literal_explicit);
	printf("local address: %p\n", &local_explicit);
	printf("const_string_literal address: %p\n", &const_string_literal_explicit);
	
	printf("global address: %p\n", &global_explicit);
	printf("const_global address: %p\n", &const_global_explicit);
	printf("static_global address: %p\n", &static_global_explicit);
	printf("const_static_global address: %p\n", &const_static_global_explicit);
	printf("StaticFunction address: %p\n", StaticFunctionExplicit);
	printf("ExternFunction address: %p\n", ExternFunctionExplicit);
}

