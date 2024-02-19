#ifndef __UDP_PROXY_HPP__
#define __UDP_PROXY_HPP__

#include "i_proxy.hpp"
#include "UDPsocket.hpp"

namespace ilrd
{
    class UDPproxy: public IProxy
    {
        public:
        UDPproxy(UDPsocket *socket);
        ~UDPproxy() = default;
        UDPproxy(const UDPproxy& other) = default;
        UDPproxy& operator=(const UDPproxy& other) = default;

        class UDPReadTask : public IProxy::IProxyTask 
        {   public:

            UDPReadTask(char *array, UDPsocket *socket);
            ~UDPReadTask();
            UDPReadTask(const UDPReadTask& other) = default;
            UDPReadTask& operator=(const UDPReadTask& other) = default;

            int GetKey();
            UDPsocket *GetSocket();
            u_int32_t GetUID();

            private:

            UDPsocket *m_socket;
            char *m_array;
        };
        
        class UDPWriteTask : public IProxy::IProxyTask 
        {   
            public:
            UDPWriteTask(char *array, UDPsocket *socket);  
            ~UDPWriteTask();
            UDPWriteTask(const UDPWriteTask& other) = default;
            UDPWriteTask& operator=(const UDPWriteTask& other) = default;
            
            int GetKey();
            u_int32_t GetUID();
            UDPsocket *GetSocket();
            
            private:

            UDPsocket *m_socket;
            char *m_array;
        };
        
        std::shared_ptr<IProxy::IProxyTask> GetTask(int fd , IListener::Mode mode);

        private: 
        UDPsocket *m_socket;   
    };

}

#endif

