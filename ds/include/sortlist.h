

/*
Rev: 
Dev: Leonid Golovko
status: finished
date: 
*/
#ifndef __SORT_LIST_H__
#define __SORT_LIST_H__

#include <stddef.h> /* size_t */

#include "dlist.h" 

typedef struct SortList sort_list_t;


typedef struct SortIter
{
	dlist_iter_t iter;
	#ifndef NDEBUG
	sort_list_t *list;
	#endif /*NDEBUG*/
} sort_iter_t;

typedef int (*compare_t)(void *, const void *); /*comparative int*/
typedef int (*action_t)(void *, void *);
typedef compare_t is_match_t; /*reuse name for boolean*/

/***********************************************************************/
/*
Description: Create a sorted list.
Arguments: Compare function.
Return: Pointer to a sorted list on success and NULL on fail.
Time complexity: O(1).
Space complexity: O(1).
*/

sort_list_t *SortListCreate(compare_t func); /*done*/

/***********************************************************************/
/*
Description: Destroy a sorted list.
Arguments: Valid poiter to a sorted list.
Return: Void.
Time complexity: O(n).
Space complexity: O(1).
*/

void SortListDestroy(sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Insert the value in the right location of the list.
Arguments: Valid pointer to a list and pointer to the data.
Return: The inserted node on success and tail dummy on fail.
Time complexity: O(n).
Space complexity: O(1).
*/

sort_iter_t SortListInsert(sort_list_t *list, void *data);

/***********************************************************************/
/*
Description: Remove a node from a sorted list.
Arguments: Valid pointer to the current location.
Return: The next node.
Time complexity: O(1).
Space complexity: O(1).
*/

sort_iter_t SortListRemove(sort_iter_t current); /*done*/

/***********************************************************************/

/*
Description: Find the value param in the list.
Arguments: Valid pointers to iterators from, to, param and a pointer to list.
Return: The found node on success and to node on fail.
Time complexity: O(n).
Space complexity: O(1).
*/

sort_iter_t SortListFind(sort_iter_t from, sort_iter_t to, sort_list_t *list, void *param); /*done*/

/***********************************************************************/

/*
Description: Make an action on the node from to to.
Arguments: Valid pointer from, to, action_param and a pointer to function.
Return: Status if the function action worked if 0 returned and 1 if failed.
Time complexity: O(n).
Space complexity: O(1).
*/

int SortListForEach(sort_iter_t from, sort_iter_t to, action_t action, void *action_param); /*done*/

/***********************************************************************/
/*
Description: Count amount of nodes in the list.
Arguments: Valid const pointer to list.
Return: Size of list.
Time complexity: O(n).
Space complexity: O(1).
*/

size_t SortListSize(const sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Check if list is empty.
Arguments: Valid constant pointer of list.
Return: 1 if empty and 0 if not.
Time complexity: O(1).
Space complexity: O(1).
*/

int SortListIsEmpty(sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Return the next node.
Arguments: Valid current node.
Return: Next node.
Time complexity: O(1).
Space complexity: O(1).
*/

sort_iter_t SortListNext(sort_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Return the previous node.
Arguments: Valid current node.
Return: Previous node.
Time complexity: O(1).
Space complexity: O(1).
*/


sort_iter_t SortListPrev(sort_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Return the begining iterator of the list.
Arguments: Valid constant list pointer.
Return: The iterator in the begining of the list.
Time complexity: O(1).
Space complexity: O(1).
*/

sort_iter_t SortListBegin(const sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Return the end iterator of the list.
Arguments: Valid constant list pointer.
Return: The iterator in the end of the list.
Time complexity: O(1).
Space complexity: O(1).
*/

sort_iter_t SortListEnd(const sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Gets the data from the current iterator.
Arguments: Valid pointer to current.
Return: The data of the current node.
Time complexity: O(1).
Space complexity: O(1).
*/

void *SortListGetData(sort_iter_t current); /*done*/

/***********************************************************************/
/*
Description: Pop a new node to the front of the list.
Arguments: Valid list pointer.
Return: The value of the node poped.
Time complexity: O(1).
Space complexity: O(1).
*/

void *SortListPopFront(sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Pop a new node to the end of the list.
Arguments: Valid list pointer.
Return: The value of the node poped.
Time complexity: O(1).
Space complexity: O(1).
*/

void *SortListPopBack(sort_list_t *list); /*done*/

/***********************************************************************/
/*
Description: Get all nodes from src to dest list in a sorted way.
Arguments: Valid pointer to list dest and src.
Return: Void.
Time complexity: O(n).
Space complexity: O(1).
*/

void SortListMerge(sort_list_t *dest, sort_list_t *src); /* done */

/***********************************************************************/
/*
Description: Find node with the match function.
Arguments: Valid iterator from, to, function match and void pointer of the param that will be entered the match fucntion.
Return: The found node on success and to on fail.
Time complexity: O(n).
Space complexity: O(1).
*/

sort_iter_t SortListFindIf(sort_iter_t from, sort_iter_t to, is_match_t is_match, void *param); /*done*/

/*
Description: 
Arguments:
Return: 

Time complexity: O().
Space complexity: O().
*/
int SortListIsEqual(sort_iter_t iter1 , sort_iter_t iter2);

#endif /* __SORT_LIST_H__ */
