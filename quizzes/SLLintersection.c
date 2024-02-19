
#define SUCCESS 0
#define FAIL 1


#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf*/

#include "ListExercise.h"
void FreeIntersectionTest1();
void FindIntersectionTest1();
void FindIntersectionTest2();
node_t *FindIntersection(node_t *head1, node_t *head2);
node_t *SeperateIntersection(node_t *head1, node_t *head2);

int main()
{	
	FindIntersectionTest1();
	FindIntersectionTest2();
	FreeIntersectionTest1();
	return 0;
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


void FreeIntersectionTest1()
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
	
	
	
	result = SeperateIntersection(node1, node6);
	if(result == node1 && NULL == node1->next)
	{
		printf("FreeIntersectionTest1 pass\n");
	}
	else
	{
		printf("FreeIntersectionTest1 fail\n");
		/*printf("node 1 %p\n", node1);
		printf("node 2 %p\n", node2);
		printf("node 3 %p\n", node3);
		printf("node 4 %p\n", node4);
		printf("node 5 %p\n", node5);
		printf("node 6 %p\n", node6);
		printf("node 7 %p\n", node7);
		printf("node 8 %p\n", node8);
		printf("result %p\n", result);*/
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

node_t *FindIntersection(node_t *head1, node_t *head2)
{
	node_t *length_list1 = NULL;
	node_t *length_list2 = NULL;
	int counter1 = 0;
	int counter2 = 0;
	int move = 0;
	
	assert(head1);
	assert(head2);
	
	length_list1 = head1;
	length_list2 = head2;
	
	while(NULL != length_list1)
	{
		++counter1;
		length_list1 = length_list1->next;
	}
	
	while(NULL != length_list2)
	{
		++counter2;
		length_list2 = length_list2->next;
	}
	
	length_list1 = head1;
	length_list2 = head2;
	
	if(counter1 > counter2)
	{
		while(move != counter1 - counter2)
		{
			length_list1 = length_list1->next;
			++move;
		}
	}
	else
	{
		while(move != counter2 - counter1)
		{
			length_list2 = length_list2->next;
			++move;
		}
	}
	
	while(NULL != length_list1)
	{
		if(length_list1 == length_list2)
		{
			return length_list1;
		}
		
		length_list1 = length_list1->next;
		length_list2 = length_list2->next;
	}
	
	return NULL;
}



node_t *SeperateIntersection(node_t *head1, node_t *head2)
{
	node_t *length_list1 = NULL;
	node_t *length_list2 = NULL;
	int counter1 = 0;
	int counter2 = 0;
	int move = 0;
	
	assert(head1);
	assert(head2);
	
	length_list1 = head1;
	length_list2 = head2;
	

	while(NULL != length_list1)
	{
		++counter1;
		length_list1 = length_list1->next;
	}
	
	while(NULL != length_list2)
	{
		++counter2;
		length_list2 = length_list2->next;
	}
	
	length_list1 = head1;
	length_list2 = head2;
	
	if(counter1 > counter2)
	{
		while(move  != counter1 - counter2)
		{
			length_list1 = length_list1->next;
			++move;
		}
	}
	else
	{
		while(move != counter2 - counter1)
		{
			length_list2 = length_list2->next;
			++move;
		}
	}
	while(NULL != length_list1->next)
	{
		if(length_list1->next == length_list2->next)
		{
			length_list1->next = NULL;
			return length_list1;
		}
		
		length_list1 = length_list1->next;
		length_list2 = length_list2->next;
	}
	
	return NULL;
}

