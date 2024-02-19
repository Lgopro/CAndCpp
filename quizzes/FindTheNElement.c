


#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/


typedef struct node
{

	void *data;
	struct node *next;


}node_t;

void *GetTheNElement(node_t *node, size_t elem_num);

int main()
{
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	void * result = NULL;
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
	
	
	result = GetTheNElement(node1, 4);
	
	printf("The result is %d\n", *(int *)result);
	
	
	
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	
	
	
	return 0;
}

void *GetTheNElement(node_t *node, size_t elem_num)
{
	static size_t counter = 0;
	void *result = NULL;
	if(NULL != node->next)
	{
		result = GetTheNElement(node->next, elem_num);
		
	}
	
	if(elem_num == counter)
	{
		++counter;
		return node->data;
		
	}
	
	++counter;
	return result;

}

