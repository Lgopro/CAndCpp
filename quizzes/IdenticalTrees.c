#include <stdio.h>

#define TRUE 1
#define FALSE 0


typedef struct node_t Node;

struct Node
{
    node_t *left;
    node_t *right;
    int value;
};

int IdenticalTrees(node_t *head_tree1, node_t *head_tree2)
{


    if(head_tree1 == NULL && head_tree2 == NULL)
    {
        return TRUE;
    }
    if((head_tree1 == NULL && head_tree2 != NULL) || (head_tree1 != NULL && head_tree2 == NULL))
    {
        return FALSE;
    }

    int status1 = IdenticalTrees(head_tree1->left, head_tree2->left);
    int status2 = IdenticalTrees(head_tree1->right, head_tree2->right);

    if(status1 == FALSE || status2 == FALSE)
    {
        return FALSE;
    }
    return TRUE;
}

int main()
{
    
    return 0;
}