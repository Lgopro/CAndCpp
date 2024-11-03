#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct node
{
    int m_data;
    struct node *m_next;
}Node;

typedef struct dl_node
{
    DL_node *m_prev;
    DL_node *m_next;
    int value;
}DL_node;

int FindMissingNumber(int *array, size_t size)
{
    int LUT[1024] = {0};
    assert(array);

    for(size_t i = 0; i < size; ++i)
    {
        ++LUT[array[i]];
    }

    for(size_t j = 0; j < size; ++j)
    {
        if(LUT[j] == 0)
        {
            return j;
        }
    }

    return ERROR;
}


void InsertBefore(DL_node *head, DL_node *current)
{
    DL_node *prev = current->m_prev;
    head->m_prev = current->m_prev;
    head->m_next = prev->m_next;
    prev->m_next = head;
    current->m_prev = head;
}

void Delete(DL_node *head)
{
    assert(head);
    DL_node *to_delete = head;
    head->m_prev = head->m_next->m_prev->m_prev;
    head->m_next = head->m_prev->m_next->m_next;
    free(to_delete);
}


Node *Flip(Node *head)
{
    assert(head);
    Node *prev = head;
    Node *current = head->m_next;
    Node *next = head->m_next;

    while(next != NULL)
    {
        next = next->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    head->m_next = NULL;
    return prev;

}


void Check1()
{
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));
    Node *node4 = (Node *)malloc(sizeof(Node));
    Node *node5 = (Node *)malloc(sizeof(Node));
    Node *node6 = (Node *)malloc(sizeof(Node));
    Node *node7 = (Node *)malloc(sizeof(Node));

    node1->m_data = 1;
    node2->m_data = 2;
    node3->m_data = 3;
    node4->m_data = 4;
    node5->m_data = 5;
    node6->m_data = 6;
    node7->m_data = 7;
    

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = node7;
    node7->m_next = NULL;

    Node *result = Flip(node1);

    while(result != NULL)
    {
        printf("%d ", result->m_data);
        result = result->m_next;
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
}


void Check2()
{
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));
    Node *node4 = (Node *)malloc(sizeof(Node));
    Node *node5 = (Node *)malloc(sizeof(Node));
    Node *node6 = (Node *)malloc(sizeof(Node));
    Node *node7 = (Node *)malloc(sizeof(Node));

    node1->m_data = 1;
    node2->m_data = 2;
    node3->m_data = 3;
    node4->m_data = 4;
    node5->m_data = 5;
    node6->m_data = 6;
    node7->m_data = 7;
    

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = node7;
    node7->m_next = node3;

    int result = IsItLoop(node1);

    if(result == FALSE)
    {
        printf("Its false\n");
    }
    else
    {
        printf("Its true\n");
    }

    OpenLoop(node1);
    int result1 = IsItLoop(node1);
    if(result1 == FALSE)
    {
        printf("Its false\n");
    }
    else
    {
        printf("Its true\n");
    }
    RemoveAfter(node4);

    Node *result_delete = node1;
    while(result_delete != NULL)
    {
        printf("%d ", result_delete->m_data);
        result_delete = result_delete->m_next;
    }

    
    
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
}

int IsItLoop(Node * head)
{
    assert(head);
    Node *slow = head;
    Node *fast = head->m_next;
    int flag = FALSE;


    while(fast != NULL && fast->m_next != NULL)
    {
        
        if((slow == fast || slow->m_next == fast || fast->m_next == slow) && flag == TRUE)
        {
            return TRUE;
        }
        flag = TRUE;
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    return FALSE;
}

void OpenLoop(Node *head)
{
    assert(head);
    int result = IsItLoop(head);
    if(result == FALSE)
    {
        return;
    }
    size_t counter = 0;
    Node *fast = head->m_next;
    Node *slow = head;
    int flag = FALSE;

    while(fast != slow && fast->m_next != slow)
    {
        
        if((slow == fast || slow->m_next == fast || fast->m_next == slow) && flag == TRUE)
        {
            break;
        }
        flag = TRUE;
        slow = slow->m_next;
        fast = fast->m_next->m_next;
        ++counter;
    }

    int unlock_counter = 0;
    int found = FALSE;

    fast = head->m_next;
    slow = head;

    while(TRUE)
    {
        unlock_counter = 0;
        while(unlock_counter != counter * 2)
        {
            fast = fast->m_next;
            ++unlock_counter;
            if(fast->m_next == slow)
            {
                found = TRUE;
                break;
            }
        }

        if(found == TRUE)
        {
            fast->m_next = NULL;
            return;
        }
        slow = slow->m_next;
            
    }
}


void RemoveAfter(Node *prev)
{
    assert(prev);
    Node *to_delete = prev->m_next;
    prev->m_next = prev->m_next->m_next;
    

}

int main()
{
    //Check1();
    //Check2();

    
    return 0;
}