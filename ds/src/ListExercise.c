/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 02/05/2023
*/

#define SUCCESS 0
#define FAIL 1


#include <assert.h> /*assert*/


#include "ListExercise.h"









node_t *Flip(node_t *head)
{
	node_t *temp_next = head->next;
	node_t *temp= head;
	node_t *temp2= head;
	assert(NULL != head);
	
	
	while(NULL != temp2)
	{
		temp2 = temp_next->next;
		temp_next->next = temp;
		temp = temp_next;
		temp_next = temp2;
	}
	head->next = NULL;
	
	return temp;
}


node_t *FindIntersection(node_t *head1, node_t *head2)
{
	node_t *length_list1 = head1;
	node_t *length_list2 = head2;
	int counter1 = 0;
	int counter2 = 0;
	int move = 0;
	
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
			move++;
		}
	}
	else
	{
		while(move != counter2 - counter1)
		{
			length_list2 = length_list2->next;
			move++;
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



int HasLoop(const node_t *head)
{
	node_t *temp1 = (node_t *)head;
	node_t *temp2 = (node_t *)head->next;
	
	while(NULL != temp2 && NULL != temp2->next)
	{
		if(temp1 == temp2)
		{
			
			return SUCCESS;
		}
		
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	
	return FAIL;

}









