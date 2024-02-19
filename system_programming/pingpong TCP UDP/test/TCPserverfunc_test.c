
#include "PingPong.h"

int main()
{
    tcp_server server;
    TCPCreateSocketServer(&server);
    TCPPrepareAddrServer(&server, 8080);
    TCPSendAndRecieveServer(&server);
    return 0;
}