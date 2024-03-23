

#include "UserAndServer.hpp"
#include <thread>
using namespace ilrd;

int main()
{
  
    UdpUser udp_user2(9000);
    std::this_thread::sleep_for(std::chrono::seconds(20));
   
}