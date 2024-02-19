/*
Rev: Asaf Talker.
Dev: Leonid Golovko
status: finished
date: 14/09/2023
*/
#include "thread_pool.hpp"
#include <unistd.h>
using namespace ilrd;

void Func()
{
    static int counter = 0;
    ++counter;
	std::cout << "Counter is:" << counter << std::endl; 
}


void Test1()
{
    std::shared_ptr<ThreadPool::FunctionTask> task(new ThreadPool::FunctionTask(Func));
    ThreadPool pool(6);
    for(int i = 0; i < 20; ++i)
    {
        pool.AddTask(task);
    }
}

void Test2()
{
    std::shared_ptr<ThreadPool::FunctionTask> task(new ThreadPool::FunctionTask(Func));
    ThreadPool pool(5);
    pool.Pause();
    std::cout << "Pause"<< std::endl; 
    for(int i = 0; i < 100; ++i)
    {
        pool.AddTask(task);
    }
    std::cout << "Resume"<< std::endl;
    pool.Resume();
}

void Test3()
{
    std::shared_ptr<ThreadPool::FunctionTask> task(new ThreadPool::FunctionTask(Func));
    ThreadPool pool(5);
    std::cout << "Size is 5"<< std::endl;
    pool.SetNumThread(11);
    std::cout << "Size is 11"<< std::endl;
    for(int i = 0; i < 100; ++i)
    {
        pool.AddTask(task);
    }
}

void Test4()
{
    std::shared_ptr<ThreadPool::FunctionTask> task(new ThreadPool::FunctionTask(Func));
    ThreadPool pool(5);
    std::cout << "Size is 5"<< std::endl;
    pool.SetNumThread(2);
    std::cout << "Size is 2"<< std::endl;
    for(int i = 0; i < 100; ++i)
    {
        pool.AddTask(task);
    }
}
template <int var>
int TemplateFunc()
{
    int return_val = var;
    return return_val;
}

void Test5()
{
    
    ThreadPool pool(2);
    auto var1 = std::make_shared<ThreadPool::FutureTask<int>>(TemplateFunc<1>);
    auto var2 = std::make_shared<ThreadPool::FutureTask<int>>(TemplateFunc<2>);
    auto var3 = std::make_shared<ThreadPool::FutureTask<int>>(TemplateFunc<3>);
    auto var4 = std::make_shared<ThreadPool::FutureTask<int>>(TemplateFunc<4>);
    auto var5 = std::make_shared<ThreadPool::FutureTask<int>>(TemplateFunc<5>);

    pool.AddTask(var1);
    pool.AddTask(var2);
    pool.AddTask(var3);
    pool.AddTask(var4);
    pool.AddTask(var5);


    std::cout << var1->Get() << std::endl;
    std::cout << var2->Get() << std::endl;
    std::cout << var3->Get() << std::endl;
    std::cout << var4->Get() << std::endl;
    std::cout << var5->Get() << std::endl;
}


int main()
{
    Test1();
    std::cout << "Test1 Passed"<< std::endl;
    Test2();
    std::cout << "Test2 Passed"<< std::endl;
    Test3();
    std::cout << "Test3 Passed"<< std::endl;
    Test4();
    std::cout << "Test4 Passed"<< std::endl;
    Test5();
    std::cout << "Test5 Passed"<< std::endl; 
    return 0;



}

