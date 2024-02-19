#ifndef _ILRD_NBD_PROXY_HPP_
#define _ILRD_NBD_PROXY_HPP_

#include "i_proxy.hpp"
#include "UDPsocket.hpp"

namespace ilrd
{
    class NBDProxy: public IProxy
    {
        public:
        NBDProxy(UDPsocket *socket);
        ~NBDProxy() = default;
        NBDProxy(const NBDProxy& other) = default;
        NBDProxy& operator=(const NBDProxy& other) = default;

        class NBDRead : public IProxy::IProxyTask 
        {   public:

            NBDRead(int fd, size_t how_many, size_t where, UDPsocket *socket, u_int32_t uid);
            ~NBDRead();
            NBDRead(const NBDRead& other) = default;
            NBDRead& operator=(const NBDRead& other) = default;

            int GetKey();
            char * GetArray();
            size_t GetHowMany();
            size_t GetWhere();
            int GetFD();
            u_int32_t GetOffset();
            u_int32_t GetLength();
            UDPsocket *GetSocket();
            u_int32_t GetUID();


            private:

            int m_fd;
            size_t m_how_many;
            size_t m_where;  
            char *m_array;
            UDPsocket *m_socket;
            u_int32_t m_uid;

        };


        class NBDWrite : public IProxy::IProxyTask 
        {   public:

            NBDWrite(int fd, size_t how_many, size_t where, char *array, UDPsocket *socket, u_int32_t uid);
            ~NBDWrite();
            NBDWrite(const NBDWrite& other) = default;
            NBDWrite& operator=(const NBDWrite& other) = default;
            
            int GetKey();
            char *GetArray();
            size_t GetHowMany();
            size_t GetWhere();
            int GetFD();
            u_int32_t GetOffset();
            u_int32_t GetLength();
            UDPsocket *GetSocket();
            u_int32_t GetUID();

            private:

            int m_fd;
            size_t m_how_many;
            size_t m_where;
            char * m_array;
            u_int32_t m_uid;
            UDPsocket *m_socket;
            
        };

        std::shared_ptr<IProxy::IProxyTask> GetTask(int fd , IListener::Mode mode);

        
        private: 

        UDPsocket *m_socket;  
    };
}

#endif