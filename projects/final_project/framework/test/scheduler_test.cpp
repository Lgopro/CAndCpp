
/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date: 25/10/2023
*/

#include "handleton_inst.hpp"
#include "scheduler.hpp"


#include<unistd.h>

using namespace ilrd;

class MyTask : public Scheduler::ITask
{
    public:
    MyTask(){}
    virtual void Execute()
    {
        std::cout << "My task" << std::endl;
    }
   

};


class HisTask : public Scheduler::ITask
{
    public:
    HisTask() {}
    virtual void Execute()
    {
        std::cout << "His Task" << std::endl;
    }

};


class ThisTask : public Scheduler::ITask
{
    public:
    ThisTask() {}
    virtual void Execute()
    {
        std::cout << "ThisTask" << std::endl;
    }

};

class TheirTask : public Scheduler::ITask
{
    public:
    TheirTask() {}
    virtual void Execute()
    {
        std::cout << "TheirTask" << std::endl;
    }

};

class ThoseTasks : public Scheduler::ITask
{
    public:
    ThoseTasks() {}
    virtual void Execute()
    {
        std::cout << "ThoseTasks" << std::endl;
    }

};

class SpecialTask : public Scheduler::ITask
{
    public:
    SpecialTask() {}
    virtual void Execute()
    {
        std::cout << "SpecialTask" << std::endl;
    }

};
int main()
{
    Scheduler *scheduler = GetSchedulerInstance();
   
    time_t time1 = 9000;
    time_t time2 = 6000;
    time_t time3 = 7000;
    time_t time4 = 1000;
    time_t time5 = 2000;
    time_t time6 = 3000;



    std::shared_ptr<MyTask> task1 = std::make_shared<MyTask>();
    std::shared_ptr<HisTask> task2 = std::make_shared<HisTask>();
    std::shared_ptr<ThisTask> task3 = std::make_shared<ThisTask>();
    std::shared_ptr<TheirTask> task4 = std::make_shared<TheirTask>();
    std::shared_ptr<ThoseTasks> task5 = std::make_shared<ThoseTasks>();
    std::shared_ptr<SpecialTask> task6 = std::make_shared<SpecialTask>();

    scheduler->AddTask(task1, time1);
    scheduler->AddTask(task2, time2);
    scheduler->AddTask(task3, time3);
    scheduler->AddTask(task4, time4);
    scheduler->AddTask(task5, time5);
    scheduler->AddTask(task6, time6);


    sleep(10);

    return 0;
}



