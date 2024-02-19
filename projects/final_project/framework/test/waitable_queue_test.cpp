/*
Rev: Gil Fridman.
Dev: Leonid Golovko
status: finished
date: 11/09/2023
*/
#include "waitable_queue.hpp"
#include <thread> /*threads*/
using namespace ilrd; 
WaitableQueue<size_t> p1;
WaitableQueue<size_t, PriorityQueue <size_t>> pq1; 

void Push(int argument)
{
    for(size_t i = 0;i < 10; ++i)
    {
        p1.Push(i);
    }
}

void Pop(int argument)
{
    size_t var;
    for(size_t i = 0;i < 10; ++i)
    {
        p1.Pop(var);
    }
}

void PopDelay(int argument)
{
    size_t var;
    std::chrono::milliseconds timeout_ = std::chrono::milliseconds(1000);
    for(size_t i = 0;i < 10; ++i)
    {
        p1.Pop(timeout_, var);
    }
}

void PriorityPush(int argument)
{
    for(size_t i = 0;i < 10; ++i)
    {
        pq1.Push(i);
    }
}

void PriorityPop(int argument)
{
    size_t var;
    for(size_t i = 0;i < 10; ++i)
    {
        pq1.Pop(var);
    }
}

void PriorityPopDelay(int argument)
{
    size_t var;
    std::chrono::milliseconds timeout_ = std::chrono::milliseconds(1000);
    for(size_t i = 0;i < 10; ++i)
    {
        pq1.Pop(timeout_, var);
    }
}



void Test1()
{
    int argument;
    const int amount = 10;
    std::thread input[amount];
    std::thread output[amount];
    for(int i = 0;i < amount; ++i)
    {
        input[i] = std::thread(Push, std::ref(argument));
        output[i] = std::thread(Pop, std::ref(argument));
    }
    
    for(int i = 0; i < 10; ++i)
    {
        input[i].join();
        output[i].join();
    }
}

void Test2()
{
    int argument;
    const int amount = 10;
    std::thread input[amount];
    std::thread output[amount];
    for(int i = 0;i < amount; ++i)
    {
        input[i] = std::thread(Push, std::ref(argument));
        output[i] = std::thread(PopDelay, std::ref(argument));
    }
    
    for(int i = 0; i < 10; ++i)
    {
        input[i].join();
        output[i].join();
    }
}

void Test3()
{
    int argument;
    const int amount = 10;
    std::thread input[amount];
    std::thread output[amount];
    for(int i = 0;i < amount; ++i)
    {
        input[i] = std::thread(PriorityPush, std::ref(argument));
        output[i] = std::thread(PriorityPop, std::ref(argument));
    }
    
    for(int i = 0; i < 10; ++i)
    {
        input[i].join();
        output[i].join();
    }
}


void Test4()
{
    
    int argument;
    const int amount = 10;
    std::thread input[amount];
    std::thread output[amount];
    for(int i = 0;i < amount; ++i)
    {
        input[i] = std::thread(PriorityPush, std::ref(argument));
        output[i] = std::thread(PriorityPopDelay, std::ref(argument));
    }
    
    for(int i = 0; i < 10; ++i)
    {
        input[i].join();
        output[i].join();
    }
}

int main()
{
    Test1();
    std::cout << "TEST1 FINISHED" << std::endl;
    Test2();
    std::cout << "TEST2 FINISHED" << std::endl;
    Test3();
    std::cout << "TEST3 FINISHED" << std::endl;
    Test4();
    std::cout << "TEST4 FINISHED" << std::endl;
    return 0;
}

