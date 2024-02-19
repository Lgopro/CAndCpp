#ifndef __DIRMONITOR_HPP__
#define __DIRMONITOR_HPP__

#include <iostream>

namespace ilrd
{
    class FileWriter
    {
        public:
        FileWriter() = default;
        ~FileWriter() = default;
        FileWriter(const FileWriter& other) = default;
        FileWriter& operator=(const FileWriter& other) = default;

        void Write(size_t offset, size_t amount_to_write, char *array, char *name);
        void Read(size_t offset, size_t amount_to_read, char *name, char *array);
    };
}










#endif