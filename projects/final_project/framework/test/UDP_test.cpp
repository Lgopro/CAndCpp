

#include "UDP.hpp"
#include <thread>
#include "string.h"

using namespace ilrd;

void Sender()
{
    std::cout << "Sleeping for 5 seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    char arr[] = "Hello bruh";
    size_t port = 2345;
    char ip[] = "10.20.30.40";
    UDPsender sender(port, ip, strlen(arr), arr);
    sender.Send();

}

void Reciever()
{
    size_t port = 2345;
    char ip[] = "10.20.30.40";
    UDPreciever reciever(port, ip);
    reciever.Recieve();
}

int main()
{
    std::thread t1(Sender);

    std::thread t2(Reciever);


    t1.join();
    t2.join();
}