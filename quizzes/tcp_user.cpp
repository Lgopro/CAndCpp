#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <chrono>
#include <thread>

const char* SERVER_IP = "127.0.0.1";
const int SERVER_PORT = 6666;



    


int main(int argc, char *argv[]) 
{
    int clientSocket;
    struct sockaddr_in serverAddr;

   
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(SERVER_PORT);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Connection failed");
        close(clientSocket);
        return 1;
    }

    std::cout << "Connected" << std::endl;

    while(1) 
    {
        send(clientSocket, argv[2], strlen(argv[2]), 0);
        std::this_thread::sleep_for(std::chrono::seconds(std::stoi(argv[1])));
    }

    
    close(clientSocket);

    return 0;
}