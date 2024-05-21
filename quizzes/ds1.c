
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FAIL 1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

typedef struct Node node_t;
typedef struct TreeNode tree_node_t;


struct Node
{
    node_t *m_next;
    int m_data;
};


struct TreeNode
{
    tree_node_t *m_next;
    tree_node_t *m_prev;
    int m_data;
};

node_t *Flip(node_t *head)
{
    assert(head);

    node_t *prev = head;
    node_t *curr = head->m_next;
    node_t *next = head->m_next;

    while(next != NULL)
    {
        next = next->m_next;
        curr->m_next = prev;
        prev = curr;
        curr = next;
    }
    
    head->m_next = NULL;
    return prev;
}

void Exer2()
{
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *node6 = (node_t *)malloc(sizeof(node_t));

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = NULL;

    node1->m_data = 1; 
    node2->m_data = 2; 
    node3->m_data = 3; 
    node4->m_data = 4; 
    node5->m_data = 5; 
    node6->m_data = 6; 

    node_t *result = Flip(node1);

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
}


int IsLoop(node_t *head)
{
    assert(head);

    node_t *slow = head;
    node_t *fast = head->m_next;

    while(TRUE)
    {
        if(fast == NULL || fast->m_next == NULL)
        {
            break;
        }
        if(slow == fast || slow == fast->m_next)
        {
            return SUCCESS;
        }
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    return FAIL;
}

void OpenLoop(node_t *head)
{
    assert(head);

    node_t *slow = head;
    node_t *fast = head->m_next;
    size_t counter = 0;

    while(TRUE)
    {
        if(slow == fast || slow == fast->m_next)
        {
            break;
        }
        slow = slow->m_next;
        fast = fast->m_next->m_next;
        counter += 2;
    }

    size_t counter1 = 0;

    slow = head;
    fast = slow->m_next;

    while(TRUE)
    {
        if(slow == fast->m_next)
        {
            fast->m_next = NULL;
            break;
        }

        if(counter1 == counter)
        {
            counter1 = 0;
            slow = slow->m_next;
            fast = slow->m_next;
        }
        fast = fast->m_next;
        ++counter1;
    }

}

void Exer4()
{
    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node_t *node3 = (node_t *)malloc(sizeof(node_t));
    node_t *node4 = (node_t *)malloc(sizeof(node_t));
    node_t *node5 = (node_t *)malloc(sizeof(node_t));
    node_t *node6 = (node_t *)malloc(sizeof(node_t));

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = NULL;

    node1->m_data = 1; 
    node2->m_data = 2; 
    node3->m_data = 3; 
    node4->m_data = 4; 
    node5->m_data = 5; 
    node6->m_data = 6; 

    int result = IsLoop(node1);

    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    node6->m_next = node2;

    int result1 = IsLoop(node1);

    if(result == FAIL && result1 == SUCCESS)
    {
        printf("\nsuccess for Is Loop\n");
    }

    OpenLoop(node1);

    while(node1 != NULL)
    {
        printf("%d ", node1->m_data);
        node1 = node1->m_next;
    }

    printf("\nsuccess for Open Loop\n");
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
}

int IsIntersect(node_t *head1, node_t *head2)
{
    size_t counter1 = 0;
    size_t counter2 = 0;
    node_t *iter1 = NULL;
    node_t *iter2 = NULL;

    assert(head1);
    assert(head2);

    iter1 = head1;
    iter2 = head2;


    while(iter1 != NULL)
    {
        ++counter1;
        iter1 = iter1->m_next;
    }
     
    while(iter2 != NULL)
    {
        ++counter2;
        iter2 = iter2->m_next;
    }

    iter1 = head1;
    iter2 = head2;

    if(counter1 > counter2)
    {
        iter1 = iter1->m_next;
    }

    if(counter1 < counter2)
    {
        iter2 = iter2->m_next;
    }

    while(iter1 != NULL)
    {
        if(iter2 == iter1)
        {
            return TRUE;
        }
        iter1 = iter1->m_next;
        iter2 = iter2->m_next;
    }
    return FALSE;

}

void ClearIntersection(node_t *head1, node_t *head2)
{
    size_t counter1 = 0;
    size_t counter2 = 0;
    node_t *iter1 = NULL;
    node_t *iter2 = NULL;

    assert(head1);
    assert(head2);

    int result = IsIntersect(head1, head2);
    if(result == FALSE)
    {
        return;
    }

    iter1 = head1;
    iter2 = head2;

    while(iter1 != NULL)
    {
        ++counter1;
        iter1 = iter1->m_next;
    }
     
    while(iter2 != NULL)
    {
        ++counter2;
        iter2 = iter2->m_next;
    }

    iter1 = head1;
    iter2 = head2;

    if(counter1 > counter2)
    {
        iter1 = iter1->m_next;
    }

    if(counter1 < counter2)
    {
        iter2 = iter2->m_next;
    }

    while(TRUE)
    {
        if(iter2->m_next == iter1->m_next)
        {
            iter2->m_next = NULL;
            return;
        }
        iter1 = iter1->m_next;
        iter2 = iter2->m_next;
    }
}


void Exer5()
{

}

void Remove(tree_node_t *current)
{
    assert(current);

    tree_node_t *temp = NULL;

    temp = current;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    free(temp);
}

void Add(tree_node_t *before, int data)
{
    assert(before);

    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    if(new_node == NULL)
    {
        return;
    }
    
    new_node->m_data = data;
    new_node->m_next = before->m_next;
    new_node->m_prev = before;
    before->m_next = new_node;
    new_node->m_next->m_prev = new_node;

}

void Exer7()
{
    tree_node_t *node1 = (tree_node_t *)malloc(sizeof(tree_node_t));
    tree_node_t *node2 = (tree_node_t *)malloc(sizeof(tree_node_t));
    tree_node_t *node3 = (tree_node_t *)malloc(sizeof(tree_node_t));
    tree_node_t *node4 = (tree_node_t *)malloc(sizeof(tree_node_t));
    tree_node_t *node5 = (tree_node_t *)malloc(sizeof(tree_node_t));
    tree_node_t *node6 = (tree_node_t *)malloc(sizeof(tree_node_t));

    node1->m_data = 1;
    node2->m_data = 2;
    node3->m_data = 3;
    node4->m_data = 4;
    node5->m_data = 5;
    node6->m_data = 6;

    node1->m_prev = NULL;
    node1->m_next = node2;

    node2->m_prev = node1;
    node2->m_next = node3;

    node3->m_prev = node2;
    node3->m_next = node4;

    node4->m_prev = node3;
    node4->m_next = node5;

    node5->m_prev = node4;
    node5->m_next = node6;

    node6->m_prev = node5;
    node6->m_next = NULL;

    Remove(node3);
    Add(node4, 111);

    printf("Exer 7\n");

    tree_node_t *iter = node1;

    while(iter != NULL)
    {
        printf("%d ", iter->m_data);
        iter = iter->m_next;
    }

    iter = node1;
    tree_node_t *next = node1;

    while(iter != NULL)
    {
        next = next->m_next;
        free(iter);
        iter = next;
    }
    printf("\n");
}

int main()
{
    Exer2();
    Exer4();
    Exer5();
    Exer7();

    return 0;
}