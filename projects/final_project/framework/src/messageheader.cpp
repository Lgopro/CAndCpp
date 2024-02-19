
#include "messageheader.hpp"

using namespace ilrd;


ReadMessage::ReadMessage(uint32_t offset, uint32_t how_much, u_int32_t uid):m_offset(offset), m_how_much(how_much), m_mode('r'), m_uid(uid)
{
    m_array = new char[1024];
}

u_int32_t ReadMessage::GetUID() const
{
    return m_uid;
}

ReadMessage::~ReadMessage()
{
    delete [] m_array;
}

WriteMessage::WriteMessage(uint32_t offset, uint32_t how_much, char * array, u_int32_t uid):m_offset(offset), m_how_much(how_much), m_array(array), m_mode('w'), m_uid(uid)
{
    m_array = new char[1024];
    strcpy(m_array, (array + 13));
    std::cout << "Registered array is: " << m_array << std::endl;
}

WriteMessage::~WriteMessage()
{
    delete [] m_array;
}

size_t ReadMessage::GetBufferSize()
{
    return (sizeof(uint32_t) + sizeof(uint32_t) + sizeof(char) + 1);
}

size_t WriteMessage::GetBufferSize()
{
    return (sizeof(uint32_t) + sizeof(uint32_t) + sizeof(char) + m_how_much);
}

char * ReadMessage::ToBuffer(char *array)
{
    char *begin_arr = array;
    *begin_arr = 'r';
    ++begin_arr;
    *(uint32_t *)begin_arr = m_offset;
    begin_arr += sizeof(m_offset);
    *(uint32_t *)begin_arr = m_how_much;
    begin_arr += sizeof(m_how_much);
    *(uint32_t *)begin_arr = m_uid;
    begin_arr += sizeof(m_uid);
    return array;
}

char * WriteMessage::ToBuffer(char *array)
{
    char *begin_arr = array;
    *begin_arr = m_mode;
    ++begin_arr;
    *(uint32_t *)begin_arr = m_offset;
    begin_arr += sizeof(m_offset);
    *(uint32_t *)begin_arr = m_how_much;
    begin_arr += sizeof(m_how_much);
    *(uint32_t *)begin_arr = m_uid;
    begin_arr += sizeof(m_uid);
    strcpy(begin_arr, m_array);
    return array;
}

char * ReadMessage::FromBuffer(char *array)
{
    char *begin_arr = array;
    m_mode = *begin_arr;
    ++begin_arr;
    m_offset = *(uint32_t *)begin_arr;
    begin_arr += sizeof(m_offset); 
    m_how_much = *(uint32_t *)begin_arr;
    begin_arr += sizeof(m_how_much);
    std::memcpy(m_array, begin_arr, m_how_much);
    return array;
}

u_int32_t WriteMessage::GetUID() const
{
    return m_uid;
}
   
char * WriteMessage::FromBuffer(char *array)
{
    char *begin_arr = array;
    m_mode = *begin_arr;
    ++begin_arr;
    m_offset = *(uint32_t *)array;
    array += sizeof(m_offset);
    m_how_much = *(uint32_t *)array;
    array += sizeof(m_how_much);
    std::memcpy(m_array, array, m_how_much);
    array += m_how_much;
    return begin_arr;
}

uint32_t WriteMessage::GetOffset() const
{
    return m_offset;
}

uint32_t WriteMessage::GetHowMuch() const
{
    return m_how_much;
}

char * WriteMessage::GetArray() const
{
    return m_array;
}

uint32_t ReadMessage::GetOffset() const
{
    return m_offset;
}

uint32_t ReadMessage::GetHowMuch() const
{
    return m_how_much;
}

char * ReadMessage::GetArray() const
{
    return m_array;
}

char * ReadResponce::ToBuffer(char *array)
{
    m_array = array;
    return m_array;
}

char * ReadResponce::FromBuffer(char *array)
{
    m_array = array;
    return m_array;
}

char * WriteResponce::ToBuffer(char *array)
{
    m_array = array;
    return m_array;
}

char * WriteResponce::FromBuffer(char *array)
{
    m_array = array;
    return m_array;
}

char WriteMessage::ReturnMode() const
{
    return m_mode;
}

char ReadMessage::ReturnMode() const
{
    return m_mode;
}
