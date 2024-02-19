
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *left;
    node_t *right;
};

static void AddRightToLeft(node_t *left, node_t *right);

node_t *BSTToList(node_t *root)
{
    node_t *left_side = NULL;
    node_t *right_side = NULL;
    node_t *left_side_end = NULL;

    if (NULL == root)
    {
        return (NULL);
    }
    /*Go to all nodes.*/
    left_side = BSTToList(root->left);
    right_side = BSTToList(root->right);
    /*add the right side to the root*/
    AddRightToLeft(root, right_side);
    /*if we do have a left side*/
    if (NULL != left_side)
    {
        /*we go to the node with the biggest value from the left*/
        left_side_end = left_side;

        while(NULL != left_side_end->right)
        {
            left_side_end = left_side_end->right;
        }
        /*we add the root and the right side to this biggest node in value from the left side.*/
        AddRightToLeft(left_side_end, root);
        /*The left side will become the new root*/
        return (left_side);
    }
    /*if we did not have a left side in this instance we only added the right side to the root.
    Because of this we will return the root.*/
    return (root);
}

static void AddRightToLeft(node_t *left_side, node_t *right_side)
{
    left_side->right = right_side;

    if (NULL != right_side)
    {
        right_side->left = left_side;
    }
}

node_t *NewNode(void *value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(NULL == newnode)
    {
        return NULL;
    }

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


int main()
{
    int value1 = 4;
    int value2 = 2;
    int value3 = 6;
    int value4 = 1;
    int value5 = 3;
    int value6 = 5;
    int value7 = 7;
    node_t *temp = NULL;
	node_t *root = NULL;
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    node_t *node3 = NULL;
    node_t *node4 = NULL;
    node_t *node5 = NULL;
    node_t *node6 = NULL;
    root = NewNode(&value1);
    node1 = NewNode(&value2);
    node2 = NewNode(&value3);
    node3 = NewNode(&value4);
    node4 = NewNode(&value5);
    node5 = NewNode(&value6);
    node6 = NewNode(&value7);
    root->left = node1; /*2*/
    root->right = node2; /*6*/
    node1->left = node3; /*1*/
    node1->right = node4; /*3*/
    node2->left = node5; /*5*/
    node2->right = node6; /*7*/
    temp = BSTToList(root);
    while(NULL != temp)
    {
        printf("%d\n", *(int *)temp->data);
        temp = temp->right;
    }
	return 0;
}