
/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date:04/06/2023
*/

#include <stdio.h> /*printf*/
#include "avl.h" 

#define COUNT 3

int Compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int ForEachOper(void *val1, void *val2)
{
    (void)val2;
    printf("The number is: %d, ", *(int *)val1);
    return 0;
}


void print2DUtil(avl_node_t* root, int space)
{
    int i = 0;

    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2DUtil(root->children[RIGHT], space);

    printf("\n");
    
    for (i = COUNT; i < space; i++)
    {
        printf(" ");
    }

    printf("%d\n", *(int *)root->data);
 
    print2DUtil(root->children[LEFT], space);
    
    printf("\n");
}

void print2D(avl_tree_t* tree)
{
    print2DUtil(tree->root, 0);
}



void AVLCreateTest();
void AVLInsertTest1();
void AVLInsertTest2();
void AVLInsertTest3();
void AVLInsertTest4();
void AVLFindTest();
void AVLCountTest();
void AVLHeightTest();
void AVLForEachTest();
void AVLRemoveTest();



int main()
{	
	AVLCreateTest();
    AVLInsertTest1();
	AVLInsertTest2();
	AVLInsertTest3();
	AVLInsertTest4();
    AVLFindTest();
    AVLCountTest();
    AVLHeightTest();
    AVLForEachTest();
    AVLRemoveTest();
	return 0;
}




void AVLCreateTest()
{
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	
	if(NULL != tree && 1 == AVLIsEmpty((const avl_tree_t *)tree))
	{
		printf("AVLCreateTest pass\n");
	}
	else
	{
		printf("AVLCreateTest fail\n");
	}	
	AVLDestroy(tree);	
}


void AVLInsertTest1()
{
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	result1 = AVLInsert(tree, (void *)&value1);
	result2 = AVLInsert(tree, (void *)&value2);
	result3 = AVLInsert(tree, (void *)&value3);

	print2D(tree);
	if(NULL != tree && 0 == result1 && 0 == result2 && 0 == result3 && 0 == AVLIsEmpty((const avl_tree_t *)tree))
	{
		printf("AVLInsertTest1 pass\n");
		printf("AVLIsEmpty pass\n");
        printf("AVLDestroy pass\n");
	}
	else
	{
		printf("AVLInsertTest fail\n");
		printf("AVLIsEmpty fail\n");
		printf("AVLDestroy fail\n");
	}	
	AVLDestroy(tree);		
}

void AVLInsertTest2()
{
	int value1 = 5;
	int value2 = 4;
	int value3 = 3;
	
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	result1 = AVLInsert(tree, (void *)&value1);
	result2 = AVLInsert(tree, (void *)&value2);
	result3 = AVLInsert(tree, (void *)&value3);

	print2D(tree);
	if(NULL != tree && 0 == result1 && 0 == result2 && 0 == result3 && 0 == AVLIsEmpty((const avl_tree_t *)tree))
	{
		printf("AVLInsertTest2 pass\n");
	}
	else
	{
		printf("AVLInsertTest2 fail\n");
	}	
	AVLDestroy(tree);		
}


void AVLInsertTest3()
{
	int value1 = 10;
	int value2 = 6;
	int value3 = 8;
	
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	result1 = AVLInsert(tree, (void *)&value1);
	result2 = AVLInsert(tree, (void *)&value2);
	result3 = AVLInsert(tree, (void *)&value3);

	print2D(tree);
	if(NULL != tree && 0 == result1 && 0 == result2 && 0 == result3 && 0 == AVLIsEmpty((const avl_tree_t *)tree))
	{
		printf("AVLInsertTest3 pass\n");
	}
	else
	{
		printf("AVLInsertTest3 fail\n");
	}	
	AVLDestroy(tree);		
}

void AVLInsertTest4()
{
	int value1 = 10;
	int value2 = 20;
	int value3 = 15;
	
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	result1 = AVLInsert(tree, (void *)&value1);
	result2 = AVLInsert(tree, (void *)&value2);
	result3 = AVLInsert(tree, (void *)&value3);

	print2D(tree);
	if(NULL != tree && 0 == result1 && 0 == result2 && 0 == result3 && 0 == AVLIsEmpty((const avl_tree_t *)tree))
	{
		printf("AVLInsertTest4 pass\n");
	}
	else
	{
		printf("AVLInsertTest4 fail\n");
	}	
	AVLDestroy(tree);		
}

void AVLFindTest()
{
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	
    int wrong_value1 = 44;
    int wrong_value2 = 41;
    int wrong_value3 = 42;
    int wrong_value4 = 43;
	void *find1 = NULL;
    void *find2 = NULL;
    void *find3 = NULL;
    void *find4 = NULL;
    void *find5 = NULL;
    void *find6 = NULL;
   

	avl_tree_t *tree = AVLCreate(Compare);
	
	AVLInsert(tree, (void *)&value1);
	AVLInsert(tree, (void *)&value2);
	AVLInsert(tree, (void *)&value3);
	AVLInsert(tree, (void *)&value4);
	AVLInsert(tree, (void *)&value5);
	AVLInsert(tree, (void *)&value6);

    find1 = AVLFind(tree, (const void *)&value5);
	find2 = AVLFind(tree, (const void *)&wrong_value1);
    find3 = AVLFind(tree, (const void *)&wrong_value2);
    find4 = AVLFind(tree, (const void *)&wrong_value3);
	find5 = AVLFind(tree, (const void *)&wrong_value4);
    find6 = AVLFind(tree, (const void *)&value2);

	if(value5 == *(int *)find1 && NULL == find2 && NULL == find3 && NULL == find4 && NULL == find5 && value2 == *(int *)find6)
	{
		printf("AVLFindTest pass\n");
	}
	else
	{
		printf("AVLFindTest fail\n");	
	}	
	AVLDestroy(tree);		
}


