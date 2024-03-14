#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TRUE 1
#define FALSE 0

typedef struct Node node_t;

struct Node
{
    int value;
    node_t *next;
};

int IsLoop(node_t *head)
{
    node_t *slow = NULL;
    node_t *fast = NULL;

    assert(head);
    fast = head->next;
    slow = head;

    while(fast != slow && fast->next != slow)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == NULL || fast->next == NULL)
        {
            return FALSE;
        }

        printf("%u\n", fast);
        printf("%u\n", slow);
        sleep(1);
    }

    return TRUE;
}

void BreakLoop(node_t *head)
{
    size_t slow_counter = 0;
    size_t amount_of_nodes_in_circle = 0;
    size_t counter = 0;

    node_t *slow = NULL;
    node_t *fast = NULL;

    assert(head);

    int result = IsLoop(head);
    if(result == FALSE)
    {
        return;
    }
    
    slow = head;
    fast = head->next;

    while(fast != slow && fast->next != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
        ++slow_counter;

        if(fast == NULL || fast->next == NULL)
        {
            return FALSE;
        }

        printf("%u\n", fast);
        printf("%u\n", slow);
        sleep(1);
    }

    amount_of_nodes_in_circle = slow_counter * 2;

    slow = head;
    
    while(slow_counter != 0)
    {
        counter = 0;
        fast = slow->next;
        while(counter < amount_of_nodes_in_circle)
        {
            if(fast->next == slow)
            {
                fast->next = NULL;
                return;
            }
            ++counter;
            fast = fast->next;
        }
        slow = slow->next;
        --slow_counter;
    }
}

int main()
{
    int result = FALSE;
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *node6 = (node_t *)malloc(sizeof(node_t));
    node_t *node7 = (node_t *)malloc(sizeof(node_t));
    

    node1->value = 1;
    node2->value = 2;
    node3->value = 3;
    node4->value = 4;
    node5->value = 5;
    node6->value = 6;
    node7->value = 7;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node3;

    result = IsLoop(node1);
    if(result == TRUE)
    {
        printf("Is loop\n");
    }
    else
    {
        printf("Is not loop\n");
    }
    BreakLoop(node1);
    if(node7->next == NULL)
    {
        printf("Broke loop\n");
    }
    else
    {
        printf("Not Broke loop\n");
    }

    return 0;
}



