
#include "framework.hpp"
#include "i_command.hpp"
#include "raid_manager.hpp"
#include "minnionproxy.hpp"
#include "handleton_inst.hpp"
#include "UDPminnion.hpp"

#include <unistd.h>
using namespace ilrd;

char Reading[20];

class NBDProxy: public IProxy
{
    public:
    NBDProxy() = default;
    ~NBDProxy() = default;
    NBDProxy(const NBDProxy& other) = default;
    NBDProxy& operator=(const NBDProxy& other) = default;

    friend class NBDRead;
    friend class NBDWrite;

    class NBDRead : public IProxy::IProxyTask 
    {   public:

        NBDRead(int fd, size_t how_many, size_t where):m_fd(fd),m_how_many(how_many),m_where(where) {};
        ~NBDRead() = default;
        NBDRead(const NBDRead& other) = default;
        NBDRead& operator=(const NBDRead& other) = default;

        int GetKey()
        {
            return 0;
        }

        char * GetArray(){ return m_array;};
        size_t GetHowMany(){return m_how_many;};
        size_t GetWhere(){return m_where;};
        int GetFD(){return m_fd;};


        private:

        int m_fd;
        size_t m_how_many;
        size_t m_where;  
        char *m_array;
    };


    class NBDWrite : public IProxy::IProxyTask 
    {   public:

        NBDWrite(int fd, size_t how_many, size_t where, char *array = "Testing"):m_fd(fd),m_how_many(how_many),m_where(where)  
        {
            m_array = new char[strlen(array)];
            strcpy(m_array, array);
        };
        ~NBDWrite()
        {
            delete [] m_array;
        }
        NBDWrite(const NBDWrite& other) = default;
        NBDWrite& operator=(const NBDWrite& other) = default;
        
        int GetKey()
        {
            std::cout<< "GetKey NBDWrite" << std::endl;
            return 1;
        }

        char *GetArray(){ return (m_array);};
        size_t GetHowMany(){return m_how_many;};
        size_t GetWhere(){return m_where;};
        int GetFD(){return m_fd;};

        private:

        int m_fd;
        size_t m_how_many;
        size_t m_where;
        char * m_array;
        
    };

    std::shared_ptr<IProxy::IProxyTask> GetTask(int fd , IListener::Mode mode);
};

std::shared_ptr<IProxy::IProxyTask> NBDProxy::GetTask(int fd ,IListener::Mode mode)
{
    std::cout<< "Got to Get task" <<std::endl;
    if(mode == IListener::Mode::READ)
    {
        return std::make_shared<NBDRead>(fd, 6, 880);
    }
    return std::make_shared<NBDWrite>(fd, 6, 880);
}


class ReadCommand : public ICommand
{
    public:

    ReadCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~ReadCommand() = default;
    ReadCommand(const ReadCommand& other) = default;
    ReadCommand& operator=(const ReadCommand& other) = default;
    
    
    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
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

        raid_manager->GetMinnion()->Read(m_length, offset_in_minnion, minnion_number);


        /*build buffer. Call to raid manager.*/
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

        char arr[] = "1.1.1.1";
        RAIDManager *raid_manager = GetRaidInstance();
        raid_manager->GetMinnion()->RegisterMinnion(task->GetFD(), arr);
        size_t minnion_number = GetRaidInstance()->GetRightMinnionNumber(task->GetWhere());
        size_t offset_in_minnion = GetRaidInstance()->GetOffsetInMinnion(task->GetWhere());

        raid_manager->GetMinnion()->Write(task->GetArray(), offset_in_minnion, minnion_number, task->GetHowMany());

        return false;
    }

    std::function <bool()> GetFunc() const
    {
        return m_task;
    }


    private:

    std::function <bool()> m_task;


};




void Sender(size_t port, size_t size_of_array ,char *array)
{
    char ip[] = "10.20.30.40";
    UDPMinnionsender send(port, ip, size_of_array, array);
}

int main()
{
    size_t port = 2350;
    char array[] = "Got Good Result";
    size_t size_of_array = strlen(array);
    std::thread t2(std::bind(&Sender, port, size_of_array ,array));
    sleep(10);
    t2.join();
    return 0;
}