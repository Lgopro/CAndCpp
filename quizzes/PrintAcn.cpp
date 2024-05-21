

#include <iostream>
#include <cassert>


typedef struct Node node_t;

struct Node
{
    node_t *m_left;
    node_t *m_right;
    int m_data;
};

bool PrintParents(node_t *head, int key)
{

    if(head == NULL)
    {
        return false;
    }

    if(key == head->m_data)
    {
        return true;
    }

    bool result1 = PrintParents(head->m_left, key);
    bool result2 = PrintParents(head->m_right, key);

    if(result1 == true || result2 == true)
    {
        std::cout << head->m_data << " ";
    }

    return result1 || result2;
}


int main()
{

    node_t *arr = new node_t[6];
    arr[0].m_data = 1;
    arr[1].m_data = 2;
    arr[2].m_data = 3;
    arr[3].m_data = 4;
    arr[4].m_data = 5;
    arr[5].m_data = 7;
    
    arr[0].m_left = &arr[1];
    arr[0].m_right = &arr[2];
    arr[1].m_left = &arr[3];
    arr[1].m_right = &arr[4];
    arr[3].m_left = &arr[5];
    arr[3].m_right = nullptr;

    arr[2].m_left = nullptr;
    arr[2].m_right = nullptr;
    arr[4].m_left = nullptr;
    arr[4].m_right = nullptr;

    bool result = PrintParents(&arr[0], 7);
    if(result == false)
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
        std::cout << "" << std::endl;
    }

    delete [] arr;
    
    return 0;
}