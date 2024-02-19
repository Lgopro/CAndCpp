#ifndef __DISPATCHER_HPP__
#define __DISPATCHER_HPP__

#include <unordered_set>
#include <memory>
#include <iostream>

namespace ilrd
{
    
template<typename EVENT>
class Dispatcher;

template<typename EVENT>
class ACallBack
{
public:        
    ACallBack() = default;
    virtual ~ACallBack();

    ACallBack(const ACallBack&) = default;
    ACallBack& operator=(const ACallBack&) = default;

    friend Dispatcher<EVENT>;
    

protected:
    virtual void NotifyDeathExtended(){}

private:
    void SetDispatcher(Dispatcher<EVENT>* dispatcher); //because of freind Dispatcher<EVENT>;
    virtual void Notify(const EVENT& event) = 0;  //because of freind Dispatcher<EVENT>;
    void NotifyDeath();  //because of freind Dispatcher<EVENT>;
    Dispatcher<EVENT>* m_dispatcher_ptr;
}; // class ACallBack

template<typename T, typename EVENT>
class CallBack : public ACallBack<EVENT>
{
public:
    CallBack(T& obj, void (T::*op)(const EVENT&), 
                                            void (T::*death_op)() = nullptr);
    CallBack(const CallBack&) = default;
    ~CallBack() = default;
    CallBack& operator=(const CallBack&) = default;
    //Description: Call the m_op function to make an event.
    //Input variables: event.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    void Notify(const EVENT& event);

protected:
    //Description: Call the m_op function to make an event.
    //Input variables: event.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    void NotifyDeathExtended();

private:
    T& m_obj;
    void (T::*m_op)(const EVENT&); 
    void (T::*m_death_op)();
}; // class CallBack

template<typename EVENT>
class Dispatcher
{
public:
    Dispatcher() = default;
    ~Dispatcher();

    Dispatcher(const Dispatcher&) = delete;
    Dispatcher& operator=(const Dispatcher&) = delete;

    //Description: Register an call back to be able to broadcast to all the users registered.
    //Input variables: ACallBack class with a string.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    void Register(ACallBack<EVENT>* CallBack);
    //Description: Unregister an call back to be able to broadcast to all the users registered.
    //Input variables: ACallBack class with a string.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    void UnRegister(ACallBack<EVENT>* CallBack);
    //Description: Broadcast the event to all the registered objects.
    //Input variables: event.
    //Return variables: void.
    //Time complexity: O(n).
    //Space complexity: O(1).
    void Broadcast(const EVENT& event_) const;

private:
    std::unordered_set<ACallBack<EVENT> *> m_CallBacks;

}; // class Dispatcher



template<typename EVENT>
Dispatcher<EVENT>::~Dispatcher()
{
    try
    {
        std::unordered_set<ACallBack<EVENT> *> temp = m_CallBacks;
        auto iter = temp.begin();
        while(iter != temp.end())
        { 
            (*iter)->NotifyDeath();
            ++iter;  
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<typename EVENT>
void Dispatcher<EVENT>::Register(ACallBack<EVENT>* CallBack)
{
    if(nullptr == CallBack)
    {
        throw("CallBack is null");
    }
    CallBack->SetDispatcher(this);
    m_CallBacks.insert(CallBack);
}

template<typename EVENT>
void Dispatcher<EVENT>::UnRegister(ACallBack<EVENT> * CallBack)
{
    if(nullptr == CallBack)
    {
        throw("CallBack is null");
    }
    m_CallBacks.erase(CallBack);
}

template<typename EVENT>
void Dispatcher<EVENT>::Broadcast(const EVENT& event_) const
{
    std::unordered_set<ACallBack<EVENT> *> temp = m_CallBacks;
    auto iter = temp.begin();
    while(iter != temp.end())
    { 
        (*iter)->Notify(event_);
        ++iter;  
    }
}


template<typename T, typename EVENT>
CallBack<T, EVENT>::CallBack(T& obj,
    void (T::*op)(const EVENT&), void (T::*death_op)())
    : m_obj(obj), m_op(op), m_death_op(death_op)
{
    if(nullptr == m_op)
    {
        throw("m_op is null");
    }
}


template<typename T, typename EVENT>
void CallBack<T, EVENT>::Notify(const EVENT& event)
{
    (m_obj.*m_op)(event);
}

template<typename T, typename EVENT>
void CallBack<T, EVENT>::NotifyDeathExtended()
{
    if(nullptr != m_death_op)
    {
        (m_obj.*m_death_op)();
    }
}



template<typename EVENT>
void ACallBack<EVENT>::SetDispatcher(Dispatcher<EVENT>* dispatcher)
{
    m_dispatcher_ptr = dispatcher;
}


template<typename EVENT>
ACallBack<EVENT>::~ACallBack()
{
   if(nullptr != m_dispatcher_ptr)
   {
        m_dispatcher_ptr->UnRegister(this);
   }
    
}


template<typename EVENT>
void ACallBack<EVENT>::NotifyDeath()
{
    m_dispatcher_ptr = nullptr;
    NotifyDeathExtended();
}
} // namespace ilrd
#endif // __DISPATCHER_HPP__
