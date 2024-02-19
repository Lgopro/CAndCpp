

#include <stdio.h>
#include "mu_test.h"
#include "ListFunc.h"



int Predicate(void * _element, void* _context)
{
	return (*(int*)_element == *(int*)_context);
}

int ListAction(void* _element, void* _context)
{
	return (*(int*)_element % 2 == 0 && *(int*)_context % 2 == 0);
}

int Less(void* _a, void* _b)
{
	return ( *(int*)_a > *(int*)_b);
}

void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}







UNIT(FindFirst_Check_Null)
	int arr[]={5,3,5,4,2};
	int i=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_FindFirst(NULL, end, Predicate, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_FindFirst(begin, NULL, Predicate, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_FindFirst(begin, end, NULL, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_FindFirst(begin, end, Predicate, NULL) == NULL);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(FindFirst_Check_Not_Null)
	int arr[]={5,3,5,4,2};
	int i,j=2;
	ListItr begin,end,status;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	status = ListItr_FindFirst(begin, end, Predicate, (void*) &j);
	ASSERT_THAT(status == begin );
	j=4;
	status = ListItr_FindFirst(begin, end, Predicate, (void*) &j);
	ASSERT_THAT(status == ListItr_Next(begin));
	List_Destroy(&list, DestroyPart);
END_UNIT


UNIT(CountIf_Check_Null)
	int arr[]={5,3,5,4,2};
	int i=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_CountIf(NULL, end, Predicate, (void*) &i) == 0);
	ASSERT_THAT(ListItr_CountIf(begin, NULL, Predicate, (void*) &i) == 0);
	ASSERT_THAT(ListItr_CountIf(begin, end, NULL, (void*) &i) == 0);
	ASSERT_THAT(ListItr_CountIf(begin, end, Predicate, NULL) == 0);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(CountIf_Check_Not_Null)
	int arr[]={5,3,5,4,2};
	int i,j=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_CountIf(begin, end, Predicate, (void*) &j) == 2);
	j=2;
	ASSERT_THAT(ListItr_CountIf(begin, end, Predicate, (void*) &j) == 1);
	j=8;
	ASSERT_THAT(ListItr_CountIf(begin, end, Predicate, (void*) &j) == 0);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(ForEach_Check_Null)
	int arr[]={5,3,5,4,2};
	int i=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_ForEach(NULL, end, Predicate, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_ForEach(begin, NULL, Predicate, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_ForEach(begin, end, NULL, (void*) &i) == NULL);
	ASSERT_THAT(ListItr_ForEach(begin, end, Predicate, NULL) == NULL);
	List_Destroy(&list, DestroyPart);
END_UNIT



UNIT(ForEach_Check_Not_Null)
	int arr[]={5,6,5,4,3};
	int i,j=4;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_ForEach(begin, end, ListAction, (void*) &j) == ListItr_Next(begin));
	ASSERT_THAT(ListItr_ForEach(begin, end, ListAction, (void*) &i) == end);
	
	
	List_Destroy(&list, DestroyPart);
END_UNIT


UNIT(Sort_Check_Not_Null)
	int arr[]={1,2,3,4,5};
	int i;
	void* result;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ListItr_Sort(begin, end, Less);
	begin = ListItr_Begin(list);
	for(i=0;i<5;i++)
	{
		result=ListItr_Get(begin);
		arr[i]=*(int*)result ;
		begin= ListItr_Next(begin);
	}
	for(i=0;i<4;i++)
	{
		ASSERT_THAT(arr[i]<=arr[i+1]);
	}
	
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Splice_Check_Null)
	int arr[]={5,3,5,4,2};
	int i=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_Splice(NULL, begin, end) == NULL);
	ASSERT_THAT(ListItr_Splice(begin, NULL,end) == NULL);
	ASSERT_THAT(ListItr_Splice(begin, end, NULL) == NULL);
	List_Destroy(&list, DestroyPart);
END_UNIT


UNIT(Splice_Check_Not_Null)
	int arr[]={10,3,1};
	int i;
	void* result;
	ListItr begin,end,destenation;
	List* list;
	list=List_Create();
	for(i=0; i<3;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	begin = ListItr_Next(begin);
	destenation = ListItr_Begin(list);
	ListItr_Splice(destenation, begin, end);
	begin = ListItr_Begin(list);
	for(i=0;i<3;i++)
	{
		result = ListItr_Get(begin);
		arr[i]=*(int*)result ;
		/*printf("%d ", arr[i]);*/
		begin = ListItr_Next(begin);
	}
	List_Destroy(&list, DestroyPart);
END_UNIT


UNIT(Merge_Check_Null)
	int arr[]={5,3,5,4,2};
	int i=5;
	ListItr begin,end;
	List* list;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ASSERT_THAT(ListItr_Merge(NULL, begin, end,NULL, begin, Less) == NULL);
	ASSERT_THAT(ListItr_Merge(begin, NULL,end,NULL, begin, Less) == NULL);
	ASSERT_THAT(ListItr_Merge(begin, end, NULL,NULL, begin, Less) == NULL);
	ASSERT_THAT(ListItr_Merge(NULL, begin, end,NULL, begin, Less) == NULL);
	ASSERT_THAT(ListItr_Merge(begin, begin,end,NULL, NULL, Less) == NULL);
	ASSERT_THAT(ListItr_Merge(begin, end, NULL,NULL, begin, NULL) == NULL);
	List_Destroy(&list, DestroyPart);
END_UNIT

UNIT(Merge_Check_Not_Null)
	int arr[]={1,8,2,3,10};
	int i=5;
	ListItr begin,end;
	List* list;
	void* result;
	list=List_Create();
	for(i=0; i<5;i++)
	{
		List_PushHead(list, (void*)&arr[i]);
	}
	begin = ListItr_Begin(list);
	end = ListItr_End(list);
	ListItr_Merge(begin, begin, ListItr_Next(begin),ListItr_Prev(ListItr_Prev(ListItr_Prev(end))), ListItr_Prev(end), Less);
	for(i=0;i<5;i++)
	{
		result = ListItr_Get(begin);
		arr[i]=*(int*)result ;
		printf("%d ", arr[i]);
		begin = ListItr_Next(begin);
	}
	for(i=0;i<4;i++)
	{
		ASSERT_THAT(arr[i]<=arr[i+1]);
	}
	List_Destroy(&list, DestroyPart);
END_UNIT



TEST_SUITE(Function_Iterator_List)

	TEST(FindFirst_Check_Null)
	TEST(FindFirst_Check_Not_Null)
	TEST(CountIf_Check_Null)
	TEST(CountIf_Check_Not_Null)
	TEST(ForEach_Check_Null)
	TEST(ForEach_Check_Not_Null)
	TEST(Sort_Check_Not_Null)
	TEST(Splice_Check_Null)
	TEST(Splice_Check_Not_Null)
	TEST(Merge_Check_Null)
	TEST(Merge_Check_Not_Null)
	
END_SUITE
