/*
Rev: Maria Ponomariov.
Dev: Leonid Golovko
status: finished
date: 17/05/2023
*/
#include <stdio.h> /*print*/

#include "pqueue.h"

typedef struct Element
{
	void *data;
	size_t priority;
	
}is_match_param_t;

int Equal(const void * value1, const void *value2)
{
	return (*(int *)((is_match_param_t *)value1)->data == 
	*(int *)((is_match_param_t *)value2)->data && 
	(size_t)((is_match_param_t *)value1)->priority == 
	(size_t)((is_match_param_t *)value2)->priority);
}


int Action(void *value1, void *value2)
{
	(void)value2;
	printf("%d ", *(int *)value1);
	return 0;
}

int Compare(const void *value1, const void *value2)
{
	return ((size_t)((is_match_param_t *)value1)->priority - (size_t)((is_match_param_t *)value2)->priority);

}

void PQCreateTest();
void PQEnqueueTest();
void PQDequeueTest();
void PQClearTest();
void PQEraseTest();

int main()
{	
	PQCreateTest();
	PQEnqueueTest();
	PQDequeueTest();
	PQClearTest();
	PQEraseTest();
	return 0;
}





void PQCreateTest()
{
	pq_t *pq = PQCreate(Equal);
	
	if(0 == PQSize((const pq_t *)pq) && 1 == PQIsEmpty((const pq_t *)pq))
	{
		printf("PQCreateTest pass\n");
	}
	else
	{
		printf("PQCreateTest fail\n");
	}
	PQDestroy(pq);
}


void PQEnqueueTest()
{
	pq_t *pq = PQCreate(Compare);
	is_match_param_t param1;
	is_match_param_t param2;
	is_match_param_t param3;
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	size_t priority1 = 1;
	size_t priority2 = 2;
	size_t priority3 = 3;
	void *data1 = NULL;
	void *data2 = NULL;
	void *data3 = NULL;
	
	param1.data = (void *)&number1;
	param1.priority = priority1;
	
	
	param2.data = (void *)&number2;
	param2.priority = priority2;
	
	
	param3.data = (void *)&number3;
	param3.priority = priority3;
	
	
	
	PQEnqueue(pq, &param1);
	data1 = PQPeek((const pq_t *)pq);
	PQEnqueue(pq, &param2);
	data2 = PQPeek((const pq_t *)pq);
	PQEnqueue(pq, &param3);
	data3 = PQPeek((const pq_t *)pq);
	
	if(3 == PQSize((const pq_t *)pq) && 0 == PQIsEmpty((const pq_t *)pq) && 1 == *(int *)((is_match_param_t *)data1)->data && 1 == ((is_match_param_t *)data1)->priority && 1 == *(int *)((is_match_param_t *)data2)->data && 1 == ((is_match_param_t *)data2)->priority && 1 == *(int *)((is_match_param_t *)data3)->data && 1 == ((is_match_param_t *)data3)->priority)
	{
		printf("PQEnqueueTest pass\n");
		printf("PQIsEmptyTest pass\n");
		printf("PQSizeTest pass\n");
	}
	else
	{
		printf("PQEnqueueTest fail\n");
		printf("PQIsEmptyTest fail\n");
		printf("PQSizeTest fail\n");
		printf("data1 is %d\n" , *(int *)((is_match_param_t *)data1)->data);
		printf("priority1 is %ld\n" , (size_t)((is_match_param_t *)data1)->priority);
		printf("data2 is %d\n" , *(int *)((is_match_param_t *)data2)->data);
		printf("priority2 is %ld\n" , (size_t)((is_match_param_t *)data2)->priority);
		printf("data3 is %d\n" , *(int *)((is_match_param_t *)data3)->data);
		printf("priority3 is %ld\n" , (size_t)((is_match_param_t *)data3)->priority);
	}
	PQDestroy(pq);

}


void PQDequeueTest()
{
	pq_t *pq = PQCreate(Compare);
	is_match_param_t param1;
	is_match_param_t param2;
	is_match_param_t param3;
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	size_t priority1 = 1;
	size_t priority2 = 2;
	size_t priority3 = 3;
	void *data1 = NULL;
	
	
	param1.data = (void *)&number1;
	param1.priority = priority1;
	
	
	param2.data = (void *)&number2;
	param2.priority = priority2;
	
	
	param3.data = (void *)&number3;
	param3.priority = priority3;
	
	
	
	PQEnqueue(pq, &param1);
	PQEnqueue(pq, &param2);
	PQEnqueue(pq, &param3);
	
	
	PQDequeue(pq);
	PQDequeue(pq);
	
	data1 = PQPeek((const pq_t *)pq);
	if(1 == PQSize((const pq_t *)pq) && 0 == PQIsEmpty((const pq_t *)pq) && 3 == *(int *)((is_match_param_t *)data1)->data && 3 == ((is_match_param_t *)data1)->priority)
	{
		printf("PQDequeueTest pass\n");
		
	}
	else
	{
		printf("PQDequeueTest fail\n");
		
		printf("data1 is %d\n" , *(int *)((is_match_param_t *)data1)->data);
		printf("priority1 is %ld\n" , (size_t)((is_match_param_t *)data1)->priority);
		
	}
	PQDestroy(pq);
}

void PQClearTest()
{
	pq_t *pq = PQCreate(Compare);
	is_match_param_t param1;
	is_match_param_t param2;
	is_match_param_t param3;
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	size_t priority1 = 1;
	size_t priority2 = 2;
	size_t priority3 = 3;
	
	
	param1.data = (void *)&number1;
	param1.priority = priority1;
	
	
	param2.data = (void *)&number2;
	param2.priority = priority2;
	
	
	param3.data = (void *)&number3;
	param3.priority = priority3;
	
	
	
	PQEnqueue(pq, &param1);
	PQEnqueue(pq, &param2);
	PQEnqueue(pq, &param3);
	
	PQClear(pq);
	
	
	if(0 == PQSize((const pq_t *)pq) && 1 == PQIsEmpty((const pq_t *)pq))
	{
		printf("PQClearTest pass\n");
		
	}
	else
	{
		printf("PQClearTest fail\n");
		
		
		
	}
	PQDestroy(pq);
}

void PQEraseTest()
{

	pq_t *pq = PQCreate(Compare);
	is_match_param_t param1;
	is_match_param_t param2;
	is_match_param_t param3;
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	size_t priority1 = 1;
	size_t priority2 = 2;
	size_t priority3 = 3;
	void *data1 = NULL;
	void *data2 = NULL;
	
	param1.data = (void *)&number1;
	param1.priority = priority1;
	
	
	param2.data = (void *)&number2;
	param2.priority = priority2;
	
	
	param3.data = (void *)&number3;
	param3.priority = priority3;
	
	
	
	PQEnqueue(pq, &param1);
	PQEnqueue(pq, &param2);
	PQEnqueue(pq, &param3);
	
	PQErase(pq, Equal, (void *)&param2);
	data1 = PQPeek((const pq_t *)pq);
	PQDequeue(pq);
	data2 = PQPeek((const pq_t *)pq);
	
	if(1 == PQSize((const pq_t *)pq) && 0 == PQIsEmpty((const pq_t *)pq) && 1 == *(int *)((is_match_param_t *)data1)->data && 1 == ((is_match_param_t *)data1)->priority && 3 == *(int *)((is_match_param_t *)data2)->data && 3 == ((is_match_param_t *)data2)->priority)
	{
		printf("PQEraseTest pass\n");
		
	}
	else
	{
		printf("PQEraseTest fail\n");
		
	}
	PQDestroy(pq);
}




