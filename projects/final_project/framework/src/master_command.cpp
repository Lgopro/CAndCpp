
#include "master_command.hpp"

using namespace ilrd;


ReadCommand::ReadCommand(std::function <bool()>func):m_task(func), ICommand(func)
{

}

bool ReadCommand::Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        
        std::cout<<"its ReadCommand"<<std::endl;
        m_task();
        IProxy::IProxyTask *task_run = task.get();
        read(task->GetFD(), Reading, 5);
        std::cout<< Reading << std::endl;
        std::cout<< "fd: " << task->GetFD() << " how_may: " << task->GetHowMany() << " where: " << task->GetWhere() << std::endl;

        char arr[] = "1.1.1.1";
        RAIDManager *raid_manager = GetRaidInstance();
        raid_manager->GetMinnion()->RegisterMinnion(task->GetFD(), arr);
        size_t minnion_number = GetRaidInstance()->GetRightMinnionNumber(task->GetWhere());
        size_t offset_in_minnion = GetRaidInstance()->GetOffsetInMinnion(task->GetWhere());
        size_t m_length = 10;
        UDPsocket *socket = task->GetSocket();
        raid_manager->GetMinnion()->Read(m_length, offset_in_minnion, minnion_number, socket);

        return false;
    }
    std::function <bool()> GetFunc() const
    {
        return m_task;
    }

    private:

    std::function <bool()> m_task;
};


class WriteCommand : public ICommand
{
    public:

    WriteCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~WriteCommand() = default;
    WriteCommand(const WriteCommand& other) = default;
    WriteCommand& operator=(const WriteCommand& other) = default;

    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        std::cout<<"its WriteCommand"<<std::endl;
        m_task();

        IProxy::IProxyTask *task_run = task.get();
        read(task->GetFD(), Reading, 5);
        std::cout<< Reading << std::endl;
        std::cout<< "fd: " << task->GetFD() << " how_may: " << task->GetHowMany() << " where: " << task->GetWhere() << " text is: " << task->GetArray() << std::endl;

        char arr[] = "127.0.0.1";
        RAIDManager *raid_manager = GetRaidInstance();
        raid_manager->GetMinnion()->RegisterMinnion(task->GetFD(), arr);
        size_t minnion_number = GetRaidInstance()->GetRightMinnionNumber(task->GetWhere());
        size_t offset_in_minnion = GetRaidInstance()->GetOffsetInMinnion(task->GetWhere());
        UDPsocket *socket = task->GetSocket();
        raid_manager->GetMinnion()->Write(task->GetArray(), offset_in_minnion, minnion_number, task->GetHowMany(), socket);

        return false;
    }

    std::function <bool()> GetFunc() const
    {
        return m_task;
    }


    private:

    std::function <bool()> m_task;


};
