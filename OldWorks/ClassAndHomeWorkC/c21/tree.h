#ifndef _TREE_
#define _TREE_



typedef struct Tree Tree;

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
typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
} TreeTraverse;
/*
Description: Function creates the tree structure.
Input: Void.
Output: The created tree or NULL if failed.
Complexity: O(1).
*/
Tree* TreeCreate();
/*
Description: Function destroyes all the nodes in the tree.
Input: The structure of the tree pointer.
Output: Void.
Complexity: O(n).
*/
void TreeDestroy(struct Tree* _tree);
/*
Description: Function creates and inserts a new node structure in the tree.
Input: Tree structure pointer and the data.
Output: ADTErr.TODO
Complexity: o(log(n)).
*/
ADTErr TreeInsert(Tree* _tree, int _data);
/*
Description: Function foundes the data in the nodes of the tree.
Input: The tree structure pointer and the data.
Output: NOT_GENERATED if the tree structure dident created, EQUALITY_FOUND if the data found in the structure and EQUALITY_NOT_FOUND if not.
Complexity: o(log(n)).
*/
int TreeIsDataFound(Tree* _tree, int _data);
/*
Description: Function prints the tree nodes in three different ways.
Input: Tree structure pointer and the type of printing.
Output: Void.
Complexity: o(n).
*/
void TreePrint(Tree* _tree, TreeTraverse _traverseMode);
#endif
