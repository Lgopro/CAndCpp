#include "UserAndServer.hpp"
#include <thread>
using namespace ilrd;

int main()
{
    User udp_user1(8888, 9999);
    std::this_thread::sleep_for(std::chrono::seconds(30));
}

