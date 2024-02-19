
#include <stdlib.h>

#define EXIT 0
#define CREATE_LIST 1
#define DESTROY_LIST 2
#define PUSH_A_NEW_NODE_TO_HEAD 3
#define PUSH_A_NEW_NODE_TO_TAIL 4
#define POP_A_NEW_NODE_FROM_HEAD 5
#define POP_A_NEW_NODE_FROM_TAIL 6
#define COUNT_AMOUNT_OF_NODES 7
#define CHECK_IF_LIST_IS_EMPTY 8
#define PRINT_LIST 9
#define NOT_INIT -1
#define EMPTY 1
#define NOT_EMPTY 2
#define ZERO_ITEMS 0
typedef struct Node Node;
typedef struct List List;


typedef enum
{
    
    ERR_OK,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
           
    ERR_STACK_BBBBB = 30
    


}ADTErr ;
/*
Description: Function creates the list structure.
Input: Void.
Output: The created list or NULL if failed.
Complexity: o(1).
*/
List* ListCreate(void);
/*
Description: Destroy the created list if its created.
Input: Pointer to the original list.
Output: Void.
Complexity: o(1).
*/
void ListDestroy(List* _list);
/*
Description: Pushes new block to the head of the list.
Input: Pointer to the original list and the data of the block
Output: ERR_OK if the block is added, ERR_NOT_INITIALIZED if list not created,ERR_ALLOCATION_FAILED if the block did not created.
Complexity: o(1).
*/
ADTErr ListPushHead(List* _list,int _data);
/*
Description: Pushes new block to the tail of the list.
Input: Pointer to the original list and the data of the block
Output: ERR_OK if the block is added, ERR_NOT_INITIALIZED if list not created,ERR_ALLOCATION_FAILED if the block did not created.
Complexity: o(1).
*/
ADTErr ListPushTail(List* _list,int _data);
/*
Description: Deletes block from the begining of the list.
Input: Pointer to the original list and pointer to the deleted data.
Output: ERR_OK if the block deleted, ERR_NOT_INITIALIZED if list not created.
Complexity: o(1).
*/
ADTErr ListPopHead(List* _list,int* _data);
/*
Description: Deletes block from the end of the list.
Input: Pointer to the original list and pointer to the deleted data.
Output: ERR_OK if the block deleted, ERR_NOT_INITIALIZED if list not created.
Complexity: o(1).
*/
ADTErr ListPopTail(List* _list,int* _data);
/*
Description: Countes the amount of added blocks on the list.
Input: Pointer to the original list.
Output: The amount of blocks found.
Complexity: o(n).
*/
size_t ListCountItems(List* _list);
/*
Description: Function checks if the list is empty.
Input: Pointer to the original list.
Output: 0 if list not initialized, 1 if itts empty and 2 if its not.
Complexity: o(1).
*/
int ListIsEmtpy(List* _list);
/*
Description: Function prints the list of blocks.
Input: Pointer to the original list.
Output: Void.
Complexity: o(n).
*/
void ListPrintf(List* _list);

