
#include "input_mediator.hpp"
#include "tp_task.hpp"

using namespace ilrd;

void InputMediator::Register(int fd, IListener::Mode mode, IProxy* proxy)
{
    std::function <void (IListener::Mode,int) > func = [=] (IListener::Mode mode, int fd)
    {
        this->ReactorCallBack(fd, mode, proxy);
    };

    GetFrameWorkReactor()->Register(fd, mode, func);
}

void InputMediator::ReactorCallBack(int fd, IListener::Mode mode, IProxy* proxy)
{
    std::shared_ptr<IProxy::IProxyTask> task = proxy->GetTask(fd, mode);
    std::shared_ptr<TpTask> task_to_enter(new TpTask (task));
    GetThreadPool()->AddTask(task_to_enter);
}

void InputMediator::Run()
{
    GetFrameWorkReactor()->Run();
}

void InputMediator::Stop()
{
    GetFrameWorkReactor()->Stop();
    GetThreadPool()->Pause();
}