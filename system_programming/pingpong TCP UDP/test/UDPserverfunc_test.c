#include "PingPong.h"
int main()
{
    udp_server server;
    UDPCreateSocketServer(&server);
    UDPPrepareAddrServer(&server, 8070);
    UDPSendAndRecieveServer(&server);

    return 0;
}