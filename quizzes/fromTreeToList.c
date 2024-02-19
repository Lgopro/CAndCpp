#include <stdio.h> /*printf*/
#include <stdlib.h> /*calloc*/
#include <assert.h>
#include <string.h>

typedef struct BSTNode node_t;

struct BSTNode
{
    node_t *left;
    node_t *right;
    void *value;

};
node_t* BTSToSortedList(node_t* node);
node_t *NewNode(void *value);

int main()
{
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    int value4 = 5;
    int value5 = 8;
    int value6 = 9;
    node_t *result = NULL;
	node_t *root = NULL;
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    node_t *node3 = NULL;
    node_t *node4 = NULL;
    node_t *node5 = NULL;
    root = NewNode(&value1);
    node1 = NewNode(&value2);
    node2 = NewNode(&value3);
    node3 = NewNode(&value4);
    node4 = NewNode(&value5);
    node5 = NewNode(&value6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = NULL;
    result = BTSToSortedList(root);
    while(NULL != root->right)
    {
        printf("The result is %d\n", *(int *)root->value);
        root = root->right;
    }

	return 0;
}

node_t *NewNode(void *value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(NULL == newnode)
    {
        return NULL;
    }

    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}




node_t* BTSToSortedList(node_t* node)
{
    node_t* temp = NULL;
    node_t* temp_right = NULL;
    if (node == NULL || (node->left == NULL && node->right == NULL))
    {
        return (node);
    }
    
    if (node->left != NULL) 
    {
       
        BTSToSortedList(node->left);
        temp = node->right;
        node->right = node->left;
        node->left = NULL;
        temp_right = node->right;
        while (NULL != temp_right->right)
        {
            temp_right = temp_right->right;
        }
        temp_right->right = temp;
    }
 
    BTSToSortedList(node->right);
    return (node);
}