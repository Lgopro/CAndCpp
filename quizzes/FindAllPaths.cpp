#include <iostream>
#include <cassert>



struct node_t
{
    size_t m_amount;
    node_t *m_array;
    int m_value;
};

bool PrintAllPaths(node_t *head, size_t max_amount_of_steps, size_t steps_made, int value_to_find)
{
    bool status = false;

    assert(head);

    if(max_amount_of_steps == 0)
    {
        return false;
    }

    if(head->m_value == value_to_find)
    {
        std::cout<< "The result is: " << head->m_value;
        return true;
    }

    for(size_t i = 0; i < head->m_amount; ++i)
    {
        status = PrintAllPaths(&head->m_array[i], max_amount_of_steps - 1, steps_made + 1 ,value_to_find);
        if(status == true)
        {
            std::cout<< " " << head->m_value;
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;

}

int main()
{
    node_t *node1 = new node_t[1];
    node_t *node2 = new node_t[1];
    node_t *node3 = new node_t[1];
    node_t *node4 = new node_t[1];
    
    node1->m_array = new node_t[3];
    node2->m_array = new node_t[1];
    node3->m_array = new node_t[2];
    
    node4->m_amount = 0;
    node4->m_value = 3;

    node3->m_amount = 2;
    node3->m_value = 2;

    node2->m_amount = 1;
    node2->m_value = 1;

    node1->m_amount = 3;
    node1->m_value = 0;

    node3->m_array[0] = *node1;
    node3->m_array[1] = *node2;
    

    
    node2->m_array[0] = *node4;
    

    
    node1->m_array[0] = *node2;
    node1->m_array[1] = *node3;
    node1->m_array[2] = *node4;
    

    PrintAllPaths(node3, 10, 0, 3);

    delete [] node3->m_array;
    delete [] node2->m_array;
    delete [] node1->m_array;
    
    delete [] node1;
    delete [] node2;
    delete [] node3;
    delete [] node4;

    return 0;
}