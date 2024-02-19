#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mu_test.h"
#include "vector.h"

#define LINE_LENGTH 50
struct Person
{
    int     m_id;         /* Primary Key */
    char    m_name[128];
    int     m_age;
};
/*
Description: Destroy vector part.
Input: Pointer to the vector item .
Output: Void.
Complexity: O(1).
*/
void DestroyVecPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;

}
/*
Description: Function print the vector integer items.
Input: The pointer to the element to print, index of element and the pointer to the context to do any operations with vector if needed.
Output: index.
Complexity: O(1).
*/
int	VectorInt(void* _element, size_t _index, void* _context)
{
	int* y;
	y=(int*)_element;
	printf("%d) %d\n",(int)_index, *y);
	return _index;
}
/*
Description: Function find the sum of the vector items.
Input: The pointer to the element to print, index of element and the pointer to the context to do any operations with vector if needed.
Output: index.
Complexity: O(1).
*/
int	Vectorsum(void* _element, size_t _index, void* _context)
{

	*(int*)_context+=((struct Person*)_element)->m_age;
	return _index;
}

UNIT(VectorCreate)
	Vector* vector;
	vector = Vector_Create(5, 6);
	ASSERT_THAT( vector != NULL);
	Vector_Destroy(&vector, DestroyVecPart);
	ASSERT_THAT( Vector_Create(0, 0) == NULL);
END_UNIT



UNIT(VectorDestroy)
	int a=4 , b=5, c=8;
	Vector* vector;
	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	Vector_Destroy(&vector, DestroyVecPart);
	ASSERT_THAT( vector == NULL);
	
END_UNIT

UNIT(VectorApend)
	int a ;
	Vector* vector;
	vector = Vector_Create(5, 6);
	a = 6;
	ASSERT_THAT( Vector_Append(NULL, &a) == VECTOR_UNITIALIZED_ERROR);
	ASSERT_THAT( Vector_Append(vector, NULL) == VECTOR_UNITIALIZED_ERROR);
	ASSERT_THAT( Vector_Append(vector,&a) == VECTOR_SUCCESS);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT


UNIT(VectorRemove)
	int* a = NULL;
	int x=6;
	Vector* vector;
	vector = Vector_Create(5, 6);
	ASSERT_THAT( Vector_Remove(NULL, (void**)&a) == VECTOR_UNITIALIZED_ERROR);
	ASSERT_THAT( Vector_Remove(vector, NULL) == ERR_NOT_INITIALIZED);
	ASSERT_THAT( Vector_Remove(vector,(void**)&a) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR);
	Vector_Append(vector,&x);
	ASSERT_THAT( Vector_Remove(vector,(void**)&a) == VECTOR_SUCCESS);
	ASSERT_THAT( a = &x );
	ASSERT_THAT( Vector_Remove(vector,(void**)&a) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT


UNIT(VectorGet)
	int* a ;
	int b;
	Vector* vector=NULL;
	b = 5;
	a = &b;
	ASSERT_THAT( Vector_Get(NULL, 5, (void**)&a) == VECTOR_UNITIALIZED_ERROR);
	vector = Vector_Create(5, 6);
	ASSERT_THAT( Vector_Get(vector,5, NULL) == ERR_NOT_INITIALIZED);
	ASSERT_THAT( Vector_Get(vector,5 ,(void**)&a) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR);
	Vector_Append(vector,&a);
	Vector_Append(vector,(void**)&a);
	ASSERT_THAT( Vector_Get(vector,0,(void**)&a) == VECTOR_SUCCESS);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT

UNIT(VectorSet)
	int* a ;
	int b;
	Vector* vector=NULL;
	b = 5;
	a = &b;
	ASSERT_THAT( Vector_Set(NULL, 5, (void*)a) == VECTOR_UNITIALIZED_ERROR);
	vector = Vector_Create(5, 6);
	ASSERT_THAT( Vector_Set(vector,5, NULL) == ERR_NOT_INITIALIZED);
	ASSERT_THAT( Vector_Set(vector,10 ,(void*)a) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR);
	ASSERT_THAT( Vector_Set(vector,0,(void*)a) == VECTOR_SUCCESS);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT

UNIT(VectorSize)
	int* a ;
	int b;
	Vector* vector=NULL;
	b = 5;
	a = &b;
	ASSERT_THAT(Vector_Size(NULL) == 0);
	vector = Vector_Create(5, 6);
	ASSERT_THAT( Vector_Size(vector) == 0);
	Vector_Append(vector,&a);
	ASSERT_THAT( Vector_Size(vector) == 1);
	Vector_Append(vector,&a);
	ASSERT_THAT( Vector_Size(vector) == 2);
	Vector_Remove(vector,(void**)&a);
	ASSERT_THAT( Vector_Size(vector) == 1);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT

UNIT(VectorCapasity)
	Vector* vector=NULL;
	ASSERT_THAT(Vector_Capacity(NULL) == 0);
	vector = Vector_Create(5, 6);
	ASSERT_THAT(Vector_Capacity(vector) == 5);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT


UNIT(VectorPrint)
	int a=4 , b=5, c=8;
	void* tempvalue=NULL;
	Vector* vector=NULL;
	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&a);
	Vector_Append(vector,(void**)&b);
	Vector_Append(vector,(void**)&c);
	Vector_Append(vector,(void**)&a);
	Vector_ForEach(vector, VectorInt,tempvalue);
	fflush(stdin);
	Vector_Destroy(&vector, DestroyVecPart);
END_UNIT
UNIT(VectorSum)
	struct Person class[3]={{200,"Shaul",19},{50,"Haim",23},{30,"Shlomo",44}};
	
	Vector* vector=NULL;
	int a=0;

	vector = Vector_Create(5, 6);
	Vector_Append(vector,(void**)&class[0]);
	Vector_Append(vector,(void**)&class[1]);
	Vector_Append(vector,(void**)&class[2]);
	Vector_ForEach(vector, Vectorsum, &a);
	ASSERT_THAT(a == 86);
	Vector_Destroy(&vector, DestroyVecPart);
	
	
END_UNIT

TEST_SUITE(Vector)
	TEST(VectorCreate)
	TEST(VectorDestroy)
	TEST(VectorApend)
	TEST(VectorRemove)
	TEST(VectorGet)
	TEST(VectorSet)
	TEST(VectorSize)
	TEST(VectorCapasity)
	TEST(VectorPrint)
	TEST(VectorSum)
END_SUITE
