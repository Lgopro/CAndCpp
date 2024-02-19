
#include <stdio.h>
#include "mu_test.h"
#include "queue.h"




void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}
UNIT(Queue_Create_Zero)
	
	ASSERT_THAT(Queue_Create( 0 ) == NULL );
	
	
END_UNIT


UNIT(Queue_Create_Not_Zero)
	Queue* queue;
	queue=Queue_Create( 5 );
	ASSERT_THAT(queue != NULL );
	Queue_Destroy(&queue, DestroyPart);
	
END_UNIT

UNIT(Queue_Destroy_Zero)
	Queue* queue;
	queue=Queue_Create( 5 );
	ASSERT_THAT(queue != NULL );
	Queue_Destroy(&queue, DestroyPart);
	ASSERT_THAT(queue == NULL );
	
END_UNIT

UNIT(Queue_End_Queue_Null)
	int a = 6;
	Queue* queue;
	Queue_Result result;
	queue=Queue_Create( 5 );
	ASSERT_THAT(queue != NULL );
	result=Queue_Enqueue(NULL, (void*)&a );
	ASSERT_THAT(result == QUEUE_UNINITIALIZED_ERROR );
	result=Queue_Enqueue(queue, NULL );
	ASSERT_THAT(result == QUEUE_UNINITIALIZED_ITEM );
	Queue_Destroy(&queue, DestroyPart);
	ASSERT_THAT(queue == NULL );
	
END_UNIT


UNIT(Queue_End_Add)

	int a = 6;
	Queue* queue;
	Queue_Result result;
	queue=Queue_Create( 2 );
	
	result=Queue_Enqueue(queue, (void*)&a );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Enqueue(queue, (void*)&a );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Enqueue(queue, (void*)&a );
	ASSERT_THAT(result == QUEUE_OVERFLOW );
	Queue_Destroy(&queue, DestroyPart);
	ASSERT_THAT(queue == NULL );
	
END_UNIT


UNIT(Queue_Del_Queue_Null)
	int a = 6;
	Queue* queue;
	Queue_Result result;
	queue=Queue_Create( 5 );
	ASSERT_THAT(queue != NULL );
	result=Queue_Dequeue(NULL, (void**)&a );
	ASSERT_THAT(result == QUEUE_UNINITIALIZED_ERROR );
	result=Queue_Dequeue(queue, NULL );
	ASSERT_THAT(result == QUEUE_UNINITIALIZED_ITEM );
	Queue_Destroy(&queue, DestroyPart);
	ASSERT_THAT(queue == NULL );
	
END_UNIT
UNIT(Queue_Del_Rem)

	int a = 6, b=10, c=15;
	int* res;
	Queue* queue;
	Queue_Result result;
	queue=Queue_Create( 2 );
	
	result=Queue_Enqueue(queue, (void*)&a );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Enqueue(queue, (void*)&b );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Enqueue(queue, (void*)&c );
	ASSERT_THAT(result == QUEUE_OVERFLOW );
	result=Queue_Dequeue(queue, (void**)&res );
	ASSERT_THAT(*res == a );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Dequeue(queue, (void**)&res );
	ASSERT_THAT(*res == b );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	result=Queue_Dequeue(queue, (void**)&res );
	ASSERT_THAT(result == QUEUE_UNDERFLOW );
	Queue_Destroy(&queue, DestroyPart);
	ASSERT_THAT(queue == NULL );
	
END_UNIT


UNIT(Queue_Empty_Null)
	int status;
	status=Queue_IsEmpty(NULL);
	ASSERT_THAT(status == -1 );
END_UNIT


UNIT(Queue_Empty_Not_Null)
	int status,a=5;
	Queue* queue;
	Queue_Result result;
	queue=Queue_Create( 2 );
	status=Queue_IsEmpty(queue);
	ASSERT_THAT(status == 0 );
	result=Queue_Enqueue(queue, (void*)&a );
	ASSERT_THAT(result == QUEUE_SUCCESS );
	status=Queue_IsEmpty(queue);
	ASSERT_THAT(status == 1 );
END_UNIT

TEST_SUITE(TEST_QUEUE)


	TEST(Queue_Create_Zero)

	TEST(Queue_Create_Not_Zero)

	TEST(Queue_Destroy_Zero)

	TEST(Queue_End_Queue_Null)

	TEST(Queue_End_Add)

	TEST(Queue_Del_Queue_Null)

	TEST(Queue_Del_Rem)

	TEST(Queue_Empty_Null)
	
	TEST(Queue_Empty_Not_Null)

END_SUITE
