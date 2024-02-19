
#include "framework.hpp"
#include "i_command.hpp"
#include "raid_manager.hpp"
#include "minnionproxy.hpp"
#include "handleton_inst.hpp"
#include "UDPsocket.hpp"
#include "UDPproxy.hpp"
#include "messageheader.hpp"
#include <unistd.h>

using namespace ilrd;
const unsigned int BUFFER_SIZE = 1024;

class MinnionReadCommand : public ICommand
{
    public:

    MinnionReadCommand(std::function <bool()>func):m_task(func), ICommand(func){}
    ~MinnionReadCommand() = default;
    MinnionReadCommand(const MinnionReadCommand& other) = default;
    MinnionReadCommand& operator=(const MinnionReadCommand& other) = default;
    
    
    bool Run(std::shared_ptr<IProxy::IProxyTask> task)
    {
        auto read_task = std::static_pointer_cast<UDPproxy::UDPReadTask>(task);

        std::cout<<"its MinnionReadCommand"<<std::endl;
        m_task();
        FILE *file = fopen("minnion.txt", "r");
        if(nullptr == file)
        {
            std::cout<< "could not open minnion.txt" << std::endl;
            return false;
        }

        char buffer[BUFFER_SIZE];

        char *value = read_task->GetSocket()->GetMessage();

        *(u_int32_t*)buffer = *(u_int32_t*)(value + 9);

        fseek(file, *(u_int32_t*)(value + 1), SEEK_SET);

        fread(buffer + 4, 1, 1000, file);

        char ip[] = "127.0.0.1";

        buffer[4 + *(u_int32_t*)(value + 5)] = '\0';

        std::cout << "The buffer of MinnionReadCommand is: " << buffer + 4 << " uid is: " << *(u_int32_t*)(value + 9) <<std::endl;

        read_task->GetSocket()->Send(ip, 2355, buffer, *(u_int32_t*)(value + 9));

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
        
        auto write_task = std::static_pointer_cast<UDPproxy::UDPWriteTask>(task);
        
        std::cout<<"its MinnionWriteCommand"<<std::endl;
        m_task();
        FILE *file = fopen("minnion.txt", "r+");
        if(nullptr == file)
        {
            std::cout<< "could not open minnion.txt with r+. opening with w" << std::endl;
            file = fopen("minnion.txt", "w");
            if(nullptr == file)
            {
                std::cout<< "could not open minnion.txt with w." << std::endl;
                return false;
            }
        }

        WriteMessage *readfrom;

        char *value = write_task->GetSocket()->GetMessage();
        
        std::cout << "printing :" << *value << *(u_int32_t*)(value + 1) << *(u_int32_t*)(value + 5) << *(u_int32_t*)(value + 9) << (value + 13) << std::endl;
        
        fseek(file, *(u_int32_t*)(value + 1), SEEK_SET);
        
        fwrite(value + 13, sizeof(char), *(u_int32_t*)(value + 5), file);

        char arr[1024];

        *(u_int32_t*)arr = *(u_int32_t*)(value + 9);

        strcpy((arr + 4), "Success");

        char ip[] = "127.0.0.1";
        
        strcpy(write_task->GetSocket()->GetMessage(), arr);
        //Tobuffer
        write_task->GetSocket()->Send(ip, 2355, arr, *(u_int32_t*)(value + 9));

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


int main()
{
    
    std::cout << "Minnion begin" << std::endl;

    UDPsocket udp_socket("127.0.0.1", 2345);
    Framework framework;
    UDPproxy udp_proxy(&udp_socket);
    Factory <int, ICommand*> *factory = GetFactory();


    factory->Register(0, []()->ICommand *{
        return new MinnionReadCommand([]()->bool{
            std::cout<< "Running minnion read command" << std::endl;
            return true;});
    });
    
    factory->Register(1, []()->ICommand *{
        return new MinnionWriteCommand([]()->bool{
            std::cout<< "Running minnion write command" << std::endl;
            return true;});
    });

    std::vector<std::pair<int,int>> fds;
    UDPproxy *task = new UDPproxy(&udp_socket);
    size_t socket = udp_socket.GetSocket();

    fds.push_back({socket, 0});
    
    framework.RegisterAll(fds, task);
    
    std::thread t1([&]{framework.Run();});
    
    sleep(20);

    framework.Stop();

    t1.join();
    delete task;

    std::cout << "Minnion end" << std::endl;
    return 0;
}