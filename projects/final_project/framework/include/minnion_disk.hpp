
#ifndef MINNION_DISK_HPP
#define MINNION_DISK_HPP

#include <iostream>

namespace ilrd
{
    class MinnionDisk
    {
        public:

        MinnionDisk();
        ~MinnionDisk();
        void Write(size_t offset, size_t how_much, char *arr);
        void Read(size_t offset, size_t how_much, char *arr);
        char *GetArray();
        void Print(size_t offset, size_t amount_to_write) const;

        private:
        MinnionDisk& operator=(const MinnionDisk& other) = delete;
        MinnionDisk(const MinnionDisk* other) = delete;
        char *m_array;
    };
}


#endif