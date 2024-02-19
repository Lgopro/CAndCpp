
#include "PingPong.h"

int main()
{
    udp_user user;
    char IP[] = "127.0.0.1";
    UDPCreateSocketUser(&user);
    UDPPrepareAddrUser(&user, 8070, IP);
    UDPSendAndRecieveUser(&user);
    return 0;
}