
#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>
#include <string.h>


#include "queue.h"

typedef struct BSTNode node_tree_t;
#define UNTIL_END (1)
struct BSTNode
{
    node_tree_t *left;
    node_tree_t *right;
    void *value;

};

node_tree_t *NewNode(void *value);

void PrintTreeByLevel(queue_t *queue, node_tree_t *root);

int main()
{
    int value1 = 3;
    int value2 = 2;
    int value3 = 1;
    int value4 = 6;
    int value5 = 4;
    int value6 = 7;
    queue_t *queue = NULL;
	node_tree_t *root = NULL;
    node_tree_t *node1 = NULL;
    node_tree_t *node2 = NULL;
    node_tree_t *node3 = NULL;
    node_tree_t *node4 = NULL;
    node_tree_t *node5 = NULL;
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
    queue = QCreate();
    PrintTreeByLevel(queue, root);

	return 0;
}

node_tree_t *NewNode(void *value)
{
    node_tree_t *newnode = (node_tree_t *)malloc(sizeof(node_tree_t));
    if(NULL == newnode)
    {
        return NULL;
    }

    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void PrintTreeByLevel(queue_t *queue, node_tree_t *root)
{
    node_tree_t *to_print = NULL;
    assert(root);
    assert(queue);

    QEnqueue(queue, root);
    to_print = root;

    while(UNTIL_END)
    {
        QDequeue(queue);
        
        if (NULL != to_print->left)
        {
            QEnqueue(queue, to_print->left);
        }

        if (NULL != to_print->right)
        {
            QEnqueue(queue, to_print->right);
        }
        if(0 == QSize(queue))
        {
            break;
        }
        to_print = (node_tree_t *)QPeek(queue);
        printf("%d\n", *(int *)to_print->value);   
    }
}