#include <stdio.h>
#include <stdlib.h>


typedef struct Node node;

struct Node
{
    node *m_next;
    int m_value;
};

node *Flip(node *head);

int main()
{
    node *node1 = (node *)malloc(sizeof(node));
    node *node2 = (node *)malloc(sizeof(node));
    node *node3 = (node *)malloc(sizeof(node));
    node *node4 = (node *)malloc(sizeof(node));
    node *node5 = (node *)malloc(sizeof(node));
    node *node6 = (node *)malloc(sizeof(node));

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = NULL;

    node1->m_value = 1;
    node2->m_value = 2;
    node3->m_value = 3;
    node4->m_value = 4;
    node5->m_value = 5;
    node6->m_value = 6;

    node *result = Flip(node1);

    while(result != NULL)
    {
        printf("the num is: %d\n", result->m_value);
        result = result->m_next;
    }



    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    
    return 0;
}


node *Flip(node *head)
{
    static size_t counter = 0;
    static node *new_head = NULL;

    if(head->m_next == NULL)
    {
        new_head = head;
        return head;
    }

    ++counter;
    node *result = Flip(head->m_next);
    head->m_next = result->m_next;
    result->m_next = head;

    --counter;

    if(counter == 0)
    {
        return new_head;
    }
    else
    {
        return head;
    }
}