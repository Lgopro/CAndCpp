

#include "framework.hpp"
#include "i_command.hpp"
#include "raid_manager.hpp"
#include "minnionproxy.hpp"
#include "handleton_inst.hpp"
#include "UDPsocket.hpp"
#include "NBDproxy.hpp"

#include <unistd.h>
using namespace ilrd;

const unsigned int BUFFER_SIZE = 1024;

class ReadCommand : public ICommand
{
    public:

    ReadCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~ReadCommand() = default;
    ReadCommand(const ReadCommand& other) = default;
    ReadCommand& operator=(const ReadCommand& other) = default;
    
    
    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        auto read_task = std::static_pointer_cast<NBDProxy::NBDRead>(task);
        
        std::cout<<"its ReadCommand"<<std::endl;
        m_task();
        IProxy::IProxyTask *task_run = read_task.get();
        char *check_array = read_task->GetArray();
        
        std::cout<< "fd: " << read_task->GetFD() << " how_may: " << read_task->GetHowMany() << " where: " << read_task->GetWhere() << "uid is : " << read_task->GetUID()<< std::endl;
        std::cout<< "-----------------------------" << std::endl;

        char arr[] = "127.0.0.1";
        RAIDManager *raid_manager = GetRaidInstance();
        raid_manager->GetMinnion()->RegisterMinnion(read_task->GetFD(), arr);
        size_t minnion_number = GetRaidInstance()->GetRightMinnionNumber(read_task->GetWhere());
        size_t offset_in_minnion = GetRaidInstance()->GetOffsetInMinnion(read_task->GetWhere());

        UDPsocket *socket = read_task->GetSocket();

        std::cout<< "Before we send--fd: " << read_task->GetFD() << " how_may: " << read_task->GetHowMany() << " where: " << offset_in_minnion << std::endl;
            
        raid_manager->GetMinnion()->Read(read_task->GetHowMany(), offset_in_minnion, minnion_number, socket, read_task->GetUID());
        
        return true;
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
        auto write_task = std::static_pointer_cast<NBDProxy::NBDWrite>(task);
        m_task(); //?

        char *check_array = write_task->GetArray(); 
        std::cout << "Checking..." << std::endl;
        std::cout << "Status is: " << *check_array << std::endl;
       
        std::cout<< "fd: " << write_task->GetFD() << " how_may: " << write_task->GetHowMany() << " where: " << write_task->GetWhere() << " text is: " << (write_task->GetArray() + 9) << std::endl;
        std::cout<< "-----------------------------" << std::endl;

        char arr[] = "127.0.0.1";

        RAIDManager *raid_manager = GetRaidInstance();
        raid_manager->GetMinnion()->RegisterMinnion(write_task->GetFD(), arr); //? not here- hard codded. ctor of raid manager.
        size_t minnion_number = GetRaidInstance()->GetRightMinnionNumber(write_task->GetWhere());
        size_t offset_in_minnion = GetRaidInstance()->GetOffsetInMinnion(write_task->GetWhere());
        UDPsocket *socket = write_task->GetSocket(); //only in minnion proxy.not in task

        //GetFD not needed.
        std::cout<< "Before we send--fd: " << write_task->GetFD() << " how_may: " << write_task->GetHowMany() << " offset: " << offset_in_minnion << "Array is: " << (write_task->GetArray() + 9) << std::endl;

        raid_manager->GetMinnion()->Write(write_task->GetArray() , offset_in_minnion, minnion_number, write_task->GetHowMany(), socket);
        
        return true;
    }

    std::function <bool()> GetFunc() const
    {
        return m_task;
    }


    private:

    std::function <bool()> m_task;


};

int pipetest4[2];

