
#include "handleton_inst.hpp"
#include "tp_task.hpp"
#include "i_command.hpp"
#include "asyncinjection.hpp"
#include "uid_map.hpp"

using namespace ilrd;


void TpTask::Run()
{
    Factory<int, ICommand*> *factory = GetFactory();
    ICommand *command = factory->Create(m_task->GetKey());
    
    if(command->Run(m_task))
    {
        CheckUIDInMap *checker = new CheckUIDInMap(m_task->GetUID());
        AsyncInjection *async = new AsyncInjection(*checker, 1000);
    }
}

TpTask::TpTask(std::shared_ptr<IProxy::IProxyTask> task):m_task(task)
{
}
