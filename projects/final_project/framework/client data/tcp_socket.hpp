#ifndef __TCP_SOCKET_HPP__
#define __TCP_SOCKET_HPP__

#include <arpa/inet.h>
#include <iostream>
#include "filewriter.hpp"

namespace ilrd
{
    class TCPsocket
    {
        public:

        TCPsocket(char *ip, unsigned int port);
        ~TCPsocket();
        TCPsocket(const TCPsocket& other) = delete;
        TCPsocket& operator=(const TCPsocket& other) = delete;
        void Bind();
        void ListenAndAccept();
        void Send(char *message);
        void Recive();

        char *GetMessage();

        private:
        
        unsigned int m_socket;
        unsigned int m_port;
        char *m_ip;
        char *m_message;
        u_int32_t m_uid;
        struct sockaddr_in m_serverAddr;
        struct sockaddr_in m_clientAddr;
        socklen_t m_client_len;
        unsigned int m_new_socket;
    };
}

#endif