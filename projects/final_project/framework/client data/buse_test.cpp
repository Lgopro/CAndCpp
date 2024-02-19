
#include <iostream> 
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <thread>

#include "buse.hpp"

using namespace ilrd;


void Func()
{
    TCPsocket socket("127.0.0.1", 5000); 
    socket.ListenAndAccept();
    
    char array[] = "Hehe Boy!";

    socket.Recive();
    socket.Send(array);
}

int main()
{

    std::thread t1(Func);

    sleep(1);

    Buse buse(128*1024*1024, "127.0.0.1", "/dev/nbd0", 5000);

    buse.StartBuse();

    return 0;
}
