

#include "UserAndServer.hpp"
#include <thread>
using namespace ilrd;

int main()
{
    std::thread t1([&]{
        UdpUser udp_user1(9000);
        sleep(33);
    });
    sleep(10);
    std::thread t2([&]{
        UdpUser udp_user2(9000);
        sleep(22);
    });
    sleep(10);
    std::thread t3([&]{
        UdpUser udp_user3(9000);
        sleep(11);
    });
    sleep(20);
}