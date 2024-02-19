#include <iostream>
#include <unistd.h>
#include "tcp.hpp"

using namespace ilrd;

int main()
{
    char IP[] = "127.0.0.1";
    TCPsocket tcp(IP, 6666);
    tcp.Bind();
    tcp.ListenAndAccept();

    sleep(1000);
    return 0;
}