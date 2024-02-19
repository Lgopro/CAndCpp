
#include "dispatcher.hpp"

using namespace ilrd;


template<typename EVENT>
void Dispatcher<EVENT>::Register(std::shared_ptr<ACallback<EVENT>> callback_)
{
    m_callbacks.insert(callback_);
}

template<typename EVENT>
void Dispatcher<EVENT>::UnRegister(std::shared_ptr<ACallback<EVENT>> callback_)
{
    m_callbacks.erase(callback_);
}


template<typename T, typename EVENT>
CallBack<T, EVENT>::CallBack(Dispatcher<EVENT>* dispatcher, const T& obj,
    void (T::*op)(const EVENT&), void (T::*death_op)())
    : ACallback<EVENT>(dispatcher), m_obj(obj), m_op(op), m_death_op(death_op)
{
}


template<typename T, typename EVENT>
void CallBack<T, EVENT>::Notify(const EVENT& event)
{
    m_op(event);
}

template<typename T, typename EVENT>
void CallBack<T, EVENT>::NotifyDeath()
{
    m_death_op();
}

template<typename EVENT>
void Dispatcher<EVENT>::Broadcast(bool death) const
{
    std::shared_ptr<ACallback<EVENT>> iter = m_callbacks.begin();
    for (const auto& iter : m_callbacks)
    {
        std::cout << "Notified" << std::endl;
    }
}


template<typename EVENT>
ACallback<EVENT>::ACallback(Dispatcher<EVENT>* dispatcher):m_dispatcher_ptr(dispatcher)
{
}

template<typename EVENT>
ACallback<EVENT>::~ACallback()
{
    delete m_dispatcher_ptr;
}


template<typename EVENT>
void ACallback<EVENT>::NotifyDeath()
{
    m_dispatcher_ptr->Broadcast(true);
}