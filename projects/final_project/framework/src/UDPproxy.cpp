
#include <unistd.h>
#include "UDPproxy.hpp"

using namespace ilrd;

#include <memory>
#include <iostream>
#include "string.h"
#include "uid_map.hpp"
#include "handleton_inst.hpp"

const unsigned int BUFFER_SIZE = 1024;

UDPproxy::UDPproxy(UDPsocket *socket):m_socket(socket)
{
}

UDPproxy::UDPReadTask::UDPReadTask(char* array, UDPsocket *socket):m_socket(socket)
{
    m_array = new char[1024];
    m_array = array;
    *m_array = *array;
    *(u_int32_t *)(m_array + 1) = *(u_int32_t *)(array + 1);
    *(u_int32_t *)(m_array + 5) = *(u_int32_t *)(array + 5);
    *(u_int32_t *)(m_array + 9) = *(u_int32_t *)(array + 9);
    *(m_array + 13) = '\0';

}

UDPproxy::UDPReadTask::~UDPReadTask()
{
    delete [] m_array;
}

UDPproxy::UDPWriteTask::UDPWriteTask(char* array, UDPsocket *socket):m_socket(socket)
{
    m_array = new char[BUFFER_SIZE];
    m_array = array;
} 

UDPproxy::UDPWriteTask::~UDPWriteTask()
{
    delete [] m_array;
}
 
int UDPproxy::UDPWriteTask::GetKey()
{
    std::cout<< "GetKey UDPWriteTask" << std::endl;
    return 1;
}

int UDPproxy::UDPReadTask::GetKey()
{
    std::cout<< "GetKey UDPReadTask" << std::endl;
    return 0;
}

std::shared_ptr<IProxy::IProxyTask> UDPproxy::GetTask(int fd , IListener::Mode mode)
{
    std::cout<< "Got to Get task" <<std::endl;
    char array[BUFFER_SIZE];
    read(fd, array, BUFFER_SIZE);
   
    std::cout << "Minnion Server Got message..." << std::endl;
    
    char mode_arr = *array;
    if(mode_arr == 'w')
    {
        std::cout << *array << *(u_int32_t *)(array + 1) << *(u_int32_t *)(array + 5) << " uid :" << *(u_int32_t *)(array + 9) << (array + 13) << std::endl;
    }

    if(mode_arr == 'r')
    {
        std::cout <<"Get task UDP: " << *array << *(u_int32_t *)(array + 1) << *(u_int32_t *)(array + 5) << " uid :" << *(u_int32_t *)(array + 9) << std::endl;
    }
    
    if(mode_arr == 'r')
    {
        ReadMessage message(*(u_int32_t *)(array + 1), *(u_int32_t *)(array + 5), *(u_int32_t *)(array + 9));
        m_socket->SetMessageRead(array); //do not it twise..from buffer
        return std::make_shared<UDPReadTask>(m_socket->GetMessage() /* message.GetArray()  */, m_socket);
    }

    if(mode_arr == 'w')
    {
        WriteMessage message(*(u_int32_t *)(array + 1), *(u_int32_t *)(array + 5), array ,*(u_int32_t *)(array + 9));
        m_socket->SetMessageWrite(array);//do not do it twise..from buffer
        return std::make_shared<UDPWriteTask>( m_socket->GetMessage() /* array */, m_socket);
    }
}

/* u_int32_t UDPproxy::UDPReadTask::GetOffset() 
{
    return *(uint32_t *)m_array;
}

u_int32_t UDPproxy::UDPReadTask::GetLength()
{
    return *(uint32_t *)(m_array + sizeof(uint32_t));
}

char *UDPproxy::UDPReadTask::GetArray()
{
    return (m_array + 2 * sizeof(uint32_t));
} */
/* 
u_int32_t UDPproxy::UDPWriteTask::GetOffset()
{
    return *(uint32_t *)m_array;
}

u_int32_t UDPproxy::UDPWriteTask::GetLength()
{
    return *(uint32_t *)(m_array + sizeof(uint32_t));
}

char *UDPproxy::UDPWriteTask::GetArray()
{
    return (m_array + 2 * sizeof(uint32_t));
}

char *UDPproxy::UDPWriteTask::GetMinnionArray()
{
    return m_array;
} */

UDPsocket *UDPproxy::UDPWriteTask::GetSocket()
{
    return m_socket;
}
/* 
size_t UDPproxy::UDPWriteTask::GetHowMany()
{
    return 0;
}

size_t UDPproxy::UDPWriteTask::GetWhere()
{
    return 0;
}

int UDPproxy::UDPWriteTask::GetFD()
{
    return 0;
}
 */
/* char *UDPproxy::UDPReadTask::GetMinnionArray()
{
    return m_array;
} */

UDPsocket *UDPproxy::UDPReadTask::GetSocket()
{
    return m_socket;
}
/* size_t UDPproxy::UDPReadTask::GetHowMany()
{
    return 0;
}
size_t UDPproxy::UDPReadTask::GetWhere()
{
    return 0;
}

int UDPproxy::UDPReadTask::GetFD()
{
    return 0;
}
*/
u_int32_t UDPproxy::UDPReadTask::GetUID()
{
    return 0;
}


u_int32_t UDPproxy::UDPWriteTask::GetUID()
{
    return 0;
}