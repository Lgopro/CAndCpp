


#include "PingPong.h"


int main()
{
    tcp_user user;
    char IP[] = "127.0.0.1";
    TCPCreateSocketUser(&user);
    TCPPrepareAddrUser(&user, 8080, IP);
    TCPSendAndRecieveUser(&user);
    return 0;
}