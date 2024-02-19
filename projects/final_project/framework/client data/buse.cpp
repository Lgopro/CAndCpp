
#include "buse.hpp"
#include <argp.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace ilrd;

Buse::Buse(uint64_t size, char *ip, const std::string& device_address, uint32_t port):m_tcp_socket(ip, port)
{
    m_device_adress = device_address;
    m_aop.read = Read;
    m_aop.write = Write;
    m_aop.disc = Disconnect;
    m_aop.flush = Flush;
    m_aop.trim = Trim;
    m_aop.size = size;
    m_aop.blksize = 0;
    m_aop.size_blocks = 0;

    m_tcp_socket.ListenAndAccept();
}

int Buse::StartBuse()
{
    return (buse_main(m_device_adress.c_str(), &m_aop, static_cast<void *>(&m_tcp_socket)));
}

int Buse::Read(void *buf, u_int32_t len, uint64_t offset, void *userdata)
{
    if (*(int *)userdata)
    {
        fprintf(stderr, "R - %lu, %u\n", offset, len);
    }
    memcpy(buf, (char *)data + offset, len);
    return 0;
}

int Buse::Write(const void *buf, u_int32_t len, uint64_t offset, void *userdata)
{
    if (*(int *)userdata)
    {
        fprintf(stderr, "W - %lu, %u\n", offset, len);
    }
    memcpy((char *)data + offset, buf, len);
    return 0;
}

void Buse::Disconnect(void *userdata)
{
    if (*(int *)userdata)
    {
        fprintf(stderr, "Received a disconnect request.\n");
    }
}

int Buse::Flush(void *userdata)
{
    if (*(int *)userdata)
    {
        fprintf(stderr, "Received a flush request.\n");
    }
    return 0;
}

int Buse::Trim(u_int64_t from, u_int32_t len, void *userdata)
{
    if (*(int *)userdata)
    {
        fprintf(stderr, "T - %lu, %u\n", from, len);
    } 
    return 0;
}

