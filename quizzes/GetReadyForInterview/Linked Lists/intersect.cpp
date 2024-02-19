#include <iostream>
#include <list>

struct Node
{
    int data;
    Node *next;
};

bool Intersect(Node *head1, Node *head2)
{
    size_t counter1 = 0;
    size_t counter2 = 0;

    Node *iter1 = head1;
    Node *iter2 = head2;

    while(iter1->next != nullptr)
    {
        ++counter1;
        iter1 = iter1->next;
    }
    while(iter2->next != nullptr)
    {
        ++counter2;
        iter2 = iter2->next;
    }

    iter1 = head1;
    iter2 = head2;

    if(counter1 > counter2)
    {
        while(counter1 != counter2)
        {
            --counter1;
            iter1 = iter1->next;
        }
    }
    if(counter1 < counter2)
    {
        while(counter1 != counter2)
        {
            --counter2;
            iter2 = iter2->next;
        }
    }

    while(iter2 != nullptr || iter1 != nullptr)
    {
        if(iter1 == iter2)
        {
            return true;
        }
        ++iter1;
        ++iter2;
    }
    return false;
}

