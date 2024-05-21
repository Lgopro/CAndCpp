
#include <iostream>
#include <string>


typedef struct Node node_t;


struct Node
{
    std::string m_data;
    node_t *m_left;
    node_t *m_right;
};




int Count(node_t *root)
{

    if(root->m_data != "+" && root->m_data != "-" 
       && root->m_data != "*" && root->m_data != "/")
    {
        return std::stoi(root->m_data);
    }

    int left_value = Count(root->m_left);
    int right_value = Count(root->m_right);

    if(root->m_data == "+")
    {
        return left_value + right_value;
    }
    else if(root->m_data == "-")
    {
        return left_value - right_value;
    }
    else if(root->m_data == "*")
    {
        return left_value * right_value;
    }
    
    return left_value / right_value;
    

   
}



int main()
{
    node_t *node_arr = new node_t[7];
    node_arr[0].m_data = "*";
    node_arr[1].m_data = "+";
    node_arr[2].m_data = "+";
    node_arr[3].m_data = "3";
    node_arr[4].m_data = "2";
    node_arr[5].m_data = "4";
    node_arr[6].m_data = "5";


    node_arr[0].m_left = &node_arr[1];
    node_arr[0].m_right = &node_arr[2];
    node_arr[1].m_left = &node_arr[3];
    node_arr[1].m_right = &node_arr[4];
    node_arr[2].m_left = &node_arr[5];
    node_arr[2].m_right = &node_arr[6];

    int result = Count(&node_arr[0]);
    std::cout << "The result is: " << result << std::endl;
    delete [] node_arr;
    return 0;
}