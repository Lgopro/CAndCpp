
/*Tcp.hpp begin*/
#ifndef __TCP_SERVER_HPP__
#define __TCP_SERVER_HPP__

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/
#include <sys/select.h>
#include <mutex>
#include <thread> 

const int SIZE_OF_TEXT = 1024;

namespace ilrd
{

    class TcpUser
    {
        public:

        TcpUser(int tcp_port, size_t sleep, std::string name);
        ~TcpUser();

        void TCPCreateSocketUser();
        void TCPPrepareAddrUser();
        void TCPSendAndRecieveUser();
        void Stop();

        private:

        TcpUser(const TcpUser& other) = delete;
        TcpUser& operator=(const TcpUser& other) = delete;

        int m_sock;
        int m_valread;
        int m_tcp_port;
        struct sockaddr_in m_serv_addr;
        char m_hello[SIZE_OF_TEXT];
        char m_buffer[SIZE_OF_TEXT];
        size_t m_sleep_for;
        std::string m_name;
        bool m_to_send = false;
        std::time_t m_last_active_time;
    };

    class TcpServer
    {
        public:

        TcpServer(int tcp_port_number);
        ~TcpServer();

        void Run();

        void TCPCreateSocketServer();
        void TCPPrepareAddrServer();
        void TCPPrepareListenServer();
        void Stop();

        private:

        TcpServer(const TcpServer& other) = delete;
        TcpServer& operator=(const TcpServer& other) = delete;

        int m_server_fd;
        int m_client_socket;
        struct sockaddr_in m_address;
        int m_opt;
        int m_addrlen;
        int m_serverPort;
        bool m_to_send = false;
        std::mutex m_mutex;
    };
}

#endif /*__TCP_SERVER_HPP__*/
/*Tcp.hpp end*/