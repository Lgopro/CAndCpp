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

const int TEXT_SIZE = 50;
const int SIZE_OF_TEXT = 1024;
const int PING_AMOUNT = 5;
const int PONG_AMOUNT = 5;
const int UNTIL_END = 1;

namespace ilrd
{
    struct UserData
    {
        std::string domain;
        std::string machine;
        std::string ip;
        std::string user;
        std::string password;
        bool is_active = false;
    };

    class User
    {
        public:

        User() = default;
        ~User() = default;

        virtual void GetScreenshot() = 0;
        virtual std::time_t GetLastActiveTime() = 0;
        virtual const char *GetIp() = 0;
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

        TcpUser(int port);
        ~TcpUser();

        void GetScreenshot();
        std::time_t GetLastActiveTime();
        const char *GetIp();
        std::string GetUserName() const;
        std::string GetPassword() const;
        bool IsActive() const;

        void TCPCreateSocketUser();
        void TCPPrepareAddrUser();
        void TCPSendAndRecieveUser(char *message);


        private:

        TcpUser(const TcpUser& other) = delete;
        TcpUser& operator=(const TcpUser& other) = delete;

        char m_user_name[50];
        char m_pass_word[50];

        std::time_t m_last_active_time;
        bool is_user_active = false;
        bool is_user_right = false;

        std::string m_ip;

        char ack[SIZE_OF_TEXT];
        int sockfd;
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
        char buffer_from_user[SIZE_OF_TEXT];
        socklen_t client_len;

    };

    class UdpUser : public User
    {
        public:

        UdpUser(int port);
        ~UdpUser();

        void GetScreenshot();
        std::time_t GetLastActiveTime();
        const char *GetIp();
        std::string GetUserName() const;
        std::string GetPassword() const;
        bool IsActive() const;

        void UDPCreateSocketUser();
        void UDPPrepareAddrUser();
        void UDPSendAndRecieveUser(char * message);

        private:

        UdpUser(const UdpUser& other) = delete;
        UdpUser& operator=(const UdpUser& other) = delete;

        char m_user_name[50];
        char m_pass_word[50];

        std::time_t m_last_active_time;

        bool is_user_active = false;
        bool is_user_right = false;

        std::string m_ip;
        
        char ack[SIZE_OF_TEXT];
        int sockfd;
        struct sockaddr_in server_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
    };

    class Server
    {
        public:

        Server(int port_number, std::string github_link);
        ~Server();

        void PrintAllActiveUsers() const;
        void AddNewUser(std::string user_name, UserData user_data);
        void PrintAllUserNames() const;
        void Run();

        void TCPSendAndRecieveServer();
        void UDPSendAndRecieveServer();
        void CloseServer();

        private:

        Server(const Server& other) = delete;
        Server& operator=(const Server& other) = delete;

        std::unordered_map <std::string , UserData> m_user_list;
        
        std::string m_github_link;
        bool m_working_server = true;

        char ack[TEXT_SIZE];
        int udpsock;
        int tcpsock;
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        char server_ip_addr[TEXT_SIZE];
        int server_port_number;
        char buffer_from_user[TEXT_SIZE];
        socklen_t client_len;
        fd_set rset;
        int maxfd;
        int ready_descriptor;
    };
}

#endif /*__USER_AND_SERVER_HPP__*/