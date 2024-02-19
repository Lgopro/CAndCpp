/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 02/05/2023
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

#include "queue.h"





void *Action(void *value1, void *value2)
{
	printf("The value is: %d\n", *(int *)value1);
	(void)value2;
	return value1;
}


int Print(void *value1, void *value2)
{
	printf("The value is: %d\n", *(int *)value1);
	(void)value2;
	return 0;
}

void QCreateTest();
void QSizeTest();
void QIsEmptyTest();
void QPeekTest();
void QEnqueueTest();
void QEnqueueTest();
void QDequeueTest();
void QAppendTest();


int main()
{	
	QCreateTest();	
	QSizeTest();
	QIsEmptyTest();
	QPeekTest();
	QEnqueueTest();
	QDequeueTest();
	QAppendTest();
	return 0;
}

void QAppendTest()
{
	size_t size1 = 0;
	size_t size2 = 0;
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;
	int value5 = 5;
	int value6 = 6;
	int value7 = 7;
	int value8 = 8;
	int value9 = 9;
	
	queue_t *queue1 = NULL;
	queue_t *queue2 = NULL;
	queue1 = QCreate();
	queue2 = QCreate();
	
	QEnqueue(queue1, (const void *)&value1);
	QEnqueue(queue1, (const void *)&value2);
	QEnqueue(queue1, (const void *)&value3);
	QEnqueue(queue1, (const void *)&value4);
	QEnqueue(queue1, (const void *)&value5);
	QEnqueue(queue2, (const void *)&value6);
	QEnqueue(queue2, (const void *)&value7);
	QEnqueue(queue2, (const void *)&value8);
	QEnqueue(queue2, (const void *)&value9);
	
	QAppend(queue1, queue2);
	
	size1 = QSize((const queue_t *)queue1);
	size2 = QSize((const queue_t *)queue2);
	
	SListForEach(SListBegin((const slist_t *)queue1), SListEnd((const slist_t *)queue1), Print, (void *)&value1);
	
	
	if(9 == size1 && 0 == size2)
	{
		printf("QAppendTest pass\n");
	}
	else
	{
		printf("Size is: %ld\n", size1);
		printf("Size is: %ld\n", size2);
		printf("QAppendTest fail\n");
	}
	
	
	QDestroy(queue1);
	QDestroy(queue2);
}



void QCreateTest()
{
	queue_t *queue = NULL;
	iter_t iterator1 = NULL;
	iter_t iterator2 = NULL;
	
	queue = QCreate();
	iterator1 = SListBegin(queue);
	iterator2 = SListEnd(queue);
	if(iterator1 == iterator2)
	{
		printf("QCreateTest pass\n");
	}
	else
	{
		printf("QCreateTest fail\n");
	}
	
	
	QDestroy(queue);

}



void QSizeTest()
{

	
	queue_t *queue = NULL;
	
	int value = 1;
	int value1 = 2;
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	queue = QCreate();
	
	
	size1 = QSize((const queue_t *)queue);
	
	QEnqueue(queue, (const void *)&value);
	
	size2 = QSize((const queue_t *)queue);
	
	QEnqueue(queue, (const void *)&value1);
	
	size3 = QSize((const queue_t *)queue);
	if(0 == size1 && 1 == size2 && 2 == size3 )
	{
		printf("QSizeTest pass\n");
	}
	else
	{
		printf("Size is: %ld\n", size1);
		printf("Size is: %ld\n", size2);
		printf("Size is: %ld\n", size3);
		printf("QSizeTest fail\n");
	}
	
	
	QDestroy(queue);
}



void QIsEmptyTest()
{

	queue_t *queue = NULL;
	
	int value = 1;
	int value1 = 2;
	int status1 = 0;
	int status2 = 0;
	int status3 = 0;
	queue = QCreate();

	status1 = QIsEmpty((const queue_t *)queue);
	QEnqueue(queue, (const void *)&value);
	
	status2 = QIsEmpty((const queue_t *)queue);
	
	QEnqueue(queue, (const void *)&value1);
	
	status3 = QIsEmpty((const queue_t *)queue);
	if(1 == status1 && 0 == status2 && 0 == status3 )
	{
		printf("QIsEmptyTest pass\n");
	}
	else
	{
		printf("Size is: %d\n", status1);
		printf("Size is: %d\n", status2);
		printf("Size is: %d\n", status3);
		printf("QIsEmptyTest fail\n");
	}
	
	
	QDestroy(queue);
}






void QPeekTest()
{

	queue_t *queue = NULL;
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	queue = QCreate();
	
	
	
	QEnqueue(queue, (const void *)&value);
	result1 = QPeek((const queue_t *)queue);
	
	
	
	QEnqueue(queue, (const void *)&value1);
	result2 = QPeek((const queue_t *)queue);
	
	
	
	QEnqueue(queue, (const void *)&value2);
	result3 = QPeek((const queue_t *)queue);
	
	if(value == *(int *)result1 && value == *(int *)result2 && value == *(int *)result3 )
	{
		printf("QPeekTest pass\n");
	}
	else
	{
		printf("Size is: %d\n", *(int *)result1);
		printf("Size is: %d\n", *(int *)result2);
		printf("Size is: %d\n", *(int *)result3);
		printf("QPeekTest fail\n");
	}
	
	
	QDestroy(queue);
}



void QEnqueueTest()
{
	queue_t *queue = NULL;
	iter_t iterator1 = NULL;
	void * changed_value1 = NULL;
	void * changed_value2 = NULL;
	void * changed_value3 = NULL;


	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	int status1 = 1;
	int status2 = 1;
	int status3 = 1;
	queue = QCreate();
	
	
	
	
	status1 = QEnqueue(queue, (const void *)&value1);
	status2 = QEnqueue(queue, (const void *)&value2);
	status3 = QEnqueue(queue, (const void *)&value3);
	
	
	iterator1 = SListBegin(queue);
	changed_value1 = SListGet(iterator1);
	iterator1 = SListNext(iterator1);
	
	changed_value2 = SListGet(iterator1);
	iterator1 = SListNext(iterator1);
	
	
	changed_value3 = SListGet(iterator1);
	if(4 == *(int *)changed_value3 && 3 == *(int *)changed_value2 && 2 == *(int *)changed_value1 && 0 == status1 && 0 == status2 && 0 == status3)
	{
		printf("QEnqueueTest pass\n");	
	}
	else
	{
		printf("QEnqueueTest pass\n");
	}
	
	QDestroy(queue);
}



void QDequeueTest()
{
	queue_t *queue = NULL;
	iter_t iterator1 = NULL;
	void * changed_value1 = NULL;
	void * changed_value2 = NULL;
	
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	
	queue = QCreate();
	
	
	QEnqueue(queue, (const void *)&value1);
	
	QEnqueue(queue, (const void *)&value2);
	
	QEnqueue(queue, (const void *)&value3);
	
	QDequeue(queue);
	iterator1 = SListBegin((const slist_t *)queue);
	changed_value1 = SListGet(iterator1);
	QDequeue(queue);
	iterator1 = SListBegin((const slist_t *)queue);
	changed_value2 = SListGet(iterator1);
	
	if(4 == *(int *)changed_value2 && 3 == *(int *)changed_value1)
	{
		printf("QDequeueTest pass\n");	
	}
	else
	{
		printf("QDequeueTest pass\n");
	}
	
	QDestroy(queue);
}
