

#define SUCCESS 0
#define FAIL 1

#include <stdio.h> /*assert*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*free*/

typedef struct node
{

	void *data;
	struct node *next;


}node_t;

node_t *Flip(node_t *head)
{
	node_t *current = head->next;
	node_t *prev= head;
	node_t *next= head;

	assert(head);
	
	
	while(NULL != next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head->next = NULL;
	
	return prev;
}


node_t *FlipRecursive(node_t *head)
{
    node_t *result = NULL;
    assert(head);
	if (NULL == head  || NULL == head->next)
    {
        return head;
    }   
    result = FlipRecursive(head->next);
    head->next->next = head;  
    head->next = NULL;   
    return result;
}



int main()
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
	
	
	
	temp = FlipRecursive(node1);
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
	
	return 0;
}
