

#include "stdio.h"
#include <stdlib.h>


typedef struct Node node_t;

struct Node
{
    node_t *next;
    int value;
};


int NthElement(node_t *head, size_t *counter)
{
    int result;
    if(NULL == head->next)
    {
        --*counter;
        return head->value;
    }

    result = NthElement(head->next, counter);
    if(*counter == 0)
    {
        return result;
    }
    --*counter;
    return head->value;
}

int main()
{
    size_t counter = 5;
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *node6 = (node_t *)malloc(sizeof(node_t));
    node_t *node7 = (node_t *)malloc(sizeof(node_t));
    node_t *node8 = (node_t *)malloc(sizeof(node_t));
    node_t *node9 = (node_t *)malloc(sizeof(node_t));

    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;
    node5->value = 5;
    node6->value = 6;
    node7->value = 7;
    node8->value = 8;
    node9->value = 9;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = NULL;

    int result = NthElement(node1, &counter);
    printf("The result is: %d\n", result);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);
    free(node9);
    

    return 0;
}