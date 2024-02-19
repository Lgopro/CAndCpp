

#ifndef MESSAGEHEADER_HPP
#define MESSAGEHEADER_HPP


#include <iostream>

#include <time.h> /* time_t*/
#include <arpa/inet.h> /* pid_t*/
#include <cinttypes>
#include <cstdio>
#include <cstdint>
#include <cstring>


namespace ilrd
{
    class MessageHeader
    {
        public:

        MessageHeader() = default;
        ~MessageHeader() = default;
        MessageHeader& operator=(const MessageHeader& other) = default;
        MessageHeader(const MessageHeader& other) = default;

        virtual char * ToBuffer(char *array) = 0;
        virtual char * FromBuffer(char *array) = 0;
        virtual size_t GetBufferSize() = 0;

    };

    class ReadMessage : public MessageHeader
    {
        public:

        ReadMessage(uint32_t offset = 0, uint32_t how_much = 0, u_int32_t uid = 0);
        ~ReadMessage();
        ReadMessage& operator=(const ReadMessage& other) = default;
        ReadMessage(const ReadMessage& other) = default;

        char * ToBuffer(char *array);
        char * FromBuffer(char *array);
        size_t GetBufferSize();
        uint32_t GetOffset() const;
        uint32_t GetHowMuch() const;
        char * GetArray() const;
        char ReturnMode() const;
        u_int32_t GetUID() const;
        
        private:

        char *m_array;
        uint32_t m_offset;
        uint32_t m_how_much;
        char m_mode;
        u_int32_t m_uid;
    };

    class WriteMessage : public MessageHeader
    {
        public:

        WriteMessage(uint32_t offset, uint32_t how_much, char * array, u_int32_t uid);
        ~WriteMessage();
        WriteMessage& operator=(const WriteMessage& other) = default;
        WriteMessage(const WriteMessage& other) = default;

        char * ToBuffer(char *array);
        char * FromBuffer(char *array);
        size_t GetBufferSize();
        uint32_t GetOffset() const;
        uint32_t GetHowMuch() const;
        char * GetArray() const;
        char ReturnMode() const;
        u_int32_t GetUID() const;


        private:

        char *m_array;
        uint32_t m_offset;
        uint32_t m_how_much;
        char m_mode;
        u_int32_t m_uid;
    };

 
    class ReadResponce : public MessageHeader
    {
        public:

        ReadResponce() = default;
        ~ReadResponce() = default;
        ReadResponce& operator=(const ReadResponce& other) = default;
        ReadResponce(const ReadResponce& other) = default;

        char * ToBuffer(char *array);
        char * FromBuffer(char *array);

        private:
        char *m_array;
    };

    class WriteResponce : public MessageHeader
    {
        public:

        WriteResponce() = default;
        ~WriteResponce() = default;
        WriteResponce& operator=(const WriteResponce& other) = default;
        WriteResponce(const WriteResponce& other) = default;

        char * ToBuffer(char *array);
        char * FromBuffer(char *array);

        private:
        char *m_array;
    };

}


#endif /*MESSAGEHEADER_HPP*/