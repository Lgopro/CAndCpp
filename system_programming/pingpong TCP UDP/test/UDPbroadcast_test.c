

#include "PingPong.h"

 
int main()
{
    udp_user user;
    char IP[] = "127.255.255.255";
    UDPCreateSocketUserBroadcast(&user);
    UDPPrepareAddrUserBroadcast(&user, 8080, IP);
    UDPSendAndRecieveUserBroadcast(&user);
    return 0;
}