#ifndef _ILRD_INPUT_MEDIATOR_HPP_
#define _ILRD_INPUT_MEDIATOR_HPP_

#include "reactor.hpp"
#include "thread_pool.hpp"
#include "i_proxy.hpp"
#include "framework_reactor.hpp"
#include "handleton_inst.hpp"

namespace ilrd
{

class IProxy;

class InputMediator
{
public:
    InputMediator() = default;
    ~InputMediator() = default;
    InputMediator(const InputMediator& other) = default;
    InputMediator& operator=(const InputMediator& other) = default;

    //Register to reactor, with ReactorCallBack called when proxy is triggered.
    void Register(int fd, IListener::Mode mode, IProxy* proxy);

    void Run();

    void Stop();

private:

    //Activates iproxy GetTask function. Get Task.
    void ReactorCallBack(int fd, IListener::Mode mode, IProxy* proxy);
    /* FrameWorkReactor m_reactor;
    ThreadPool m_thread_pool;
     */
};  //class InputMediator
}   //namespace ilrd


#endif //_ILRD_INPUT_MEDIATOR_HPP_
