/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 03/09/23
*/
#include "PingPong.h"


int main()
{
    tcp_user user;
    char *IP = "127.0.0.1";
    int i = 0;
    

    TCPCreateSocketUser(&user);
    TCPPrepareAddrUser(&user, 7070, IP);

    for(i = 0; i < 10; ++i)
    {
        TCPSendAndRecieveUser(&user);
    }
    close(user.sockfd);
    return 0;
}