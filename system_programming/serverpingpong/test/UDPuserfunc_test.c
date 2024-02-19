/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 03/09/23
*/
#include <time.h> /*srand*/
#include <stdlib.h> /*srand*/
#include "PingPong.h"



int main()
{
    udp_user user;
    char *IP = "127.0.0.1";
    int random = 0;
    int sleep_time_random = 0;
    int i = 0;
    
       
    
    srand(time(NULL)); 

    random = (rand() % 7) + 3; 
    printf("UDP client will send %d signals\n", random);
    UDPCreateSocketUser(&user);
    UDPPrepareAddrUser(&user, 7070, IP);
    for(i = 0; i < random; ++i)
    {
        UDPSendAndRecieveUser(&user);
        sleep_time_random = (rand() % 7) + 3;  
        printf("UDP client will sleep for %d seconds\n", sleep_time_random);
        sleep(sleep_time_random);
    }
    close(user.sockfd);
    return 0;
}
