#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>
#include <string.h>

typedef struct BSTNode node_t;

struct BSTNode
{
    node_t *left;
    node_t *right;
    void *value;

};

node_t *NewNode(void *value);
void MakeAMirror(node_t *root);
void PrintTree(node_t *root);

int main()
{
    int value1 = 3;
    int value2 = 2;
    int value3 = 1;
    int value4 = 6;
    int value5 = 4;
    int value6 = 7;

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
    PrintTree(root);
    MakeAMirror(root);
    printf("\n");
    PrintTree(root);
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

void MakeAMirror(node_t *root)
{
    node_t *temp = NULL;
    if (NULL == root)
    {
        return;
    }
    else 
    {
        
        MakeAMirror(root->left);
        MakeAMirror(root->right);
       
 
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void PrintTree(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", *(int *)root->value);
    }
    if(NULL != root->left)
    {
        PrintTree(root->left);
    }
    if(NULL != root->right)
    {
        PrintTree(root->right);
    }

    return ;

}