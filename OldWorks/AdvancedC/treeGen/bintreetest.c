



#include <stdio.h>
#include "mu_test.h"
#include "binary.h"

int Predicate(void * _element, void* _context)
{
	return (*(int*)_element == *(int*)_context);
}
int Compare(void* _left, void* _right)
{
	return (*(int*)_left < *(int*)_right);
}

void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}


UNIT(Tree_Create_Null)
	
	ASSERT_THAT(BSTree_Create(NULL) == NULL );
	
END_UNIT

UNIT(Tree_Create_Not_Null)
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_Destroy)
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT




UNIT(Tree_Insert_Null)
	int i=5;
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	ASSERT_THAT(BSTree_Insert(NULL, (void*)&i) == NULL);
	ASSERT_THAT(BSTree_Insert(tree, NULL) == BSTreeItr_End(tree));
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT


UNIT(Tree_Insert_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_Begin_Null)
	
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	ASSERT_THAT(BSTreeItr_Begin(NULL) == NULL );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT


UNIT(Tree_Begin_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	void* num;
	BSTree* tree;
	BSTreeItr status;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	status = BSTreeItr_Begin(tree);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Get(status);
	ASSERT_THAT(*(int*)num == 2 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_End_Null)
	
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	ASSERT_THAT(BSTreeItr_End(NULL) == NULL );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT


UNIT(Tree_End_Not_Null)
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	ASSERT_THAT(BSTreeItr_End(tree) != NULL );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_Equals_Not_Null)
	
	
	int arr[]={9,7,5,3,2};
	int i;
	
	BSTree* tree;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	ASSERT_THAT(BSTreeItr_Equals(BSTreeItr_Begin(tree), BSTreeItr_Begin(tree)) == 1 );
	ASSERT_THAT(BSTreeItr_Equals(BSTreeItr_Begin(tree), BSTreeItr_End(tree)) == 0 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_Get_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	void* num;
	BSTree* tree;
	BSTreeItr status;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	status = BSTreeItr_Begin(tree);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Get(status);
	ASSERT_THAT(*(int*)num == 2 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT


UNIT(Tree_Find_First_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	void* num;
	BSTree* tree;
	BSTreeItr status;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	status =BSTree_FindFirst(BSTreeItr_Begin(tree), BSTreeItr_End(tree), Predicate, (void*)&arr[3]);
	num = BSTreeItr_Get(status);
	ASSERT_THAT(*(int*)num == 3 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_Remove_leaf_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	void* num;
	BSTree* tree;
	BSTreeItr status;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	status = BSTreeItr_Begin(tree);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Remove(status);
	ASSERT_THAT(*(int*)num == 2 );
	status = BSTreeItr_Begin(tree);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Remove(status);
	ASSERT_THAT(*(int*)num == 3 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT

UNIT(Tree_parent_one_son_Not_Null)
	int arr[]={9,7,5,3,2};
	int i;
	void* num;
	BSTree* tree;
	BSTreeItr status;
	tree = BSTree_Create(Compare);
	ASSERT_THAT(tree != NULL );
	for(i=0;i<5; i++)
	{
		ASSERT_THAT(BSTree_Insert(tree, (void*)&arr[i]) != NULL);
	}	
	status = BSTreeItr_Begin(tree);
	status = BSTreeItr_Next(status);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Remove(status);
	ASSERT_THAT(*(int*)num == 3 );
	status = BSTreeItr_Begin(tree);
	ASSERT_THAT(status != NULL );
	num = BSTreeItr_Remove(status);
	ASSERT_THAT(*(int*)num == 2 );
	BSTree_Destroy(&tree, DestroyPart);
END_UNIT



TEST_SUITE(TEST_Gen_Bin_Tree)
	TEST(Tree_Create_Null)
	TEST(Tree_Create_Not_Null)
	TEST(Tree_Destroy)
	TEST(Tree_Insert_Null)
	TEST(Tree_Insert_Not_Null)
	TEST(Tree_Begin_Null)
	TEST(Tree_Begin_Not_Null)
	TEST(Tree_End_Null)
	TEST(Tree_End_Not_Null)
	TEST(Tree_Equals_Not_Null)
	TEST(Tree_Get_Not_Null)
	TEST(Tree_Find_First_Not_Null)
	TEST(Tree_Remove_leaf_Not_Null)
	TEST(Tree_parent_one_son_Not_Null)
	
END_SUITE
