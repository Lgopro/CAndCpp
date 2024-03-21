#ifndef __USER_AND_SERVER_HPP__
#define __USER_AND_SERVER_HPP__

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/
#include <sys/select.h>

#define TEXT_SIZE (20)
#define BUFFER_SIZE (100)
#define PING_AMOUNT (5)
#define PONG_AMOUNT (5)
#define UNTIL_END (1)

namespace ilrd
{
    struct UserData
    {
        std::string domain;
        std::string machine;
        std::string ip;
        std::string user;
        std::string password;
    };

    class User
    {
        public:

        User() = default;
        ~User() = default;

        virtual void GetScreenshot() = 0;
        virtual std::time_t GetLastActiveTime() = 0;
        virtual char *GetIp() = 0;
        virtual std::string GetUserName() const = 0;
        virtual std::string GetPassword() const = 0;
        virtual bool IsActive() const = 0;

        private:
        User(const User& other) = delete;
        User& operator=(const User& other) = delete;
    };

    class TcpUser : public User
    {
        public:

        TcpUser();
        ~TcpUser();

        void GetScreenshot();
        std::time_t GetLastActiveTime();
        char *GetIp();
        std::string GetUserName() const;
        std::string GetPassword() const;
        bool IsActive() const;

        void TCPCreateSocketUser();
        void TCPPrepareAddrUser(size_t port, char *IP);
        void TCPSendAndRecieveUser();


        private:

        TcpUser(const TcpUser& other) = delete;
        TcpUser& operator=(const TcpUser& other) = delete;

        std::string m_user_name;
        std::string m_pass_word;

        std::time_t m_last_active_time;
        bool is_user_active = false;

        char *m_ip;

        char ack[TEXT_SIZE];
        int sockfd;
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
        char buffer_from_user[BUFFER_SIZE];
        socklen_t client_len;

    };

    class UdpUser : public User
    {
        public:

        UdpUser();
        ~UdpUser();

        void GetScreenshot();
        std::time_t GetLastActiveTime();
        char *GetIp();
        std::string GetUserName() const;
        std::string GetPassword() const;
        bool IsActive() const;

        void UDPCreateSocketUser();
        void UDPPrepareAddrUser(size_t port, char* IP);
        void UDPSendAndRecieveUser();

        private:

        UdpUser(const UdpUser& other) = delete;
        UdpUser& operator=(const UdpUser& other) = delete;

        std::string m_user_name;
        std::string m_pass_word;

        std::time_t m_last_active_time;
        bool is_user_active = false;

        char *m_ip;

        char ack[TEXT_SIZE];
        int sockfd;
        struct sockaddr_in server_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
    };

    class Server
    {
        public:

        Server(std::string github_link);
        ~Server();

        void TCPSendAndRecieveServer();
        void UDPSendAndRecieveServer();
        void CloseServer();

        private:

        Server(const Server& other) = delete;
        Server& operator=(const Server& other) = delete;

        std::unordered_map <std::string , UserData> m_active_user_list;
        std::unordered_map <std::string , UserData> m_total_user_list;
        

        std::string m_github_link;
        bool m_working_server = false;

        char ack[TEXT_SIZE];
        int udpsock;
        int tcpsock;
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
        char buffer_from_user[BUFFER_SIZE];
        socklen_t client_len;
        fd_set rset;
        int maxfd;
        int ready_descriptor;
    };
}

#endif /*__USER_AND_SERVER_HPP__*/