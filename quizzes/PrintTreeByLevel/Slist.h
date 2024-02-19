/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 1/05/2023
*/

#ifndef __SLIST_H__
#define __SLIST_H__

typedef struct Node node_t;

typedef struct SList slist_t;



typedef node_t * iter_t;

typedef int(*is_match_t)(void *, void *);

typedef int (*action_t)(void *, void *);

/***********************************************************************/
/*
Description: Create a list.
Arguments: None.
Return: Pointer to list.
Time complexity: O(1)
Space complexity: O(1)
*/
slist_t *SListCreate(void);

/***********************************************************************/
/*
Description: Destroy a list.
Arguments: Valid list pointer.
Return: Void.
Time complexity: O(n)
Space complexity: O(1)
*/
void SListDestroy(slist_t *list);

/***********************************************************************/
/*
Description: Find the value in the itertors from to.
Arguments: Valid itertors from and to, valid value and a pointer to a function.
Return: Pointer to itertor.
Time complexity: O(n)
Space complexity: O(1)
*/
iter_t SListFind(iter_t from, iter_t to, const void *value, is_match_t matcher) ;

/***********************************************************************/
/*
Description: Insert iterator.
Arguments: Valid iterator and value.
Return: Iterator created on success and last itertor on fail.
Time complexity: O(1)
Space complexity: O(1)
*/
iter_t SListInsert(iter_t where, void *value);

/***********************************************************************/
/*
Description: Remove iterator.
Arguments: Valid iterator.
Return: Next iterator.
Time complexity: O(1)
Space complexity: O(1)
*/
iter_t SListRemove(iter_t where);

/***********************************************************************/
/*
Description: Count amount of nodes.
Arguments: Valid pointer to a list.
Return: Amount of nodes.
Time complexity: O(n)
Space complexity: O(n)
*/
size_t SListCount(const slist_t *list);

/***********************************************************************/
/*
Description: Find end of list.
Arguments: Valid list pointer.
Return: End of list.
Time complexity: O(1)
Space complexity: O(1)
*/
iter_t SListEnd(const slist_t *list);

/***********************************************************************/
/*
Description: Find begin of list.
Arguments: Valid list pointer.
Return: Begining of list.
Time complexity: O(1)
Space complexity: O(1)
*/
iter_t SListBegin(const slist_t *list);

/***********************************************************************/
/*
Description: Make an action on nodes from to to with the param value
Arguments: Valid itertors from and to, valid value and a pointer to a function.
Return: 0 on pass and 1 of fail.
Time complexity: O(n)
Space complexity: O(1)
*/
int SListForEach(iter_t from, iter_t to, action_t action, void *param);

/***********************************************************************/
/*
Description: Set a value in the selected position.
Arguments: Valid position and void pointer.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void SListSet(iter_t position, void *value);

/***********************************************************************/
/*
Description: Get a value of the current location.
Arguments: Valid iterator.
Return: Pointer to a value.
Time complexity: O(1)
Space complexity: O(1)
*/
void *SListGet(iter_t position);

/***********************************************************************/
/*
Description: Go to the next node.
Arguments: Valid iterator.
Return: Next node.
Time complexity: O(1)
Space complexity: O(1)
*/
iter_t SListNext(iter_t position);

/***********************************************************************/
/*
Description: Check if the values of the two iterators match.
Arguments: Two valid iterators.
Return: 0 on positive result and -1 on negative.
Time complexity: O(1)
Space complexity: O(1)
*/
int SListIterIsEqual(iter_t iter1 , iter_t iter2);
/*
Description: Move the begining of src to the end of dest.
Arguments: Valid pointer to src and dest queues.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void ListAppend(slist_t *dest, slist_t *src);

#endif /*__SLIST__*/
