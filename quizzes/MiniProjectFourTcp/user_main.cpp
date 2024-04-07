

/*user_main.cpp begin*/
#include "Tcp.hpp"

using namespace ilrd;

const int SUCCESS = 0;
const int FAIL = 1;

int main(int argc, char* argv[]) 
{
    if(argc < 4)
    {
        std::cout << "wrong input" << std::endl;
        return FAIL;
    }

    int userPort = std::stoi(argv[2]);
    int time = std::stoi(argv[3]);

    std::cout << "user port is: " << userPort << std::endl;
    std::cout << "user time is: " << time << std::endl;
    std::cout << "user name is: " << argv[1] << std::endl;

    TcpUser user(userPort, time, argv[1]);

    std::thread t1([&]{
        
    user.TCPCreateSocketUser();
    user.TCPPrepareAddrUser();
    user.TCPSendAndRecieveUser();

    });

    std::this_thread::sleep_for(std::chrono::seconds(40));
    user.Stop();
    t1.detach();

    return SUCCESS;
}

/*user_main.cpp end*/