#include <unistd.h>
#include "NBDproxy.hpp"
#include "messageheader.hpp"

using namespace ilrd;



NBDProxy::NBDProxy(UDPsocket *socket):m_socket(socket)
{

}
        
NBDProxy::NBDRead::NBDRead(int fd, size_t how_many, size_t where, UDPsocket *socket, u_int32_t uid):m_fd(fd),m_how_many(how_many),m_where(where), m_socket(socket), m_uid(uid)
{
    m_array = new char[1024];          
}

NBDProxy::NBDRead::~NBDRead()
{
    delete [] m_array;
}

u_int32_t NBDProxy::NBDRead::GetUID()
{
    return m_uid;
}   

u_int32_t NBDProxy::NBDWrite::GetUID()
{
    return m_uid;
}

int NBDProxy::NBDRead::GetKey()
{
    std::cout<< "GetKey NBDRead" << std::endl;
    return 0;
}

char * NBDProxy::NBDRead::GetArray()
{ 
    return m_array;
}
            
size_t NBDProxy::NBDRead::GetHowMany()
{
    return m_how_many;
}
            
size_t NBDProxy::NBDRead::GetWhere()
{
    return m_where;
}
            
int NBDProxy::NBDRead::GetFD()
{
    return m_fd;
}

u_int32_t NBDProxy::NBDRead::GetOffset()
{
    return 0;
}

u_int32_t NBDProxy::NBDRead::GetLength()
{
    return 0;
}
            
UDPsocket *NBDProxy::NBDRead::GetSocket()
{
    return m_socket;
}

NBDProxy::NBDWrite::NBDWrite(int fd, size_t how_many, size_t where, char *array, UDPsocket *socket, u_int32_t uid):m_fd(fd),m_how_many(how_many),m_where(where), m_socket(socket), m_uid(uid)
{
    m_array = new char[1024];
    *m_array = *array;
    *(uint32_t *)(m_array + 1) = *(uint32_t *)(array + 1);
    *(uint32_t *)(m_array + 5) = *(uint32_t *)(array + 5);
    *(uint32_t *)(m_array + 9) = *(uint32_t *)(array + 9);
    strcpy((m_array + 13), (array + 13));

}

NBDProxy::NBDWrite::~NBDWrite()
{
    delete [] m_array;
}
            
int NBDProxy::NBDWrite::GetKey()
{
    std::cout<< "GetKey NBDWrite" << std::endl;
    return 1;
}

char *NBDProxy::NBDWrite::GetArray()
{ 
    return m_array;
}
            
size_t NBDProxy::NBDWrite::GetHowMany()
{
    return m_how_many;
}

size_t NBDProxy::NBDWrite::GetWhere()
{
    return m_where;
}
            
int NBDProxy::NBDWrite::GetFD()
{
    return m_fd;
}

u_int32_t NBDProxy::NBDWrite::GetOffset()
{
    return 0;
}

u_int32_t NBDProxy::NBDWrite::GetLength()
{
    return 0;
}

UDPsocket *NBDProxy::NBDWrite::GetSocket()
{
    return m_socket;
}

extern int pipetest4[2];

std::shared_ptr<IProxy::IProxyTask> NBDProxy::GetTask(int fd ,IListener::Mode mode)
{
    std::cout<< "Got to Get task" <<std::endl;
    char array[1024];
    read(fd, array, 1024);
    char array_mode = *array;
    u_int32_t offset;
    u_int32_t length;
    u_int32_t uid;

    if('r' == array_mode || 'w' == array_mode)
    {
        offset = *(u_int32_t *)(array + 1);
        length = *(u_int32_t *)(array + 5);
        uid = *(u_int32_t *)(array + 9);

        std::cout << "The full array is: "<< *array << *(u_int32_t *)(array + 1) << *(u_int32_t *)(array + 5) <<  *(u_int32_t *)(array + 9) << (array + 13) << std::endl;
    }

    if('r' == array_mode) //Read to minnion
    {
        mode = IListener::Mode::READ;
        std::cout<< "Get task Array is dont exist in ReadMessage" << std::endl;
        /* m_socket->SetMessageRead(array); */
        return std::make_shared<NBDRead>(fd, length, offset, m_socket, uid);
    }
    else if('w' == array_mode) //Write to minnion
    {
        mode = IListener::Mode::WRITE;
        std::cout<< "Get task Array is: " << array + 9 << std::endl;
        /* m_socket->SetMessageWrite(array); */
        return std::make_shared<NBDWrite>(fd, length, offset, array ,m_socket, uid);
    }
}