void AVLCountTest()
{

    int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	int value7 = 7;
	int value8 = 8;
	int value9 = 10;
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	AVLInsert(tree, (void *)&value1);
	AVLInsert(tree, (void *)&value2);
	AVLInsert(tree, (void *)&value3);
	AVLInsert(tree, (void *)&value4);
	AVLInsert(tree, (void *)&value5);
	AVLInsert(tree, (void *)&value6);
    AVLInsert(tree, (void *)&value7);
	AVLInsert(tree, (void *)&value8);
	AVLInsert(tree, (void *)&value9);
	
	if(9 == AVLCount((const avl_tree_t *)tree))
	{
		printf("AVLCountTest pass\n");
	}
	else
	{
		printf("AVLCountTest fail\n");
        printf("%ld\n", AVLCount((const avl_tree_t *)tree));
	}	
	AVLDestroy(tree);		
}

void AVLHeightTest()
{

    int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	
	avl_tree_t *tree = AVLCreate(Compare);
	
	AVLInsert(tree, (void *)&value1);
	AVLInsert(tree, (void *)&value2);
	AVLInsert(tree, (void *)&value3);
	AVLInsert(tree, (void *)&value4);
	AVLInsert(tree, (void *)&value5);
	AVLInsert(tree, (void *)&value6);
    
	
	if(3 == AVLHeight((const avl_tree_t *)tree))
	{
		printf("AVLHeightTest pass\n");
	}
	else
	{
		printf("AVLHeightTest fail\n");
        printf("%ld\n", AVLHeight((const avl_tree_t *)tree));
	}	
	AVLDestroy(tree);		
}


void AVLForEachTest()
{
    int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	int value7 = 55;
	int value8 = 6;
    int value9 = 33;
	int value10 = 10;

    int status1 = 0;
    int status2 = 0;
    int status3 = 0;

	avl_tree_t *tree = AVLCreate(Compare);
	
	AVLInsert(tree, (void *)&value1);
	AVLInsert(tree, (void *)&value2);
	AVLInsert(tree, (void *)&value3);
	AVLInsert(tree, (void *)&value4);
	AVLInsert(tree, (void *)&value5);
	AVLInsert(tree, (void *)&value6);
    AVLInsert(tree, (void *)&value7);
    AVLInsert(tree, (void *)&value8);
    AVLInsert(tree, (void *)&value9);
    AVLInsert(tree, (void *)&value10);
    

    printf("IN_ORDER\n");
    status1 = AVLForEach(tree, IN_ORDER, ForEachOper, NULL);
    printf("\n");
    printf("POST_ORDER\n");
    status2 = AVLForEach(tree, POST_ORDER, ForEachOper, NULL);
    printf("\n");
    printf("PRE_ORDER\n");
    status3 = AVLForEach(tree, PRE_ORDER, ForEachOper, NULL);
    printf("\n");

	if(0 == status1 && 0 == status2 && 0 == status3)
	{
		printf("AVLForEachTest pass\n");
	}
	else
	{
		printf("AVLForEachTest fail\n");
	}	
	AVLDestroy(tree);		
}



void AVLRemoveTest()
{
    int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	int value7 = 55;
	int value8 = 6;
    int value9 = 33;
	int value10 = 10;

    

	avl_tree_t *tree = AVLCreate(Compare);
	
	AVLInsert(tree, (void *)&value1);
	AVLInsert(tree, (void *)&value2);
	AVLInsert(tree, (void *)&value3);
	AVLInsert(tree, (void *)&value4);
	AVLInsert(tree, (void *)&value5);
	AVLInsert(tree, (void *)&value6);
    AVLInsert(tree, (void *)&value7);
    AVLInsert(tree, (void *)&value8);
    AVLInsert(tree, (void *)&value9);
    AVLInsert(tree, (void *)&value10);
	printf("\nAVLHeight((const avl_tree_t *)tree) is %ld\n", AVLHeight((const avl_tree_t *)tree));
	print2D(tree);
	AVLRemove(tree, (void *)&value3);
    AVLRemove(tree, (void *)&value5);


	printf("\nAVLHeight((const avl_tree_t *)tree) is %ld\n", AVLHeight((const avl_tree_t *)tree));
    
	print2D(tree);

    printf("IN_ORDER\n");
    AVLForEach(tree, IN_ORDER, ForEachOper, NULL);
    printf("\nAVLHeight((const avl_tree_t *)tree) is %ld\n", AVLHeight((const avl_tree_t *)tree));
    printf("AVLRemoveTest pass\n");
	
	AVLDestroy(tree);		
}