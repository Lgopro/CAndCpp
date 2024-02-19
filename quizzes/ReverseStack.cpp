#include <iostream>
#include <stack>

template <typename TYPE>
void ReverseStackRec(std::stack<TYPE> stack, std::stack<TYPE>& reverse_stack)
{
    if(stack.empty() == true)
    {
        return;
    }
    reverse_stack.push(stack.top());
    stack.pop();
    ReverseStackRec(stack, reverse_stack);

}

int main()
{
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    std::stack<int> reverse_stack;

    ReverseStackRec(stack, reverse_stack);

    while(reverse_stack.empty() != true)
    {
        std::cout<< reverse_stack.top() << " " << std::endl;
        reverse_stack.pop();
    }
    return 0;
}