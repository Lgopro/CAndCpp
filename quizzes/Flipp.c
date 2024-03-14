
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node node_t;

struct Node
{
    int value;
    node_t *next;
};

node_t *Flip(node_t *head)
{
    node_t *current = NULL;
    node_t *prev = NULL;
    node_t *future = NULL;

    assert(head);
    prev = head;
    current = head;
    future = head->next;

    while(future != NULL)
    {
        current = future;
        future = future->next;
        current->next = prev;
        prev = current;
    }

    head->next = NULL;
    return current;
}


int main()
{
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *result = NULL;

    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;
    node5->value = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    result = Flip(node1);

    while(result != NULL)
    {
        printf("%d ", result->value);
        result = result->next;
    }

    return 0;
}