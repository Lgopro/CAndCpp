

#ifndef BUSE_HPP_INCLUDED
#define BUSE_HPP_INCLUDED

#include <sys/types.h>
#include <iostream>
#include "tcp_socket.hpp"
#include "buse.h"

namespace ilrd
{
  class Buse
  {
    public:

    Buse(uint64_t size, char *ip , const std::string& device_address, uint32_t port);

    int StartBuse();

    ~Buse() = default;
    
    Buse(const Buse& other) = delete;
    
    Buse& operator=(const Buse& other) = delete;

    private:
    
    std::string m_device_adress;
    TCPsocket m_tcp_socket;
    buse_operations m_aop;
    static void *data;

    static int Read(void *buf, u_int32_t len, uint64_t offset, void *userdata);
    static int Write(const void *buf, u_int32_t len, uint64_t offset, void *userdata);
    static void Disconnect(void *userdata);
    static int Flush(void *userdata);
    static int Trim(u_int64_t from, u_int32_t len, void *userdata);

  };
}
#endif /* BUSE_HPP_INCLUDED */