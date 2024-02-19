#include <stdio.h>
#include <stdlib.h>
#include "MemoryMappingFull.h"

int global_implicit = 5;
const int const_global_implicit = 5;
static int static_global_implicit = 5;
const static int const_static_global_implicit = 5;

static void StaticFunctionImplicit()
{
	printf("hello");
}

extern void ExternFunctionImplicit();

void FuncImplicit()
{
	int* p_heap_static = (int*)malloc(sizeof(int));
	const int const_local_static = 5;
	int local_static = 5;
	static int static_local_static = 5;
	const static int const_static_local_static = 5;
	char *string_literal_static = "hello";
	const char *const_string_literal_static = "nice";	
	
	printf("\nAddresses for implicit library: \n");
	printf("p_heap address: %p\n", p_heap_static);
	printf("const_local address: %p\n", &const_local_static);
	printf("static_local address: %p\n", &static_local_static);
	printf("const_static_local address: %p\n", &const_static_local_static);
	printf("string_literal address: %p\n", string_literal_static);
	printf("local address: %p\n", &local_static);
	printf("const_string_literal address: %p\n", &const_string_literal_static);
	
	printf("global address: %p\n", &global_implicit);
	printf("const_global address: %p\n", &const_global_implicit);
	printf("static_global address: %p\n", &static_global_implicit);
	printf("const_static_global address: %p\n", &const_static_global_implicit);
	printf("StaticFunction address: %p\n", StaticFunctionImplicit);
	printf("ExternFunction address: %p\n", ExternFunctionImplicit);
}

