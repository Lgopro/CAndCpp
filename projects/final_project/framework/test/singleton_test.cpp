/*
Rev: Ido Isaacs
Dev: Leonid Golovko
status: finished
date: 19/09/2023
*/
#include "factory.hpp"
#include "singleton.hpp"
using namespace ilrd;

class Test
{
    public:
    Test(){};
    ~Test() = default;
    private:
    Test& operator=(const Test& other) = delete;
    Test(const Test& other) = delete;
    

};

class TestChild : public Test
{
    public:
    TestChild(): Test(){};
    ~TestChild() = default;
    TestChild(int val){std::cout << "Test Child: "<< val << std::endl;};

    private:
    TestChild& operator=(const TestChild& other) = delete;
    TestChild(const TestChild& other) = delete;

};


class TestChild2 : public Test
{
    public:
    TestChild2(): Test(){};
    ~TestChild2() = default;
    TestChild2(int val){std::cout << "Test Child2: "<< val << std::endl;};

    private:
    TestChild2& operator=(const TestChild2& other) = delete;
    TestChild2(const TestChild2& other) = delete;

};

class TestChild3 : public Test
{
    public:
    TestChild3(): Test(){};
    ~TestChild3() = default;
    TestChild3(int val){std::cout << "Test Child3: "<< val << std::endl;};

    private:
    TestChild3& operator=(const TestChild3& other) = delete;
    TestChild3(const TestChild3& other) = delete;

};

void Test1(int var)
{
    ilrd::Factory<int, Test*, int> *check = Singleton<Factory<int, Test*, int>>::GetInstance();
    check->Register(0, [var](int value)->Test*
    {
        TestChild* child = new TestChild(value);
        return child;
    });
    Test *data1 = check->Create(0, var);
    delete data1;
}


int main()
{
    std::thread threads[10];
    for(int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(Test1, i);
    }
    
    for(int i = 0; i < 10; ++i)
    {
        threads[i].join();
    }
    
    return 0; 
}






