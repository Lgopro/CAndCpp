/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 25/04/2023
*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/

#include "d_vector.h"

void DVectorPushBackTest();
void DVectorCreateTest();
void DVectorSizeTest();
void DVectorCapacityTest();
void DVectorPopBackTest();
void DVectorShrinkTest();
void DVectorReserveTest();
void DVectorGetAccessToElementTest();

int main()
{	
	DVectorCreateTest();
	DVectorSizeTest();
	DVectorCapacityTest();
	DVectorPushBackTest();
	DVectorPopBackTest();
	DVectorShrinkTest();
	DVectorReserveTest();
	DVectorGetAccessToElementTest();
	return 0;
}

void DVectorCreateTest()
{
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 10);
	
	if(NULL != vector&& 0 == DVectorSize(vector) && 10 == DVectorCapacity(vector))
	{
		printf("Test DVectorCreateTest pass\n");
	}
	else
	{
		printf("Test DVectorCreateTest fail\n");
	}
	DVectorDestroy(vector);

}

void DVectorSizeTest()
{
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	int value = 4;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 10);
	
	size1 = DVectorSize((const dvector_t *)vector);
	DVectorPushBack(vector, (const void *)&value);
	size2 = DVectorSize((const dvector_t *)vector);
	DVectorPopBack(vector);
	size3 = DVectorSize((const dvector_t *)vector);
	if(0 == size1 && 1 == size2 && 0 == size3)
	{
		printf("Test DVectorSizeTest pass\n");
	}
	else
	{
		printf("Test DVectorSizeTest fail\n");
	}
	
	DVectorDestroy(vector);

}


void DVectorCapacityTest()
{
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	size_t size4 = 0;
	int value = 4;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 10);
	
	size1 = DVectorCapacity((const dvector_t *)vector);
	DVectorPushBack(vector, (const void *)&value);
	size2 = DVectorCapacity((const dvector_t *)vector);
	DVectorPopBack(vector);
	size3 = DVectorCapacity((const dvector_t *)vector);
	DVectorPushBack(vector, (const void *)&value);
	DVectorPushBack(vector, (const void *)&value);
	DVectorPushBack(vector, (const void *)&value);
	DVectorPushBack(vector, (const void *)&value);
	DVectorPushBack(vector, (const void *)&value);
	size4 = DVectorCapacity((const dvector_t *)vector);
	if(10 == size1 && 10 == size2 && 5 == size3 && 5 == size4)
	{
		printf("Test DVectorCapacityTest pass\n");
	}
	else
	{
		printf("%ld\n", size1);
		printf("%ld\n", size2);
		printf("%ld\n", size3);
		printf("%ld\n", size4);
		printf("Test DVectorCapacityTest fail\n");
	}
	
	DVectorDestroy(vector);

}


void DVectorPushBackTest()
{
	
	size_t status1 = 10;
	size_t status2 = 10;
	size_t status3 = 10;
	size_t status4 = 10;
	size_t status5 = 10;
	size_t status6 = 10;

	
	int value1 = 4;
	int value2 = 5;
	int value3 = 6;
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	int result4 = 0;
	int result5 = 0;
	int result6 = 0;
	
	size_t size1 = 0;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 5);
	
	
	status1 = DVectorPushBack(vector, (const void *)&value1);
	status2 = DVectorPushBack(vector, (const void *)&value2);
	result1 = *(int *)DVectorGetAccessToElement(vector, 0);
	status3 = DVectorPushBack(vector, (const void *)&value3);
	status4 = DVectorPushBack(vector, (const void *)&value1);
	status5 = DVectorPushBack(vector, (const void *)&value2);
	status6 = DVectorPushBack(vector, (const void *)&value3);
	result2 = *(int *)DVectorGetAccessToElement(vector, 1);
	result3 = *(int *)DVectorGetAccessToElement(vector, 2);
	result4 = *(int *)DVectorGetAccessToElement(vector, 3);
	result5 = *(int *)DVectorGetAccessToElement(vector, 4);
	result6 = *(int *)DVectorGetAccessToElement(vector, 5);
	size1 = DVectorCapacity((const dvector_t *)vector);
	if(10 == size1 && 0 == status1 && 0 == status2 && 0 == status3 && 0 == status4 && 0 == status5 && 0 == status6 && 4 == result1 && 5 == result2 && 6 == result3 && 4 == result4 && 5 == result5 && 6 == result6)
	{
		printf("Test DVectorPushBackTest pass\n");
	}
	else
	{
		printf("Test DVectorPushBackTest fail\n");
	}
	
	DVectorDestroy(vector);
}

