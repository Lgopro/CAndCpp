#ifndef _ILRD_INPUT_PROXY_HPP_
#define _ILRD_INPUT_PROXY_HPP_

#include "reactor.hpp"
#include "thread_pool.hpp"
#include "scheduler.hpp"
#include "UDPsocket.hpp"

namespace ilrd
{
class IProxy
{
public:

    IProxy() = default;
    ~IProxy() = default;
    IProxy(const IProxy& other) = default;
    IProxy& operator=(const IProxy& other) = default;


    class IProxyTask
    {
    public:

        IProxyTask() = default;
        ~IProxyTask() = default;
        IProxyTask(const IProxyTask& other) = default;
        IProxyTask& operator=(const IProxyTask& other) = default;

        virtual int GetKey() = 0;
        virtual u_int32_t GetUID() = 0;
        virtual UDPsocket *GetSocket() = 0;
        

    }; //IProxyTask

    virtual std::shared_ptr<IProxyTask> GetTask(int fd, IListener::Mode mode) = 0;

};  //class IProxy
};  



#endif //_ILRD_INPUT_PROXY_HPP_
