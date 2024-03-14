#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct List m_list;
typedef struct Node m_node;

struct List
{
    m_node *begin;
    m_node *end;
};

struct Node
{
    int value;
    m_node *next;
};

m_list *CreateList()
{
    m_list *list = (m_list *)malloc(sizeof(m_list));
    if(list == NULL)
    {
        return NULL;
    }

    list->begin = (m_node *)malloc(sizeof(m_node));
    if(list->begin == NULL)
    {
        free(list);
        return NULL;
    }

    list->end = (m_node *)malloc(sizeof(m_node));
    if(list->end == NULL)
    {
        free(list->begin);
        free(list);
        return NULL;
    }

    list->begin->next = list->end;
    list->end->next = NULL;
    return list;
}

void DeleteList(m_list *list)
{
    m_node *prev = NULL;
    m_node *curr = NULL;

    assert(list);

    curr = list->begin;
    while(curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    free(list);
    list = NULL;
}

void PrintList(m_list *list)
{
    m_node *iter = NULL;
    assert(list);
    iter = list->begin->next;
    while(iter != list->end)
    {
        printf("Value is %d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

void ListAddBegin(m_list *list, int m_value)
{
    m_node *iter = NULL;
    assert(list);

    iter = (m_node *)malloc(sizeof(m_node));
    if(NULL == iter)
    {
        return; 
    }

    iter->next = list->begin->next;
    iter->value = m_value;
    list->begin->next = iter;
}

void ListAddEnd(m_list *list, int m_value)
{
    m_node *iter = NULL;

    assert(list);

    iter = (m_node *)malloc(sizeof(m_node));
    if(NULL == iter)
    {
        return; 
    }

    list->end->value = m_value;
    list->end->next = iter;
    iter->next = NULL;
    list->end = iter;
}

void DeleteNodeWithValue(m_list *list, int m_value)
{
    
    m_node *iter = NULL;
    m_node *temp = NULL;

    assert(list);

    iter = list->begin->next;
    while(iter != list->end)
    {
        if(iter->value == m_value)
        {
            temp = iter->next;
            iter->value = iter->next->value;
            iter->next = iter->next->next;
            free(temp);
        }
        iter = iter->next;
    }
}

size_t ListSize(m_list *list)
{
    m_node *iter = NULL;
    size_t counter = 0;
    assert(list);
    iter = list->begin->next;
    while(iter != list->end)
    {
        ++counter;
        iter = iter->next;
    }
    return counter;
}


void ReverseList(m_list *list)
{
    m_node *iter = NULL;
    m_node *temp = NULL;
    size_t size = 0;
    size_t counter = 0;
    size_t val = 2;
    int value = 0;
    int go_to_end = 0;
    assert(list);

    size = ListSize(list);
    if(size == 0 || size == 1)
    {
        return;
    }

    while(counter != size - 1)
    {
        
        go_to_end = 0;
        iter = list->begin->next;
        while(go_to_end < size - val)
        {
           iter = iter->next; 
           ++go_to_end;
        }
        temp = iter->next;

        value = iter->next->value; 
        iter->next = iter->next->next;

        free(temp);
        ++val;
        ListAddEnd(list, value);

        ++counter;
    }
    iter = list->begin;
    temp = iter->next;
    value = iter->next->value;
    iter->next = iter->next->next;
    free(temp);
    ListAddEnd(list, value);

}

int main()
{
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    int val4 = 4;
    int val5 = 5;
    int val6 = 6;
    

    m_list *list = CreateList();
    ListAddEnd(list, val1);
    ListAddEnd(list, val2);
    ListAddEnd(list, val3);
    ListAddEnd(list, val4);
    ListAddEnd(list, val5);
    ListAddEnd(list, val6);
    PrintList(list);
    ReverseList(list);
    PrintList(list);
    DeleteList(list);

    return 0;
}