#include <stdio.h>

#include "mu_test.h"

#include "heap.h"

#include "vector.h"
int	Compare(const void *_left, const void *_right)
{
	return *(int*)_left > *(int*)_right;
}

UNIT(Heap_Build_Null_args)
ASSERT_THAT(Heap_Build(NULL, Compare) == NULL );
END_UNIT


UNIT(Heap_Build_creation_legal_values)
	Vector* vector;
	vector = Vector_Create(5, 6);
	ASSERT_THAT(Heap_Build(vector, Compare) != NULL );
END_UNIT

UNIT(Heap_Build_creation_zero_length_vector)
	Vector* vector;
	vector = Vector_Create(0, 6);
	ASSERT_THAT(Heap_Build(vector, Compare) != NULL );
END_UNIT

UNIT(Heap_Build_check_root_correctness)

	int a=5 , b=8, c=4;
	const void* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	heap=Heap_Build(vector, Compare);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 8 );
END_UNIT


UNIT(Heap_Extract_element)

	int a=5 , b=8, c=4 ,d=10;
	const void* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	heap=Heap_Build(vector, Compare);
	Heap_Insert(heap, (void*)&d);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 10 );
	Heap_Extract(heap);
	result = Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 8 );
END_UNIT

UNIT(Heap_Size_Null_args)

	ASSERT_THAT( Heap_Size(NULL) == 0 );
END_UNIT


UNIT(Heap_Size_empty)

	
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	heap=Heap_Build(vector, Compare);
	ASSERT_THAT( Heap_Size(heap) == 0 );
	
END_UNIT


UNIT(Heap_Size_diff_sizes)
	int a=5 , b=8, c=4 ,d=10;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	heap=Heap_Build(vector, Compare);
	ASSERT_THAT( Heap_Size(heap) == 0 );
	Heap_Insert(heap, (void*)&a);
	ASSERT_THAT( Heap_Size(heap) == 1 );
	Heap_Insert(heap, (void*)&b);
	ASSERT_THAT( Heap_Size(heap) == 2 );
	Heap_Insert(heap, (void*)&c);
	ASSERT_THAT( Heap_Size(heap) == 3 );
	Heap_Insert(heap, (void*)&d);
	ASSERT_THAT( Heap_Size(heap) == 4 );
END_UNIT

UNIT(Heap_Peek_Null_args)
	ASSERT_THAT( Heap_Peek(NULL) == NULL );
END_UNIT

UNIT(Heap_Peek_ok)
	int a=5 , b=8, c=4 ,d=10;
	void const* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	heap=Heap_Build(vector, Compare);
	Heap_Insert(heap, (void*)&a);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 5 );
	Heap_Insert(heap, (void*)&b);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 8 );
	Heap_Insert(heap, (void*)&c);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 8 );
	Heap_Insert(heap, (void*)&d);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 10 );
	
END_UNIT


UNIT(Heap_Peek_empty_heap)
	
	void const* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	heap=Heap_Build(vector, Compare);
	result = Heap_Peek(heap);
	ASSERT_THAT( result == NULL );
	
END_UNIT

UNIT(Heap_insert_to_built_heap)

	int a=5 , b=8, c=4 ,d=10;
	const void* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	heap=Heap_Build(vector, Compare);
	Heap_Insert(heap, (void*)&d);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 10 );
END_UNIT

UNIT(Heap_insert_Null_args)

	int a=5;
	Heap_ResultCode status;
	
	status = Heap_Insert(NULL, (void*)&a);
	ASSERT_THAT( status == HEAP_NOT_INITIALIZED );
END_UNIT

UNIT(Heap_insert_check_realloc_many_items)

	int a=5 , b=8, c=4 ,d=10;
	const void* result;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(1, 1);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	heap=Heap_Build(vector, Compare);
	Heap_Insert(heap, (void*)&d);
	result=Heap_Peek(heap);
	ASSERT_THAT( *(int*)result == 10 );
END_UNIT

UNIT(Heap_Extract_Null_args)

	void* status;

	status = Heap_Extract(NULL);
	ASSERT_THAT( status == NULL );
END_UNIT

UNIT(Heap_Extract_empty)

	void* status;
	Vector* vector;
	Heap* heap;
	vector = Vector_Create(1, 1);
	heap=Heap_Build(vector, Compare);
	status = Heap_Extract(heap);
	ASSERT_THAT( status == NULL );
END_UNIT

TEST_SUITE(Test Heap)

	TEST(Heap_Build_Null_args)

	TEST(Heap_Build_creation_zero_length_vector)

	TEST(Heap_Build_creation_legal_values)

	TEST(Heap_Build_check_root_correctness)

	TEST(Heap_Size_Null_args)

	TEST(Heap_Size_empty)

	TEST(Heap_Size_diff_sizes)

	TEST(Heap_Peek_Null_args)

	TEST(Heap_Peek_ok)

	TEST(Heap_Peek_empty_heap)	

	TEST(Heap_insert_Null_args)

	TEST(Heap_insert_to_built_heap)

	IGNORE_TEST(Heap_insert_to_empty_heap)

	IGNORE_TEST(Heap_insert_check_fixed_vector)

	TEST(Heap_insert_check_realloc_many_items)

	TEST(Heap_Extract_Null_args)

	TEST(Heap_Extract_element)

	TEST(Heap_Extract_empty)
    /* Check inserts, extracts and again by peek, and size */

	IGNORE_TEST(Heap_end_to_end)

END_SUITE
