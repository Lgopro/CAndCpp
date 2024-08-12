
#include "minnionproxy.hpp"
#include "messageheader.hpp"
#include "reactor.hpp"
#include "handleton_inst.hpp"
#include <algorithm>
#include <iostream>
#include <unistd.h> 

using namespace ilrd;

const unsigned int BUFFER_SIZE = 1024;

class WakeUp
{
    public:
    WakeUp():m_fd(0), m_mode(IListener::READ){}
    bool operator()(IListener::Mode mode, int fd)
    {
        char array[BUFFER_SIZE];
        read(fd, array, BUFFER_SIZE);
        std::cout << "Got message of :" << (array + 4) << std::endl;
        GetUIDMap()->SetUIDstatus(*(u_int32_t *)array, UIDMap::RECIEVED_MASTER);
        GetUIDMap()->Print();
    };

    private:
    u_int32_t m_fd;
    IListener::Mode m_mode;
};


static void Recieve(UDPsocket *socket)
{
    ListenHere listener;
    Reactor react(&listener);
    WakeUp wake;
    react.Register(socket->GetSocket(), IListener::READ, wake);
    react.Run();
}

std::vector<std::pair<int, char *>> MinnionProxy::GetFdList()
{
    return m_fd_list;
}

char * MinnionProxy::Read(size_t amout_of_data, size_t offset_in_minnion, size_t minnion_number, UDPsocket *socket, u_int32_t uid)
{
    StartReceiverThreadRead(socket);
    if((minnion_number > m_fd_list.size()) || (offset_in_minnion + amout_of_data > 1024))
    {
        return nullptr;
    }

    std::pair<int, char *> value = m_fd_list[minnion_number];
    /* char *array = socket->GetMessage(); */
    std::cout<< "amount of data is: " << amout_of_data << " offset is " << offset_in_minnion << " uid is: " << /* socket->GetUID() */uid <<std::endl;
    char ip[] = "127.0.0.1";
    ReadMessage message(offset_in_minnion, amout_of_data, uid);
    char *final_arr = new char[3 * sizeof(uint32_t) + sizeof(char) + 1];
    final_arr = message.ToBuffer(final_arr);
    std::cout<< "After ReadMessage final_arr is: mode is:" << *final_arr << " offset is: " << *(u_int32_t *)(final_arr + 1) << " length is: "<< *(u_int32_t *)(final_arr + 5) <<" uid is: " << uid <<std::endl;
    
    socket->Send(ip, 2345, final_arr, /* message.GetUID() */uid);
    
    delete [] final_arr;

    m_receiverThreadread.join();   
    return nullptr; 
}

bool MinnionProxy::Write(char * data, size_t offset_in_minnion, size_t minnion_number, size_t how_much, UDPsocket *socket)
{
    StartReceiverThreadWrite(socket);
    if((minnion_number > m_fd_list.size()) || (offset_in_minnion + strlen(data) > 1024))
    {
        std::cout<< "failed to write" << std::endl;
        return false;
    }
    std::pair<int, char *> value = m_fd_list[minnion_number];
    
    char ip[] = "127.0.0.1";
    WriteMessage message(offset_in_minnion, how_much, data ,*(u_int32_t *)(data + 9));
    char *final_arr = new char[BUFFER_SIZE];
    final_arr = message.ToBuffer(final_arr);
    std::cout << "Write final array: " << *final_arr << *(u_int32_t *)(final_arr + 1) << *(u_int32_t *)(final_arr + 5)<< *(u_int32_t *)(final_arr + 9) << (final_arr + 13) << std::endl;

    socket->Send(ip, 2345, final_arr, message.GetUID());

    delete [] final_arr; 
    
    m_receiverThreadwrite.join();   
    return true;
}

bool MinnionProxy::RegisterMinnion(int fd, char *ip)
{
    bool flag = false;
    
    for(size_t i = 0; i < m_fd_list.size(); ++i)
    {
        if((fd == m_fd_list[i].first) && (0 == strcmp(m_fd_list[i].second, ip)))
        {
            flag = true;
        }
    }

    if(flag == false)
    {
        m_fd_list.push_back(std::make_pair(fd, ip));
        return true;
    }
    else
    {
        return false;
    }
}

bool MinnionProxy::UnregisterMinnion(int fd, char *ip)
{
    bool flag = false;
    
    for(size_t i = 0; i < m_fd_list.size(); ++i)
    {
        if((fd == m_fd_list[i].first) && (0 == strcmp(m_fd_list[i].second, ip)))
        {
            m_fd_list.erase(m_fd_list.begin() + i);
            return true;
        }
    }
    return false;
}

void MinnionProxy::StartReceiverThreadRead(UDPsocket *socket)
{
    std::unique_lock<std::mutex> lock(m_mutex_read);
        
    m_receiverThreadread = std::thread(&MinnionProxy::ReceiverThreadFunctionRead, this, socket);  
}

void MinnionProxy::ReceiverThreadFunctionRead(UDPsocket *socket)
{
    std::unique_lock<std::mutex> lock(m_mutex_read);
    char array[BUFFER_SIZE];
    int value = 1;
    //while readamount is 0 rows(with usleep(10)) only read row
    /* while(value != 0)
    { */
        /* value = */ read(socket->GetSocket(), array, BUFFER_SIZE);//add while
    /* } */
    std::cout << "Got message of :" << (array + 4) << std::endl;
    GetUIDMap()->SetUIDstatus(*(u_int32_t *)array, UIDMap::RECIEVED_MASTER);
    GetUIDMap()->Print();
}


void MinnionProxy::StartReceiverThreadWrite(UDPsocket *socket)
{
    std::unique_lock<std::mutex> lock(m_mutex_write);
        
    m_receiverThreadwrite = std::thread(&MinnionProxy::ReceiverThreadFunctionWrite, this, socket);  
}

void MinnionProxy::ReceiverThreadFunctionWrite(UDPsocket *socket)
{
    std::unique_lock<std::mutex> lock(m_mutex_read);
    char array[BUFFER_SIZE];
    int value = 1;
    //while readamount is 0 rows(with usleep(10)) only read row
    /* while(value != 0)
    { */
        /* value = */ read(socket->GetSocket(), array, BUFFER_SIZE);//add while
    /* } */
    std::cout << "Got message of :" << (array + 4) << std::endl;
    GetUIDMap()->SetUIDstatus(*(u_int32_t *)array, UIDMap::RECIEVED_MASTER);
    GetUIDMap()->Print();
}


