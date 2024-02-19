

#include <stdio.h>

#include "mu_test.h"
#include "list.h"

void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}



UNIT(List_Create_Zero)
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(List_Destroy_Test)
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Push_Head_Null)
	int a=5;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PushHead(NULL, (void*)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PushHead(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Push_Head_Not_Null)
	int a=5;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PushHead(NULL, (void*)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PushHead(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	status = List_PushHead(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Push_Tail_Null)
	int a=5;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PushTail(NULL, (void*)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PushTail(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Push_Tail_Not_Null)
	int a=5;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PushTail(NULL, (void*)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PushTail(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	status = List_PushTail(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT


UNIT(List_Pop_Head_Null)
	int* a;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PopHead(NULL, (void**)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PopHead(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Pop_Head_Not_Null)
	void* a;
	int b=5;
	size_t statusnum;
	List_Result status;
	struct List* list;
	list = List_Create();
	status = List_PopHead(list, (void**)&a);
	ASSERT_THAT(status == LIST_UNDERFLOW );
	status = List_PushHead(list, (void*)&b);
	status = List_PopHead(list, (void**)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	ASSERT_THAT(*(int*)a == 5 );
	status = List_PushHead(list, (void*)&b);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 1 );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Count)
	void* a;
	int b=5;
	size_t statusnum;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PopHead(NULL, (void**)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PopHead(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 0 );
	status = List_PushHead(list, (void*)&b);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 1 );
	List_PushHead(list, (void*)&b);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 2 );
	List_PushHead(list, (void*)&b);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 3 );
	status = List_PopHead(list, (void**)&a);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 2 );
	status = List_PopHead(list, (void**)&a);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 1 );
	status = List_PopHead(list, (void**)&a);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 0 );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Pop_Tail_Null)
	int* a;
	List_Result status;
	struct List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL );
	status = List_PopTail(NULL, (void**)&a);
	ASSERT_THAT(status == LIST_UNINITIALIZED_ERROR );
	status = List_PopTail(list, NULL);
	ASSERT_THAT(status == LIST_NULL_ELEMENT_ERROR );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Pop_Tail_Not_Null)
	void* a;
	int b=5;
	size_t statusnum;
	List_Result status;
	struct List* list;
	list = List_Create();
	status = List_PopTail(list, (void**)&a);
	ASSERT_THAT(status == LIST_UNDERFLOW );
	status = List_PushHead(list, (void*)&b);
	status = List_PopTail(list, (void**)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	ASSERT_THAT(*(int*)a == 5 );
	status = List_PushHead(list, (void*)&b);
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 1 );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
END_UNIT

UNIT(List_Mixed_Push_And_Pop)
	int a=5;
	void* b;
	List_Result status;
	struct List* list;
	size_t statusnum;
	list = List_Create();
	status = List_PushHead(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	status = List_PushHead(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	status = List_PushTail(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	status = List_PushTail(list, (void*)&a);
	ASSERT_THAT(status == LIST_SUCCESS );
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 4 );
	status = List_PopTail(list, (void**)&b);
	ASSERT_THAT(status == LIST_SUCCESS );
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 3 );
	status = List_PopHead(list, (void**)&b);
	ASSERT_THAT(status == LIST_SUCCESS );
	statusnum = List_Size(list);
	ASSERT_THAT(statusnum == 2 );
	List_Destroy(&list, DestroyPart);
	ASSERT_THAT(list == NULL );
	
END_UNIT



TEST_SUITE(TEST_LIST)

	TEST(List_Create_Zero)
	
	TEST(List_Destroy_Test)
	
	TEST(List_Push_Head_Null)

	TEST(List_Push_Head_Not_Null)
	
	TEST(List_Push_Tail_Null)

	TEST(List_Push_Tail_Not_Null)
	
	TEST(List_Pop_Head_Null)

	TEST(List_Pop_Head_Not_Null)
	
	TEST(List_Count)
	
	TEST(List_Pop_Tail_Null)

	TEST(List_Pop_Tail_Not_Null)
	
	TEST(List_Mixed_Push_And_Pop)
	
END_SUITE
