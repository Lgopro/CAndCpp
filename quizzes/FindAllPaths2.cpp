#include <iostream>
#include <cassert>
#include <list>

typedef struct Node node_t;

struct Node
{
    size_t m_amount;
    node_t *m_array;
    size_t m_value;
};

void FindAllPaths(node_t *prev, node_t *src, node_t *dest, std::list<int> m_list)
{
    assert(src);
    assert(dest);
    if(prev == nullptr)
    {
        m_list.push_back(src->m_value);

    }

    if(src->m_value == dest->m_value)
    {
        for(int iter : m_list)
        {
            std::cout << iter << " ";
        }
        std::cout << " " << std::endl;
        return;
    }

    for(size_t i = 0; i < src->m_amount; ++i)
    {
        if(prev != nullptr)
        {
            if(prev->m_value == src->m_array[i].m_value)
            {
                continue;
            }
        }
        m_list.push_back(src->m_array[i].m_value);
        FindAllPaths(src, &src->m_array[i], dest, m_list);
        m_list.pop_back();
    }
    
}

int main()
{
    std::list<int> list;

    node_t *node1 = new node_t[1];
    node_t *node2 = new node_t[1];
    node_t *node3 = new node_t[1];
    node_t *node4 = new node_t[1];
    
    node1->m_array = new node_t[3]; /*0*/
    node2->m_array = new node_t[1];
    node3->m_array = new node_t[2];
    
    node4->m_amount = 0;
    node4->m_value = 3; /*3*/

    node3->m_amount = 2;
    node3->m_value = 2; /*2*/

    node2->m_amount = 1;
    node2->m_value = 1; /*1*/

    node1->m_amount = 3;
    node1->m_value = 0; /*0*/

    node3->m_array[0] = *node1;
    node3->m_array[1] = *node2;
    
    node2->m_array[0] = *node4;
    
    node1->m_array[0] = *node2;
    node1->m_array[1] = *node3;
    node1->m_array[2] = *node4;
    
    FindAllPaths(nullptr, node3, node4, list);

    return 0;
}