/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 07/05/2023
*/
#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h> /* size_t */

typedef struct Node node_t;


typedef struct DList dlist_t;


typedef node_t * dlist_iter_t;



/***********************************************************************/
/*
Description: Create a double linked list.
Arguments: Void.
Return: List pointer on success and NULL on fail.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_t *DListCreate(void); /*done*/

/***********************************************************************/
/*
Description: Destroy the linked list.
Arguments: Valid pointer to a list.
Return: Void.
Time complexity: O(n).
Space complexity: O(1).
*/

void DListDestroy(dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Count amount of nodes in the list.
Arguments: Valid const pointer to list.
Return: Size of list.
Time complexity: O(n).
Space complexity: O(1).
*/

size_t DListSize(const dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Insert a node with a value before where.
Arguments: Valid pointer of where and pointer of data.
Return: The node inserted on success and dummy node of tail on fail.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListInsert(dlist_iter_t where, void *data); /*done*/

/***********************************************************************/
/*
Description: Remove a node from a list
Arguments: Valid pointer to the current location.
Return: The next node.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListRemove(dlist_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Return the next node.
Arguments: Valid pointer to a current node.
Return: Pointer to next node.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListNext(dlist_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Return the previous node.
Arguments: Valid pointer to a current node.
Return: Pointer to previous node.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListPrev(dlist_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Check if list is empty.
Arguments: Valid constant pointer of list.
Return: 1 if empty and 0 if not.
Time complexity: O(1).
Space complexity: O(1).
*/

int DListIsEmpty(const dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Find the value param in the list.
Arguments: Valid pointers to iterators from, to, param and a pointer to function.
Return: The found node on success and to node on fail.
Time complexity: O(n).
Space complexity: O(1).
*/

dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, int (*match_func)(void *data, const void *param), const void *param) ; /*done*/

/***********************************************************************/
/*
Description: Make an action on the node from to to.
Arguments: Valid pointer from, to, action_param and a pointer to function.
Return: Status if the function action worked if 0 returned and 1 if failed.
Time complexity: O(n).
Space complexity: O(1).
*/

int DListForEach(dlist_iter_t from, dlist_iter_t to, int(*action_func)(void *data, void *param), void *action_param); /*done*/

/***********************************************************************/
/*
Description: Set data to the data parameter.
Arguments: Valid pointer current.
Return: Void.
Time complexity: O(1).
Space complexity: O(1).
*/

void DListSetData(dlist_iter_t current, void *data); /*done*/

/***********************************************************************/
/*
Description: Gets the data from the current iterator.
Arguments: Valid pointer to current.
Return: The data of the current node.
Time complexity: O(1).
Space complexity: O(1).
*/

void *DListGetData(dlist_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Check if the two etarators are equal.
Arguments: Valid two iterator pointers.
Return: 1 if they are equal and 0 if not.
Time complexity: O(1).
Space complexity: O(1).
*/

int DListIsEqual(dlist_iter_t iter1 , dlist_iter_t iter2); /*done*/

/***********************************************************************/
/*
Description: Return the begining iterator of the list.
Arguments: Valid constant list pointer.
Return: The iterator in the begining of the list.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListBegin(const dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Return the end iterator of the list.
Arguments: Valid constant list pointer.
Return: The iterator in the end of the list.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListEnd(const dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Push a new node to the end of the list.
Arguments: Valid list and data pointers.
Return: The node after the entered node.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListPushBack(dlist_t *list, void *data); /*done*/

/***********************************************************************/
/*
Description: Push a new node to the front of the list.
Arguments: Valid list and data pointers.
Return: The node after the entered node.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListPushFront(dlist_t *list, void *data); /*done*/

/***********************************************************************/
/*
Description: Pop a new node to the front of the list.
Arguments: Valid list pointer.
Return: The value of the node poped.
Time complexity: O(1).
Space complexity: O(1).
*/

void *DListPopFront(dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Pop a new node to the end of the list.
Arguments: Valid list pointer.
Return: The value of the node poped.
Time complexity: O(1).
Space complexity: O(1).
*/

void *DListPopBack(dlist_t *list); /*done*/

/***********************************************************************/
/*
Description: Get the nodes from up to to before where.
Arguments: 3 pointers to a valid location and where from and to are from one list an where is from another.
Return: Iterator to the "from" node in its new location.
Time complexity: O(1).
Space complexity: O(1).
*/

dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to);

/***********************************************************************/
/*
Description: Find multiple nodes that satisfy the match function.
Arguments: Valid pointers to from, to, param, output_list and output_list.
Return: 1 if something found and 0 if not.
Time complexity: O(n).
Space complexity: O(n).
*/
int DListMultiFind(dlist_iter_t from, dlist_iter_t to, int (*match_func)(void *data, const void *param), const void *param, dlist_t *output_list);






#endif /* __DLIST_H__ */
