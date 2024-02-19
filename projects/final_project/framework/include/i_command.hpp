#ifndef _ILRD_INPUT_COMMAND_HPP_
#define _ILRD_INPUT_COMMAND_HPP_

#include "reactor.hpp"
#include "thread_pool.hpp"
#include "scheduler.hpp"
#include "i_proxy.hpp"

namespace ilrd
{
class ICommand
{
public:

    inline ICommand(std::function <bool()>func);
    ~ICommand() = default;
    ICommand(const ICommand& other) = default;
    ICommand& operator=(const ICommand& other) = default;

    virtual bool Run(std::shared_ptr<IProxy::IProxyTask> task) = 0;

    virtual std::function <bool()> GetFunc() const = 0;


    private:
    std::function <bool()> m_func;

};  //class ICommand



ICommand::ICommand(std::function <bool()>func):m_func(func)
{

}

}   //namespace ilrd


#endif //_ILRD_INPUT_COMMAND_HPP_
