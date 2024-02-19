
#include <stdio.h>
#include "mu_test.h"
#include "ListStructs.h"
#include "ListIt.h"
#include "List.h"


void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}


UNIT(Iterator_It_Begin_Check)
	int arr[]={5,3,5,4,2},i;
	ListItr status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Begin(NULL);
	ASSERT_THAT(status == NULL );
	status = ListItr_Begin(list);
	ASSERT_THAT( (Node*)status == list->m_head.m_next );
	List_Size(list);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_It_End_Check)
	int arr[]={5,3,5,4,2},i;
	ListItr status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_End(NULL);
	ASSERT_THAT(status == NULL );
	status = ListItr_End(list);
	ASSERT_THAT( (Node*)status == &list->m_tail );
	List_Size(list);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_Equals_Check)
	int arr[]={5,3,5,4,2},i;
	int status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Equals(NULL, NULL);
	ASSERT_THAT(status == 0 );
	status = ListItr_Equals((ListItr)list->m_head.m_next , (ListItr)list->m_head.m_next);
	ASSERT_THAT( status == 1 );
	status = ListItr_Equals((ListItr)list->m_head.m_next , (ListItr)&list->m_tail);
	ASSERT_THAT( status == 0 );
	List_Size(list);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_It_Next_Check)
	int arr[]={5,3,5,4,2},i;
	ListItr status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Next(NULL);
	ASSERT_THAT(status == NULL );
	status = ListItr_Next((ListItr)&list->m_head);
	ASSERT_THAT( status == (ListItr)list->m_head.m_next );
	status = ListItr_Next((ListItr)&list->m_tail);
	ASSERT_THAT( status == (ListItr)&list->m_tail );
	List_Size(list);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_It_Prev_Check)
	int arr[]={5,3,5,4,2},i;
	ListItr status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Prev(NULL);
	ASSERT_THAT(status == NULL );
	status = ListItr_Prev((ListItr)list->m_head.m_next);
	ASSERT_THAT( status == (ListItr)list->m_head.m_next );
	status = ListItr_Prev((ListItr)&list->m_tail);
	ASSERT_THAT( status == (ListItr)list->m_tail.m_prev );
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_Get_Check)
	int arr[]={5,3,5,4,2},i;
	void* status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	
	List_Size(list);
	
	status = ListItr_Get(NULL);
	ASSERT_THAT(status == NULL );
	status = ListItr_Get((ListItr)&list->m_tail);
	ASSERT_THAT( status == NULL );
	status = ListItr_Get((ListItr)list->m_head.m_next);
	ASSERT_THAT( *(int*)status == 2 );
	List_Destroy(&list, DestroyPart);
END_UNIT


UNIT(Iterator_Set_Check)
	int arr[]={5,3,5,4,2},i;
	void* status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Set((ListItr)list->m_tail.m_prev,(void*)&arr[4]);
	ASSERT_THAT(*(int*)status == 5 );
	status = ListItr_Get((ListItr)list->m_tail.m_prev);
	ASSERT_THAT( *(int*)status == 2 );
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_InsertBefore_Check)
	int arr[]={5,3,5,4,2},i;
	ListItr statusnode;
	void* status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	statusnode = ListItr_InsertBefore((ListItr)&list->m_tail, (void*)&arr[4]);
	ASSERT_THAT( statusnode == (ListItr)list->m_tail.m_prev );
	status = ListItr_Get((ListItr)list->m_tail.m_prev);
	ASSERT_THAT( *(int*)status == 2 );
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Iterator_Remove_Check)
	int arr[]={5,3,5,4,2},i;
		
	void* status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	status = ListItr_Remove(NULL);
	ASSERT_THAT( status == NULL );
	status = ListItr_Remove((ListItr)list->m_tail.m_prev);
	ASSERT_THAT( *(int*)status == 5 );
	List_Destroy(&list, DestroyPart);
END_UNIT


TEST_SUITE(ITERATOR_LIST)

	TEST(Iterator_It_Begin_Check)
	
	TEST(Iterator_It_End_Check)
	
	TEST(Iterator_Equals_Check)
	
	TEST(Iterator_It_Next_Check)
	
	TEST(Iterator_It_Prev_Check)
	
	TEST(Iterator_Get_Check)
	
	TEST(Iterator_Set_Check)
	
	TEST(Iterator_InsertBefore_Check)
	
	TEST(Iterator_Remove_Check)
	
END_SUITE
