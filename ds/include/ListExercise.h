/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 02/05/2023
*/
#ifndef __SLISTEXER_H__
#define __SLISTEXER_H__


#include <stddef.h>




typedef struct node
{

	void *data;
	struct node *next;


}node_t;


/*
Description: Flips the entered linked list.
Arguments: Valid head pointer.
Return: The head of the begining of the new list.
Time complexity: O(n)
Space complexity: O(1)
*/

node_t *Flip(node_t *head);

/*
Description: Check if the function has loop or not.
Arguments: Valid const node.
Return: 0 on success and 1 on fail.
Time complexity: O(n)
Space complexity: O(1)
*/

int HasLoop(const node_t *head);



/*
Description: Find if lists intersect or not.
Arguments: Two valid node_t pointers.
Return: The node on success and NULL on fail.
Time complexity: O(n)
Space complexity: O(1)
*/

node_t *FindIntersection(node_t *head1, node_t *head2);










#endif /*__SLISTEXER_H__*/
