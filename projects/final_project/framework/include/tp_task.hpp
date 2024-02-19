#ifndef _ILRD_TP_TASK_HPP_
#define _ILRD_TP_TASK_HPP_


#include "thread_pool.hpp"
#include "i_proxy.hpp"

namespace ilrd
{
class TpTask : public ThreadPool::ITask
{
public:

    TpTask(std::shared_ptr<IProxy::IProxyTask> task);
    ~TpTask() = default;
    TpTask(const TpTask& other) = default;
    TpTask& operator=(const TpTask& other) = default;

    void Run();

    private:

    std::shared_ptr<IProxy::IProxyTask> m_task;   
};  //class TpTask

}   //namespace ilrd


#endif //_ILRD_TP_TASK_HPP_
