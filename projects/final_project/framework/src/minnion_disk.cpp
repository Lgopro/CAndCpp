

#include "minnion_disk.hpp"
#include <cstring>

using namespace ilrd;

MinnionDisk::MinnionDisk()
{
    m_array = new char[1024];
    for(int i = 0; i < 1023 ;i++)
    {
        m_array[i] = '@';
    }
    m_array[1023] = '\0';
}


MinnionDisk::~MinnionDisk()
{
    delete [] m_array;
}

char *MinnionDisk::GetArray()
{
    return m_array;
}

void MinnionDisk::Write(size_t offset, size_t how_much, char *arr)
{
    char *m_arr_begin = GetArray();
    m_arr_begin += offset;
    std::memcpy(m_arr_begin, arr, how_much);
}

void MinnionDisk::Read(size_t offset, size_t how_much, char *arr)
{
    char *m_arr_begin = GetArray();
    m_arr_begin += offset;
    std::memcpy(arr, m_arr_begin, how_much);
}

void MinnionDisk::Print(size_t offset, size_t amount_to_write) const
{
    std::cout <<" The array is:" << m_array << std::endl;
    std::cout << "The offset is: " << offset << " The amount of data to write is: " << amount_to_write << std::endl;
}