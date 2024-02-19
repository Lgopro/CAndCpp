#include <iostream>

typedef struct Node node_t;

struct Node
{
    node_t *left;
    node_t *right;
    int data;
};

bool PrintPath(node_t *head, int number)
{
    if(nullptr == head)
    {
        return false;
    }
    if(head->data == number)
    {
        return true;
    }

    bool result1 = PrintPath(head->left, number);
    bool result2 = PrintPath(head->right, number);

    if(result1 | result2)
    {
        std::cout << head->data << " ";
    }

    return (result1 | result2);
}


int main()
{
    node_t *node1 = new node_t[1];
    node_t *node2 = new node_t[1];
    node_t *node3 = new node_t[1];
    node_t *node4 = new node_t[1];
    node_t *node5 = new node_t[1];
    node_t *node6 = new node_t[1];
    node_t *node7 = new node_t[1];
    

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 7;
    
    node1->left = node2;
    node1->right = node3;
    node3->left = nullptr;
    node3->right = nullptr;
    node2->left = node4;
    node2->right = node5;
    node5->left = nullptr;
    node5->right = nullptr;
    node4->left = node6;
    node4->right = nullptr;



    bool result = PrintPath(node1, 7);
    if(result == true)
    {
        printf("\n The result found ");
        
    }

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    

    return 0;
}