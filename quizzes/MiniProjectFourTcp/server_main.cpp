/*server_main.cpp begin*/
#include "Tcp.hpp"

using namespace ilrd;

const int SUCCESS = 0;
const int FAIL = 1;

int main(int argc, char* argv[]) 
{
    if(argc < 2)
    {
        std::cout << "wrong input" << std::endl;
        return FAIL;
    }

    int serverPort = std::stoi(argv[1]);

    TcpServer server(serverPort);
    
    std::thread t1([&]{
        server.Run();
    });

    std::this_thread::sleep_for(std::chrono::seconds(50));
    server.Stop();
    t1.detach();
    return SUCCESS;
}

/*server_main.cpp end*/