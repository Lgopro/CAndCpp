
#include "i_command.hpp"
#include "UDPproxy.hpp"

using namespace ilrd;



class MinnionReadCommand : public ICommand
{
    public:

    MinnionReadCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~MinnionReadCommand() = default;
    MinnionReadCommand(const MinnionReadCommand& other) = default;
    MinnionReadCommand& operator=(const MinnionReadCommand& other) = default;
    
    
    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        std::cout<<"its MinnionReadCommand"<<std::endl;
        m_task();
        FILE *file = fopen("minnion.txt", "a+");
        if(nullptr == file)
        {
            std::cout<< "could not open minnion.txt" << std::endl;
            return false;
        }

        fseek(file,0, SEEK_SET);

        fseek(file, task->GetOffset(), SEEK_SET);

        fread(task->GetMinnionArray(), sizeof(char), task->GetLength(), file);

        fclose(file);

        return false;
    }

    std::function <bool()> GetFunc() const
    {
        return m_task;
    }

    private:

    std::function <bool()> m_task;
};


class MinnionWriteCommand : public ICommand
{
    public:

    MinnionWriteCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~MinnionWriteCommand() = default;
    MinnionWriteCommand(const MinnionWriteCommand& other) = default;
    MinnionWriteCommand& operator=(const MinnionWriteCommand& other) = default;

    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        std::cout<<"its MinnionWriteCommand"<<std::endl;
        m_task();
        FILE *file = fopen("minnion.txt", "a+");
        if(nullptr == file)
        {
            std::cout<< "could not open minnion.txt" << std::endl;
            return false;
        }
        
        fseek(file,0, SEEK_SET);

        fseek(file, task->GetOffset(), SEEK_SET);

        fwrite(task->GetMinnionArray(), sizeof(char), task->GetLength(), file);

        fclose(file);

        return false;
    }

    std::function <bool()> GetFunc() const
    {
        return m_task;
    }

    private:

    std::function <bool()> m_task;
};