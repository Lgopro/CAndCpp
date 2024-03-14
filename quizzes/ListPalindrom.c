
#include <stdio.h> /* printf */
#include <assert.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct ListNode node;

struct ListNode 
{
    int val;
    node* next;
};


int isPalindrome(node* head)
{
    size_t counter = 0;
    node *iter = NULL;
    int *arr = NULL;
    size_t begin = 0;

    assert(head);

    iter = head;
    while(iter != NULL)
    {
        ++counter;
        iter = iter->next;
    }

    arr = (int *)malloc(sizeof(int) * counter);
    iter = head;
    counter = 0;

    while(iter != NULL)
    {
        arr[counter] = iter->val;
        ++counter;
        iter = iter->next;
    }

    --counter;
    while(begin < counter)
    {
        if(arr[begin] != arr[counter])
        {
            free(arr);
            return FALSE;
        }
        ++begin;
        --counter;
    }
    return TRUE;
}

int main()
{
    int result = FALSE;
    node *node1 = (node *)malloc(sizeof(node));
    node *node2 = (node *)malloc(sizeof(node));
    node *node3 = (node *)malloc(sizeof(node));
    node *node4 = (node *)malloc(sizeof(node));
    node *node5 = (node *)malloc(sizeof(node));
    node *node6 = (node *)malloc(sizeof(node));
    node *node7 = (node *)malloc(sizeof(node));

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 3;
    node6->val = 2;
    node7->val = 1;

    result = isPalindrome(node1);
    printf("Result should be palindrom\n");
    if(result == TRUE)
    {
        printf("It is a palindrom\n");
    }
    else
    {
        printf("Not a palindrom\n");
    }

    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 4;
    node6->val = 2;
    node7->val = 1;

    result = isPalindrome(node1);
    printf("Result should be not palindrom\n");
    if(result == TRUE)
    {
        printf("It is a palindrom\n");
    }
    else
    {
        printf("Not a palindrom\n");
    }


    return 0;
}