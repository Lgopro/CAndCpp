

#include "UserAndServer.hpp"
#include <thread>
using namespace ilrd;

int main()
{
  
    User udp_user1(9000 , 9001);
    std::this_thread::sleep_for(std::chrono::seconds(30));
   
}