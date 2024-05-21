
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <iostream>

typedef struct Node node_t;

struct Node
{
    node_t *m_next;
    int m_data;
};

node_t *Flip(node_t *head)
{
    static int counter = 0;

    assert(head);

    if(head->m_next == NULL)
    {
        return head;
    }

    node_t *result = Flip(head->m_next);
    
    head->m_next->m_next = head;
    head->m_next->m_next->m_next = NULL;

    return result;
}

int Max(int var1, int var2)
{
    return (var1 > var2) ? var1 : var2;
}

int MaxSum(int *arr, int sum, size_t current, size_t size)
{
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    if(current == size)
    {
        return sum;
    }

    if(sum + arr[current] > sum)
    {
        result2 = MaxSum(arr, sum + arr[current], current + 1, size);
        result2 = Max(result2, sum + arr[current]);
    }

    if(sum < 0)
    {
        result3 = MaxSum(arr, 0, current, size);
        result4 = MaxSum(arr, 0, current + 1, size);
    }

    result1 = MaxSum(arr, sum + arr[current], current + 1, size);

    return Max(Max(result3, result4), Max(result1, result2));
}


void Exer1()
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

void Exer2()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = MaxSum(arr, 0, 0, sizeof(arr)/sizeof(int));
    printf("The max sum is %d\n", result);
}

void SortStack(std::stack<int>& m_stack)
{
    std::stack<int> help_stack;
    int temp_stack = 0;
    int temp_help = 0;

    while(m_stack.size() != 0)
    {
        std::cout<< "main loop" << std::endl;
        std::cout<< "size of m_stack is " << m_stack.size() << std::endl;
        std::cout<< "size of help_stack is " << help_stack.size() << std::endl;

        if(help_stack.size() == 0)
        {
            help_stack.push(m_stack.top());
            m_stack.pop();
        }

        if(help_stack.top() > m_stack.top())
        {
            while(help_stack.top() > m_stack.top())
            {
                std::cout<< "sec loop" << std::endl;
                if(help_stack.size() == 0)
                {
                    help_stack.push(m_stack.top());
                    m_stack.pop();
                    break;
                }
                
                m_stack.push(help_stack.top());
                help_stack.pop();
            }
        }
        else
        {
            help_stack.push(m_stack.top());
            m_stack.pop();
        }
    }
    m_stack = help_stack;
}

void Exer3()
{
    std::stack<int> stack;
    stack.push(1);
    stack.push(5);
    stack.push(2);
    stack.push(88);
    stack.push(3);
    stack.push(-2);

    SortStack(stack);
    while(stack.size() != 0)
    {
        std::cout<< stack.top() << " ";
        stack.pop();
    }
}

void Swap(char *var1, char *var2)
{
    char temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void ReverseString(char *arr, int begin, int end)
{
    if(begin == end || end < begin)
    {
        return;
    }

    Swap(&arr[begin], &arr[end]);
    ReverseString(arr, begin + 1, end - 1);
}


void StackInsert(std::stack<int>& stack, int value)
{
    int top_var = 0;

    if(stack.size() == 0)
    {
        stack.push(value);
        return;
    }
    else
    {
        top_var = stack.top();
    }
    
    if(value < top_var && stack.size() > 0)
    {
        stack.pop();
        StackInsert(stack, value);
        stack.push(top_var);
    }
    else
    {
        stack.push(value);
    }
    
    
}

void Exer10()
{
    std::stack<int> m_stack;

    StackInsert(m_stack, 12);
    StackInsert(m_stack, -2);
    StackInsert(m_stack, 5);
    StackInsert(m_stack, -8);
    StackInsert(m_stack, 3);
    StackInsert(m_stack, -3);
    StackInsert(m_stack, 4);
    StackInsert(m_stack, -4);
    StackInsert(m_stack, -5);

    while(m_stack.size() != 0)
    {
        std::cout << m_stack.top() << " ";
        m_stack.pop();
    }

    std::cout << " " << std::endl;
}

int main()
{
    /* Exer1();
    Exer2(); 
    Exer3();*/

    Exer10();
    return 0;
}