int Test1()
{
    sleep(2);
    UDPsocket socket("127.0.0.1", 2355);
    std::cout << "Master begin" << std::endl;

    Framework framework;
    Factory <int, ICommand*> *factory = GetFactory();
    factory->Register(0, []()->ICommand *{
        return new ReadCommand([]()->bool{
            std::cout<< "Running read command" << std::endl;
            return true;});
    });
    
    factory->Register(1, []()->ICommand *{
        return new WriteCommand([]()->bool{
            std::cout<< "Running write command" << std::endl;
            return true;});
    });

    char array[] = "YOUCARRY";
    char *test = new char[BUFFER_SIZE];
    *test = 'w';
    *(u_int32_t *)(test + 1) = 29; //offset
    *(u_int32_t *)(test + 5) = 8; //length
    *(u_int32_t *)(test + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test + 9));
    GetUIDMap()->Print();
    strcpy((test + 13), array);

    char array1[] = "MECARRY";
    char *test1 = new char[BUFFER_SIZE];
    *test1 = 'w';
    *(u_int32_t *)(test1 + 1) = 45; //offset
    *(u_int32_t *)(test1 + 5) = 7; //length
    *(u_int32_t *)(test1 + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test1 + 9));
    GetUIDMap()->Print();
    strcpy((test1 + 13), array1);

    char array2[] = "HECARRY";
    char *test2 = new char[BUFFER_SIZE];
    *test2 = 'w';
    *(u_int32_t *)(test2 + 1) = 77; //offset
    *(u_int32_t *)(test2 + 5) = 7; //length
    *(u_int32_t *)(test2 + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test2 + 9));
    GetUIDMap()->Print();
    strcpy((test2 + 13), array2);

    char array3[] = "WECARRY";
    char *test3 = new char[BUFFER_SIZE];
    *test3 = 'w';
    *(u_int32_t *)(test3 + 1) = 100; //offset
    *(u_int32_t *)(test3 + 5) = 7; //length
    *(u_int32_t *)(test3 + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test3 + 9));
    GetUIDMap()->Print();
    strcpy((test3 + 13), array3);

    char *test4 = new char[BUFFER_SIZE];
    *test4 = 'r';
    *(u_int32_t *)(test4 + 1) = 77; //offset
    *(u_int32_t *)(test4 + 5) = 7; //length
    *(u_int32_t *)(test4 + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test4 + 9));
    GetUIDMap()->Print();
    *(test4 + 13) = '\0';

    char *test5 = new char[BUFFER_SIZE];
    *test5 = 'r';
    *(u_int32_t *)(test5 + 1) = 45; //offset
    *(u_int32_t *)(test5 + 5) = 7; //length
    *(u_int32_t *)(test5 + 9) = GetUID()->GenerateUID(); //uid
    GetUIDMap()->RegisterUID(*(u_int32_t *)(test5 + 9));
    GetUIDMap()->Print();
    *(test5 + 13) = '\0';
 
    //std::cout << *test << *(u_int32_t *)(test + 1) << *(u_int32_t *)(test + 5) << *(u_int32_t *)(test + 9) << (test + 13) << std::endl;
    
    //std::cout << "Copied array is: "<< (test + 13) << std::endl;

    if(-1 == pipe(pipetest4))
    {
        std::cout<< "pipe failed" << std::endl;
        return 1;
    }

    pid_t forkpid = fork();

    if(-1 == forkpid)
    {
        std::cout<< "fork failed" << std::endl;
    }
    else if (0 == forkpid)
    {

        write(pipetest4[1], test, BUFFER_SIZE);
        write(pipetest4[1], test1, BUFFER_SIZE);
        write(pipetest4[1], test2, BUFFER_SIZE);
        sleep(1);
        write(pipetest4[1], test3, BUFFER_SIZE);
        write(pipetest4[1], test4, BUFFER_SIZE);
        write(pipetest4[1], test5, BUFFER_SIZE);

        std::cout<< "fork worked: " << pipetest4[1]  << " "  << pipetest4[0] << std::endl;

        exit(0);
    }
    
    std::vector<std::pair<int,int>> fds;
    NBDProxy *task = new NBDProxy(&socket); //hardcodded with minnion class
    unsigned int socket_num = socket.GetSocket();

    fds.push_back({pipetest4[0], 0});

    

    framework.RegisterAll(fds, task);
    
    std::thread t1([&]{framework.Run();});
    sleep(20);

    framework.Stop();

    t1.join();

    delete [] test;
    delete [] test1;
    delete [] test2;
    delete [] test3;
    delete [] test4;
    delete [] test5;
    
    delete task;
    std::cout << "Master end" << std::endl;
    

    return 0;
}

int main()
{
   return Test1();
}