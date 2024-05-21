#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node node_t;

struct Node
{
    node_t *m_next;
    int m_value;
};

node_t *ReverseList(node_t *head)
{
    node_t *prev = NULL;
    node_t *current =  NULL;
    node_t *next = NULL;

    assert(head);

    prev = head;
    current = head->m_next;
    next = head->m_next;

    while(NULL != next)
    {
        next = next->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    
    head->m_next = NULL;
    return prev;
}

node_t *ReverseListRec(node_t *head)
{
    static int counter = 0;
    node_t *result = NULL;
    static node_t *final_back;
    
    if(head->m_next == NULL)
    {
        final_back = head;
        return head;
    }
    ++counter;
    result = ReverseListRec(head->m_next);

    --counter;

    if(counter == 0)
    {
        head->m_next->m_next = head;
        head->m_next->m_next->m_next = NULL;
        return final_back;
    }

    head->m_next->m_next = head;
    return head;
}

int main()
{
    size_t counter = 0;
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *node6 = (node_t *)malloc(sizeof(node_t));
    node_t *node7 = (node_t *)malloc(sizeof(node_t));
    node_t *node8 = (node_t *)malloc(sizeof(node_t));
    node_t *node9 = (node_t *)malloc(sizeof(node_t));

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = node7;
    node7->m_next = node8;
    node8->m_next = node9;
    node9->m_next = NULL;

    node1->m_value = 1;
    node2->m_value = 2;
    node3->m_value = 3;
    node4->m_value = 4;
    node5->m_value = 5;
    node6->m_value = 6;
    node7->m_value = 7;
    node8->m_value = 8;
    node9->m_value = 9;

    printf("Before reverse:\n");
    node_t *begin = node1;

    while(begin != NULL)
    {
        printf(" %d ", begin->m_value);
        begin = begin->m_next;
    }
    printf("\n");
    printf("Iterative:\n");
    node_t *result = ReverseList(node1);

    
    while(result != NULL)
    {
        printf(" %d ", result->m_value);
        result = result->m_next;
    }
    printf("\n");
        
    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = node7;
    node7->m_next = node8;
    node8->m_next = node9;
    node9->m_next = NULL;

    node1->m_value = 1;
    node2->m_value = 2;
    node3->m_value = 3;
    node4->m_value = 4;
    node5->m_value = 5;
    node6->m_value = 6;
    node7->m_value = 7;
    node8->m_value = 8;
    node9->m_value = 9;

    printf("Recursive:\n");
    node_t *result1 = ReverseListRec(node1);
    while(result1 != NULL)
    {
        printf(" %d ", result1->m_value);
        result1 = result1->m_next;
    }

    printf("\n");
    
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