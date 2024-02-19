#ifndef __UDP_MASTER_HPP__
#define __UDP_MASTER_HPP__

#include <iostream>

namespace ilrd
{
    class UDPreciever
    {
        public:

        UDPreciever(size_t port, char * ip);
        ~UDPreciever() = default;
        UDPreciever(const UDPreciever& other) = delete;
        UDPreciever& operator=(const UDPreciever& other) = delete;
        void Recieve();

        private:

        size_t m_port;
        char *m_ip;
        int m_recieve_socket;

    };


    class UDPsender
    {
        public:

        UDPsender(size_t port, char * ip, size_t amount, char *array);
        ~UDPsender();
        UDPsender(const UDPsender& other) = delete;
        UDPsender& operator=(const UDPsender& other) = delete;
        void Send();

        private:

        size_t m_port;
        char *m_ip;
        char *m_array;
        size_t m_amount;
    };
}


#endif