void DVectorPopBackTest()
{
	int status1 = 10;
	int status2 = 10;
	int status3 = 10;
	int status4 = 10;
	int status5 = 10;
	int status6 = 10;

	
	int value1 = 4;
	int value2 = 5;
	int value3 = 6;
	
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	size_t capacity = 0;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 5);
	
	
	DVectorPushBack(vector, (const void *)&value1);
	DVectorPushBack(vector, (const void *)&value2);
	DVectorPushBack(vector, (const void *)&value3);
	DVectorPushBack(vector, (const void *)&value1);
	DVectorPushBack(vector, (const void *)&value2);
	DVectorPushBack(vector, (const void *)&value3);
	size1 = DVectorCapacity((const dvector_t *)vector);
	status1 = DVectorPopBack(vector);
	size1 = DVectorSize((const dvector_t *)vector);
	status2 = DVectorPopBack(vector);
	status3 = DVectorPopBack(vector);
	status4 = DVectorPopBack(vector);
	size2 = DVectorSize((const dvector_t *)vector);
	status5 = DVectorPopBack(vector);
	status6 = DVectorPopBack(vector);
	size3 = DVectorSize((const dvector_t *)vector);
	capacity = DVectorCapacity((const dvector_t *)vector);
	
	if(0 == status6 && 0 == status1 && 0 == status2 && 0 == status3 && 0 == status4 && 0 == status5 && 5 == size1 && 2 == size2 && 0 == size3 && 2 == capacity)
	{
		printf("Test DVectorPopBack pass\n");
	}
	else
	{
		printf("Test DVectorPopBack fail\n");
		
	}
	DVectorDestroy(vector);
}

void DVectorShrinkTest()
{
	
	int status1 = 10;
	size_t capacity = 0;
	int value1 = 4;
	int value2 = 5;
	int value3 = 6;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 5);
	
	
	DVectorPushBack(vector, (const void *)&value1);
	DVectorPushBack(vector, (const void *)&value2);
	DVectorPushBack(vector, (const void *)&value3);
	DVectorPushBack(vector, (const void *)&value1);
	status1 = DVectorShrink(vector);
	capacity = DVectorCapacity((const dvector_t *)vector);
	
	if(5 == capacity && 0 == status1)
	{
		printf("Test DVectorShrinkTest pass\n");
	}
	else
	{
		printf("Test DVectorShrinkTest fail\n");
	}
	DVectorDestroy(vector);
}


void DVectorReserveTest()
{
	
	
	int value1 = 4;
	int value2 = 5;
	int value3 = 6;
	size_t capacity1 = 0;
	size_t capacity2 = 0;
	size_t capacity3 = 0;
	size_t capacity4 = 0;
	size_t capacity5 = 0;
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 1);
	
	
	DVectorPushBack(vector, (const void *)&value1);
	capacity1 = DVectorCapacity((const dvector_t *)vector);
	DVectorPushBack(vector, (const void *)&value2);
	capacity2 = DVectorCapacity((const dvector_t *)vector);
	DVectorPushBack(vector, (const void *)&value3);
	DVectorPushBack(vector, (const void *)&value1);
	capacity3 = DVectorCapacity((const dvector_t *)vector);
	DVectorReserve(vector, 200);
	capacity4 = DVectorCapacity((const dvector_t *)vector);
	DVectorReserve(vector, 150);
	capacity5 = DVectorCapacity((const dvector_t *)vector);
	if(1 == capacity1 && 2 == capacity2 && 4 == capacity3 && 200 == capacity4 && 200 == capacity5)
	{
		printf("Test DVectorReserveTest pass\n");
	}
	else
	{
		printf("Test DVectorReserveTest fail\n");
		printf("Cap is %ld\n", capacity1);
		printf("Cap is %ld\n", capacity2);
		printf("Cap is %ld\n", capacity3);
	}
	DVectorDestroy(vector);



}

void DVectorGetAccessToElementTest()
{
	int index0 = 0;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	int index4 = 0;
	int index5 = 0;

	
	int value1 = 4;
	int value2 = 5;
	int value3 = 6;
	
	
	dvector_t *vector = NULL;
	vector = DVectorCreate(4, 5);
	
	
	DVectorPushBack(vector, (const void *)&value1);
	DVectorPushBack(vector, (const void *)&value2);
	DVectorPushBack(vector, (const void *)&value3);
	DVectorPushBack(vector, (const void *)&value1);
	DVectorPushBack(vector, (const void *)&value2);
	DVectorPushBack(vector, (const void *)&value3);
	index0 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 0);
	
	index1 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 1);
	index2 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 2);
	index3 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 3);
	index4 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 4);
	index5 = *(int *)DVectorGetAccessToElement((const dvector_t *)vector, 5);
	if(4 == index0 && 5 == index1 && 6 == index2 && 4 == index3 && 5 == index4 && 6 == index5)
	{
		printf("Test DVectorGetAccessToElementTest pass\n");
	}
	else
	{
		printf("Test DVectorGetAccessToElementTest fail\n");
		
	}
	DVectorDestroy(vector);




}

