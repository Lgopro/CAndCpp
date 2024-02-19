
#include "i_proxy.hpp"

#include "handleton_inst.hpp"
#include "tp_task.hpp"
#include "i_command.hpp"
#include "asyncinjection.hpp"

using namespace ilrd;


void ReadNBDTask::Run()
{
    /* Factory<int, ICommand*> *factory = GetFactory();
    ICommand *command = factory->Create(m_task->GetKey());
    AsyncInjection *async = new AsyncInjection(command->GetFunc(), 1000); */
    std::cout<< "Running ReadNBDTask" <<std::endl;

}


int ReadNBDTask::GetKey()
{
    return m_key;
}


void WriteNBDTask::Run()
{
    /* Factory<int, ICommand*> *factory = GetFactory();
    ICommand *command = factory->Create(m_task->GetKey());
    AsyncInjection *async = new AsyncInjection(command->GetFunc(), 1000); */
    std::cout<< "Running WriteNBDTask" <<std::endl;

}

int WriteNBDTask::GetKey()
{
    return m_key;
}

