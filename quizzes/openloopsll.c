
#define SUCCESS 0
#define FAIL 1

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/

typedef struct node
{

	void *data;
	struct node *next;


}node_t;

int HasNoLoop(const node_t *head);
int OpenLoop(const node_t *head);
void HasNoLoopTest1();
void HasNoLoopTest2();
void HasNoLoopTest3();
void OpenLoopTest1();
void OpenLoopTest2();

int main()
{	
	HasNoLoopTest1();
	HasNoLoopTest2();
	HasNoLoopTest3();
	OpenLoopTest1();
	OpenLoopTest2();
	return 0;
}


void HasNoLoopTest1()
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
	status = HasNoLoop((const node_t *)node1);
	
	if(1 == status)
	{
		printf("HasNoLoopTest1 pass\n");
	}
	else
	{
		printf("HasNoLoopTest1 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);


}

void HasNoLoopTest2()
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
	status = HasNoLoop((const node_t *)node1);
	if(1 == status)
	{
		printf("HasNoLoopTest2 pass\n");
	}
	else
	{
		printf("HasNoLoopTest2 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);

}

void HasNoLoopTest3()
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
	status = HasNoLoop((const node_t *)node1);
	if(0 == status)
	{
		printf("HasNoLoopTest3 pass\n");
	}
	else
	{
		printf("HasNoLoopTest3 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);


}

void OpenLoopTest1()
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
	node5->next = node3;
	status = OpenLoop((const node_t *)node1);
	
	if(NULL == node5->next)
	{
		printf("OpenLoopTest1 pass\n");
	}
	else
	{
		printf("OpenLoopTest1 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);


}

void OpenLoopTest2()
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
	node6->next = node3;
	status = OpenLoop((const node_t *)node1);
	if(NULL == node6->next)
	{
		printf("OpenLoopTest2 pass\n");
	}
	else
	{
		printf("OpenLoopTest2 fail\n");
	
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);

}

int HasNoLoop(const node_t *head)
{
	node_t *temp1 = NULL;
	node_t *temp2 = NULL;
	
	assert(NULL != head);
	
	temp1 = (node_t *)head;
	temp2 = (node_t *)head->next;
	
	while(NULL != temp2 && NULL != temp2->next)
	{
		if(temp1 == temp2)
		{
			
			return FAIL;
		}
		
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	
	return SUCCESS;

}

int OpenLoop(const node_t *head)
{
	node_t *slow = NULL;
	node_t *fast = NULL;
	node_t *open_loop = NULL;
	size_t counter = 0;
	size_t loop_size = 0;
	
	assert(head);
	
	if(!HasNoLoop(head))
	{
		return FAIL;
	}
	
	slow = (node_t *)head;
	fast = (node_t *)head->next;
	open_loop = (node_t *)head;
	
	while(slow != fast && slow != fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	
	while(fast != slow)
	{
		++loop_size;
		fast = fast->next;
	}
	slow = open_loop->next;
	while(NULL != open_loop)
	{
		
		counter = 0;
		while(counter != loop_size + 1)
		{
			
			if(slow->next == open_loop)
			{
				slow->next = NULL;
				return SUCCESS;
			}
			
		
			slow = slow->next;
			++counter;
		}
		slow = open_loop->next;
		open_loop = open_loop->next;
	}
	return FAIL;
}
