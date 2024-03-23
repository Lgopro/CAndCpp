#include "UserAndServer.hpp"
#include <thread>

using namespace ilrd;


void Test2()
{
    std::cout << "Test 2. Check active users." << std::endl;
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

    user8.domain = "RUS";
    user8.ip = "127.0.0.1";
    user8.machine = "M433";
    user8.user = "Maria";
    user8.password = "4167";
    user8.is_active = false;

    udp_tcp_server.AddNewUser(user1.user, user1);
    udp_tcp_server.AddNewUser(user2.user, user2);
    udp_tcp_server.AddNewUser(user3.user, user3);
    udp_tcp_server.AddNewUser(user4.user, user4);
    udp_tcp_server.AddNewUser(user5.user, user5);
    udp_tcp_server.AddNewUser(user6.user, user6);
    udp_tcp_server.AddNewUser(user7.user, user7);
    udp_tcp_server.AddNewUser(user8.user, user8);
    
    std::thread t2([&]
    {
        std::cout << "Server is not running. Should not be active users" << std::endl;
        udp_tcp_server.PrintAllActiveUsers();
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "Server is running. Oleg, Maxim and Alex entered the server and working now." << std::endl;
        udp_tcp_server.PrintAllActiveUsers();
    });

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::thread t1([&]
    {
        udp_tcp_server.Run();
    });

    std::this_thread::sleep_for(std::chrono::seconds(60));
    udp_tcp_server.CloseServer();
    t1.detach();
    t2.join();
}

void Test3()
{
    std::cout << "Test 3. Check last active time when all users are not active." << std::endl;
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

    user8.domain = "RUS";
    user8.ip = "127.0.0.1";
    user8.machine = "M433";
    user8.user = "Maria";
    user8.password = "4167";
    user8.is_active = false;

    udp_tcp_server.AddNewUser(user1.user, user1);
    udp_tcp_server.AddNewUser(user2.user, user2);
    udp_tcp_server.AddNewUser(user3.user, user3);
    udp_tcp_server.AddNewUser(user4.user, user4);
    udp_tcp_server.AddNewUser(user5.user, user5);
    udp_tcp_server.AddNewUser(user6.user, user6);
    udp_tcp_server.AddNewUser(user7.user, user7);
    udp_tcp_server.AddNewUser(user8.user, user8);
    
    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::thread t1([&]
    {
        udp_tcp_server.Run();
    });

    
    std::this_thread::sleep_for(std::chrono::seconds(10));
    udp_tcp_server.PrintLastActiveTime(user4.user);
    udp_tcp_server.PrintLastActiveTime(user1.user);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::this_thread::sleep_for(std::chrono::seconds(88));
    udp_tcp_server.PrintLastActiveTime(user4.user);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    udp_tcp_server.CloseServer();
    t1.detach();
}


void Test1()
{
    std::cout << "Test print all users. Add Bella. Remove Maria." << std::endl;

    std::string str = "github.com/example";
    Server udp_tcp_server(9000, str);

    UserData user1;
    UserData user2;
    UserData user3;
    UserData user4;
    UserData user5;
    UserData user6;
    UserData user7;
    UserData user8;
    UserData user9;

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

    user8.domain = "RUS";
    user8.ip = "127.0.0.1";
    user8.machine = "M433";
    user8.user = "Maria";
    user8.password = "4167";
    user8.is_active = false;

    udp_tcp_server.AddNewUser(user1.user, user1);
    udp_tcp_server.AddNewUser(user2.user, user2);
    udp_tcp_server.AddNewUser(user3.user, user3);
    udp_tcp_server.AddNewUser(user4.user, user4);
    udp_tcp_server.AddNewUser(user5.user, user5);
    udp_tcp_server.AddNewUser(user6.user, user6);
    udp_tcp_server.AddNewUser(user7.user, user7);
    udp_tcp_server.AddNewUser(user8.user, user8);
    

    std::cout << "Printing all users available" << std::endl;
    udp_tcp_server.PrintAllUserNames();

    user9.domain = "RUS";
    user9.ip = "127.0.0.1";
    user9.machine = "M433";
    user9.user = "Bella";
    user9.password = "1111";
    user9.is_active = false;

    udp_tcp_server.AddNewUser(user9.user, user9);

    std::cout << "Added Bella" << std::endl;
    std::cout << "Printing all users available" << std::endl;
    udp_tcp_server.PrintAllUserNames();

    std::cout << "Removed Maria" << std::endl;
    udp_tcp_server.RemoveUser(user8.user);

    std::cout << "Printing all users available" << std::endl;
    udp_tcp_server.PrintAllUserNames();

    std::cout << "Test pass" << std::endl;
}


int main()
{
    /* Test1();
    Test2(); */
    Test3();

    return 0;
}