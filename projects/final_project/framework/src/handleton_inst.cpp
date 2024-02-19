


#define __ILRD_CREATOR__
#include "handleton_inst.hpp"
#include "handleton.hpp"


using namespace ilrd;

extern "C" ilrd::Scheduler* GetSchedulerInstance()
{
    return ilrd::Handleton<ilrd::Scheduler>::GetInstance();
}

extern "C" ilrd::ThreadPool* GetThreadPool()
{
    return ilrd::Handleton<ilrd::ThreadPool>::GetInstance();
}

extern "C" ilrd::FrameWorkReactor* GetFrameWorkReactor()
{
    return ilrd::Handleton<ilrd::FrameWorkReactor>::GetInstance();
}

extern "C" ilrd::Factory<int, ilrd::ICommand*> *GetFactory()
{
    return ilrd::Handleton<ilrd::Factory<int, ilrd::ICommand*>>::GetInstance();
}

extern "C" ilrd::MinnionProxy* GetMinnionInstance()
{
    return ilrd::Handleton<ilrd::MinnionProxy>::GetInstance();
}

extern "C" ilrd::RAIDManager* GetRaidInstance()
{
    return ilrd::Handleton<ilrd::RAIDManager>::GetInstance();
}

extern "C" ilrd::UID *GetUID()
{
    return ilrd::Handleton<ilrd::UID>::GetInstance();
}

extern "C" ilrd::UIDMap *GetUIDMap()
{
    return ilrd::Handleton<ilrd::UIDMap>::GetInstance();
}
/* extern "C" Framework *GetFrameWork()
{
    return Handleton<Framework>::GetInstance();
} */
