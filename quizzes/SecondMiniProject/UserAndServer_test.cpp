#include "UserAndServer.hpp"
#include <thread>

using namespace ilrd;


int main()
{
    std::string str= "github.com/example";
    Server udp_tcp_server(9000, str);

    UserData user1;
    UserData user2;
    UserData user3;
    UserData user4;
    UserData user5;
    UserData user6;
    UserData user7;
    UserData user8;

    user1.domain = "IL";
    user1.ip = "127.0.0.1";
    user1.machine = "M123";
    user1.user = "Lesly";
    user1.password = "1234";
    user1.is_active = false;

    user2.domain = "IL";
    user2.ip = "127.0.0.1";
    user2.machine = "M225";
    user2.user = "Alex";
    user2.password = "3333";
    user2.is_active = false;

    user3.domain = "RUS";
    user3.ip = "127.0.0.1";
    user3.machine = "M222";
    user3.user = "Oleg";
    user3.password = "3522";
    user3.is_active = false;

    user4.domain = "RUS";
    user4.ip = "127.0.0.1";
    user4.machine = "M321";
    user4.user = "Maxim";
    user4.password = "5555";
    user4.is_active = false;

    user5.domain = "IL";
    user5.ip = "127.0.0.1";
    user5.machine = "M567";
    user5.user = "Shlomi";
    user5.password = "4321";
    user5.is_active = false;

    user6.domain = "RUS";
    user6.ip = "127.0.0.1";
    user6.machine = "M777";
    user6.user = "Anna";
    user6.password = "8888";
    user6.is_active = false;

    user7.domain = "RUS";
    user7.ip = "127.0.0.1";
    user7.machine = "M333";
    user7.user = "Denis";
    user7.password = "4567";
    user7.is_active = false;

    user7.domain = "RUS";
    user7.ip = "127.0.0.1";
    user7.machine = "M433";
    user7.user = "Maria";
    user7.password = "4167";
    user7.is_active = false;

    udp_tcp_server.AddNewUser(user1.user, user1);
    udp_tcp_server.AddNewUser(user2.user, user2);
    udp_tcp_server.AddNewUser(user3.user, user3);
    udp_tcp_server.AddNewUser(user4.user, user4);
    udp_tcp_server.AddNewUser(user5.user, user5);
    udp_tcp_server.AddNewUser(user6.user, user6);
    udp_tcp_server.AddNewUser(user7.user, user7);
    udp_tcp_server.AddNewUser(user8.user, user8);
    
    std::thread t1([&]
    {
        udp_tcp_server.Run();
    });
    

    sleep(10000);
    udp_tcp_server.CloseServer();
    t1.detach();
    return 0;
}