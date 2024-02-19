#ifndef ASCII_IO_H
#define ASCII_IO_H
#include <string>
#include <typeinfo>
#include "VirtIO_t.h"
using namespace std;

class AsciiIO_t : public VirtIO_t
{
public:
    AsciiIO_t(){}
    AsciiIO_t(const char* _fileName, const char* _mode) : VirtIO_t(_fileName, _mode) {}
    virtual ~AsciiIO_t(){}
    virtual AsciiIO_t &operator<<(char _var) { return Write(_var, "%c"); }
    virtual AsciiIO_t &operator<<(unsigned char _var) { return Write(_var, "%c"); }
    virtual AsciiIO_t &operator<<(short _var) { return Write(_var, "%hd"); }
    virtual AsciiIO_t &operator<<(unsigned short _var) { return Write(_var, "%hu"); }
    virtual AsciiIO_t &operator<<(int _var) { return Write(_var, "%d"); }
    virtual AsciiIO_t &operator<<(unsigned int _var) { return Write(_var, "%u"); }
    virtual AsciiIO_t &operator<<(double _var) { return Write(_var, "%lf"); }
    virtual AsciiIO_t &operator<<(float _var) { return Write(_var, "%f"); }
    virtual AsciiIO_t &operator<<(long _var) { return Write(_var, "%li"); }
    virtual AsciiIO_t &operator<<(unsigned long _var) { return Write(_var, "%lu"); }

    virtual AsciiIO_t &operator>>(char &_var) { return Read(_var, "%c"); }
    virtual AsciiIO_t &operator>>(unsigned char &_var) { return Read(_var, "%c"); }
    virtual AsciiIO_t &operator>>(short &_var) { return Read(_var, "%hd"); }
    virtual AsciiIO_t &operator>>(unsigned short &_var) { return Read(_var, "%hu"); }
    virtual AsciiIO_t &operator>>(int &_var) { return Read(_var, "%d"); }
    virtual AsciiIO_t &operator>>(unsigned int &_var) { return Read(_var, "%u"); }
    virtual AsciiIO_t &operator>>(double &_var) { return Read(_var, "%lf"); }
    virtual AsciiIO_t &operator>>(float &_var) { return Read(_var, "%f"); }
    virtual AsciiIO_t &operator>>(long &_var) { return Read(_var, "%li"); }
    virtual AsciiIO_t &operator>>(unsigned long &_var) { return Read(_var, "%lu"); }

private:
    template <class T>
    AsciiIO_t &Write(const T &_val, const char *_format)
    {
        if(IsInWriteMode() == true && GetStatus() == ok_e)
        {
            size_t bytes = fprintf(GetFile(),_format,_val);
            if(bytes <= 0)
            {
                throw TException_t<T>(_val, __FILE__, __LINE__, "Could not add to file");
            }
            return *this;
        }
        throw TException_t<T>(_val, __FILE__, __LINE__, "There is nothing to write");
        return *this;
    }

    template <class T>
    AsciiIO_t &Read(const T &_val, const char *_format)
    {
        /* T val = _val; */
        if(IsInReadMode() == true && GetStatus() == ok_e)
        {
            if(fscanf(GetFile(), _format, &_val) == 0)
            {
                throw TException_t<T>(_val, __FILE__, __LINE__, "Could not read anthing");
            }
            return *this;
        }
        throw TException_t<T>(_val, __FILE__, __LINE__, "could not read from file");
        return *this;
    }
};

#endif