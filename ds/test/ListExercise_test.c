/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

#include "ListExercise.h"



void FlipTest();
void HasLoopTest1();
void HasLoopTest2();
void HasLoopTest3();
void FindIntersectionTest1();
void FindIntersectionTest2();
int main()
{	
	
	FlipTest();
	HasLoopTest1();
	HasLoopTest2();
	HasLoopTest3();
	FindIntersectionTest1();
	FindIntersectionTest2();
	
	return 0;
}




void FlipTest()
{
	
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	node_t * temp = NULL;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	node1->data = (void *)&val1;
	node2->data = (void *)&val2;
	node3->data = (void *)&val3;
	node4->data = (void *)&val4;
	node5->data = (void *)&val5;
	temp  = node1;
	
	
	
	temp = Flip(node1);
	if(5 == *(int *)temp->data && 4 == *(int *)temp->next->data && 3 == *(int *)temp->next->next->data && 2 == *(int *)temp->next->next->next->data && 1 == *(int *)temp->next->next->next->next->data)
	{
		printf("FlipTest pass\n");
	}
	
	else
	{
		printf("FlipTest fail\n");
	}
	
	
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	
	
}
void FindIntersectionTest1()
{
	
	node_t * result = NULL;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	node_t * node6 = (node_t *)malloc(sizeof(node_t));
	node_t * node7 = (node_t *)malloc(sizeof(node_t));
	node_t * node8 = (node_t *)malloc(sizeof(node_t));
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	node6->next = node7;
	node7->next = node8;
	node8->next = node2;
	
	
	
	result = FindIntersection(node1, node6);
	if(result == node2)
	{
		printf("Intersection test1 pass\n");
	}
	else
	{
		printf("Intersection test1 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	free(node7);
	free(node8);
}

void FindIntersectionTest2()
{
	
	node_t * result = NULL;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	node_t * node6 = (node_t *)malloc(sizeof(node_t));
	node_t * node7 = (node_t *)malloc(sizeof(node_t));
	node_t * node8 = (node_t *)malloc(sizeof(node_t));
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	node6->next = node7;
	node7->next = node8;
	node8->next = NULL;
	
	
	
	result = FindIntersection(node1, node6);
	if(result == NULL)
	{
		printf("Intersection test2 pass\n");
	}
	else
	{
		printf("Intersection test2 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	free(node7);
	free(node8);
}
void HasLoopTest1()
{
	int status = 20;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node1;
	status = HasLoop((const node_t *)node1);
	
	if(0 == status)
	{
		printf("HasLoopTest1 pass\n");
	}
	else
	{
		printf("HasLoopTest1 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);


}
void HasLoopTest2()
{
	int status = 20;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	node_t * node6 = (node_t *)malloc(sizeof(node_t));
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node5->next = node1;
	status = HasLoop((const node_t *)node1);
	if(0 == status)
	{
		printf("HasLoopTest2 pass\n");
	}
	else
	{
		printf("HasLoopTest2 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);

}
void HasLoopTest3()
{
	int status = 20;
	node_t * node1 = (node_t *)malloc(sizeof(node_t));
	node_t * node2 = (node_t *)malloc(sizeof(node_t));
	node_t * node3 = (node_t *)malloc(sizeof(node_t));
	node_t * node4 = (node_t *)malloc(sizeof(node_t));
	node_t * node5 = (node_t *)malloc(sizeof(node_t));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	status = HasLoop((const node_t *)node1);
	if(1 == status)
	{
		printf("HasLoopTest3 pass\n");
	}
	else
	{
		printf("HasLoopTest3 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);


}

