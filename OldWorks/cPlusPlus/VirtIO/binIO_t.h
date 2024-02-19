#ifndef BIN_IO_H
#define BIN_IO_H

#include <string>
#include <typeinfo>
#include "VirtIO_t.h"
using namespace std;

class BinIO_t : public VirtIO_t
{
public:
    BinIO_t(){}
    virtual ~BinIO_t(){}
    BinIO_t(const char* _fileName, const char* _mode) : VirtIO_t(_fileName, _mode) {}
    virtual BinIO_t &operator<<(char _var) { return Write(_var); }
    virtual BinIO_t &operator<<(unsigned char _var) { return Write(_var); }
    virtual BinIO_t &operator<<(short _var) { return Write(_var); }
    virtual BinIO_t &operator<<(unsigned short _var) { return Write(_var); }
    virtual BinIO_t &operator<<(int _var) { return Write(_var); }
    virtual BinIO_t &operator<<(unsigned int _var) { return Write(_var); }
    virtual BinIO_t &operator<<(double _var) { return Write(_var); }
    virtual BinIO_t &operator<<(float _var) { return Write(_var); }
    virtual BinIO_t &operator<<(long _var) { return Write(_var); }
    virtual BinIO_t &operator<<(unsigned long _var) { return Write(_var); }

    virtual BinIO_t &operator>>(char &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(unsigned char &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(short &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(unsigned short &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(int &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(unsigned int &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(double &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(float &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(long &_var) { return Read(_var); }
    virtual BinIO_t &operator>>(unsigned long &_var) { return Read(_var); }

    enum flag
    {
        write,
        read,
        none
    };

    BinIO_t& operator << (const void* _buff)
    {
        if( GetStatus() == ok_e && _buff != NULL)
        {
            m_buffer = (void*)_buff;
            m_flag = write;
            return *this;
        }
        throw TException_t<int>(writeErr_e, __FILE__, __LINE__, "There is nothing to write");

    }

    BinIO_t& operator >> (void* _buff)
    {
        if(GetStatus() == ok_e && _buff != NULL)
        {
            m_buffer = _buff;
            m_flag = read;
            return *this;
        }
        throw TException_t<int>(readErr_e, __FILE__, __LINE__, "There is nothing to read");
    }

    void operator , (int _len)
    {

        if(m_flag == write)
        {
            if(fwrite(m_buffer, _len, sizeof(char), GetFile()) == 0)
            {
                SetStatus(writeErr_e);
                throw TException_t<int>(-1, __FILE__, __LINE__, "There is nothing to write");
            }  
        }
        if(m_flag == read)
        {
            if(fread(m_buffer, _len, sizeof(char), GetFile()) == 0)
            {
                SetStatus(readErr_e);
                throw TException_t<int>(-1, __FILE__, __LINE__, "There is nothing to write");
            }
        }
    }


private:
    
	void* m_buffer;
    flag m_flag;

    template <class T>
    BinIO_t& Write(const T &_val)
    {
        if( GetStatus() == ok_e && m_flag == write)
        {
            if(fwrite(m_buffer, sizeof(m_buffer), sizeof(char), GetFile()) == 0)
            {
                SetStatus(writeErr_e);
                throw TException_t<int>(-1, __FILE__, __LINE__, "Write error");
            }  
            return *this;
        }
        throw TException_t<T>(_val, __FILE__, __LINE__, "Invalid mode or wrong status");
        return *this;
    }


    template <class T>
    BinIO_t& Read(const T &_val)
    {
        if(m_flag == read && GetStatus() == ok_e)
        {
            if(fread(m_buffer, sizeof(m_buffer), sizeof(char), GetFile()) == 0)
            {
                SetStatus(readErr_e);
                throw TException_t<int>(-1, __FILE__, __LINE__, "Read error");
            }
            return *this;
        }
        throw TException_t<T>(_val, __FILE__, __LINE__, "could not read from file");
        return *this;
    }
};

#endif
