#ifndef __TCP_PRACTICE_HPP__
#define __TCP_PRACTICE_HPP__

#include <mutex>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <list>


namespace ilrd
{
    class TCPsocket
    {
        public:

        TCPsocket(char *ip, unsigned int port);
        ~TCPsocket();
        
        void Bind();
        void ListenAndAccept();

        private:

        TCPsocket(const TCPsocket& other) = delete;
        TCPsocket& operator=(const TCPsocket& other) = delete;

        static void Recive(unsigned int socket, bool *flag);

        static std::mutex m_mutex;
        unsigned int m_socket;
        unsigned int m_port;
        char *m_ip;
        struct sockaddr_in m_serverAddr;
        struct sockaddr_in m_clientAddr;
        socklen_t m_client_len;
        bool m_flag;
        std::list<int> m_list_sockets;
        
    };
}

#endif