#ifndef __UDP_SOCKET_HPP__
#define __UDP_SOCKET_HPP__

#include <arpa/inet.h>
#include <iostream>
#include "filewriter.hpp"

namespace ilrd
{
    class UDPsocket
    {
        public:
        UDPsocket(char *ip, unsigned int port);
        ~UDPsocket();
        UDPsocket(const UDPsocket& other) = delete;
        UDPsocket& operator=(const UDPsocket& other) = delete;

        void Send(char *ip, unsigned int port, char *array, u_int32_t uid);
        void RecieveMinnion();
        void RecieveMaster();
        unsigned int GetSocket() const;
        char *GetMessage();
        void SetMessageWrite(char * message);
        void SetMessageRead(char * message);
        void SetMessageReturn(char *message);
        u_int32_t GetUID() const;

        private:
        
        unsigned int m_socket;
        unsigned int m_port;
        char *m_ip;
        char *m_message;
        u_int32_t m_uid;
        struct sockaddr_in m_serverAddr;
        struct sockaddr_in m_clientAddr;
    };
}

#endif