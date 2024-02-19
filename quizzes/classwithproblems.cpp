#include <stack>
#include <ostream>
#include <iostream>


//a) The class reperesent stack.
namespace ilrd
{
class f
{
    int a[100];
    int b;

public:
    f()
    {
        b = -1;
    }
    void h(int d)
    {
        a[++b] = d;
    }

    int e()
    {
        return a[--b];
    }
};



class StackWithNoProblems
{
    public:
    StackWithNoProblems() = default;
    ~StackWithNoProblems() = default;
    StackWithNoProblems(const StackWithNoProblems& other) = default;
    void Push(int value);  
    int Pop();

    private:

    
    StackWithNoProblems& operator=(const StackWithNoProblems& other) = delete;
    std::stack<int> m_stack;
    
};

void StackWithNoProblems::Push(int value)
{
    if(m_stack.size() < 100)
    {   
        m_stack.push(value);
    }
}

int StackWithNoProblems::Pop()
{
    int value = m_stack.top(); 
    m_stack.pop();
    return value;
}

}
using namespace ilrd;
int main()
{

    f class1;
    class1.h(1);
    class1.h(2);
    class1.h(3);
    class1.h(4);
    class1.h(5);
    f class2(class1);

    std::cout << "class1" << std::endl;
    std::cout << class1.e() << std::endl;
    std::cout << class1.e() << std::endl;
    std::cout << class1.e() << std::endl;
    std::cout << class1.e() << std::endl;
    std::cout << "class2" << std::endl;
    std::cout << class2.e() << std::endl;
    std::cout << class2.e() << std::endl;
    std::cout << class2.e() << std::endl;
    std::cout << class2.e() << std::endl;
//c) The automatic copy ctor will work. It will copy all variables to other adress for the new instance of the class.
    StackWithNoProblems stack1;
    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);
    stack1.Push(4);
    stack1.Push(5);
    
    StackWithNoProblems stack2(stack1);

    std::cout << "stack1" << std::endl;
    std::cout << stack1.Pop() << std::endl;
    std::cout << stack1.Pop() << std::endl;
    std::cout << stack1.Pop() << std::endl;
    std::cout << stack1.Pop() << std::endl;
    std::cout << "stack2" << std::endl;
    std::cout << stack2.Pop() << std::endl;
    std::cout << stack2.Pop() << std::endl;
    std::cout << stack2.Pop() << std::endl;
    std::cout << stack2.Pop() << std::endl;

    return 0;
}