
#ifndef __ILRD_HANDLETON_INST_HPP__
#define __ILRD_HANDLETON_INST_HPP__

#include "scheduler.hpp"
#include "thread_pool.hpp"
#include "reactor.hpp"
#include "framework_reactor.hpp"
#include "factory.hpp"
#include "i_command.hpp"
#include "uid.hpp"

#include "raid_manager.hpp"


#include <iostream>

class CheckClass
{
    public:
    void Print(){std::cout << "Addr is: "<< this << std::endl;};
    
};

extern "C" CheckClass* foo();

extern "C" ilrd::Scheduler* GetSchedulerInstance();

extern "C" ilrd::ThreadPool* GetThreadPool();

extern "C" ilrd::FrameWorkReactor* GetFrameWorkReactor();

extern "C" ilrd::MinnionProxy* GetMinnionInstance();

extern "C" ilrd::RAIDManager* GetRaidInstance();

extern "C" ilrd::Factory<int, ilrd::ICommand*> *GetFactory(); 

extern "C" ilrd::UID *GetUID();

extern "C" ilrd::UIDMap *GetUIDMap();

/* extern "C" ilrd::Framework *GetFrameWork(); */

#endif