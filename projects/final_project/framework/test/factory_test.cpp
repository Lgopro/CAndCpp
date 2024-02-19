/*
Rev: Yarone Margalit.
Dev: Leonid Golovko
status: finished
date: 15/09/2023
*/
#include "factory.hpp"
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


int main()
{
    ilrd::Factory<int, Test*, int> check;
    check.Register(0, [](int value)->Test*
    {
        TestChild* child = new TestChild(value);
        return child;
    });
    Test *data1 = check.Create(0, 1);

    ilrd::Factory<int, Test*, int> check2;
    check2.Register(2, [](int value)->Test*
    {
        TestChild2 *child2 = new TestChild2(value);
        return child2;
    });
    Test *data2 = check2.Create(2, 10);

    ilrd::Factory<int, Test* ,int > check3;
    check.Register(10, [](int value)->Test*{
        TestChild3 *third_child = new TestChild3;
    });
    Test *data3 = check3.Create(10, 20);
    delete data1;
    delete data2;
    delete data3;
    return 0;

}


