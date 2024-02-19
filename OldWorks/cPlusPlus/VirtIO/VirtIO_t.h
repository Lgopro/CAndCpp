#ifndef VIRT_IO_H
#define VIRT_IO_H
#include <stdio.h>
#include <iostream>
#include <string>
#include "TException_t.h"
using namespace std;
class VirtIO_t
{
public:
    VirtIO_t();
    virtual ~VirtIO_t() = 0;
    VirtIO_t(const char *_fileName, const char *_mode);
    bool OpenFile(const char *_fileName, const char *_mode);
    bool CloseFile() ;

    enum status
    {
        ok_e,
        cant_open_file_e,
        bad_access_e,
        writeErr_e,
        readErr_e
    };

    int GetLength() const;
    std::string GetName() const { return m_name; } // TODO reference
    std::string GetMode() const { return m_mode; }  // TODO reference

    bool SetPosition(int _pos); 
    const int GetPosition() const;

    virtual VirtIO_t &operator<<(char _var) = 0;
    virtual VirtIO_t &operator<<(unsigned char _var) = 0;
    virtual VirtIO_t &operator<<(short _var) = 0;
    virtual VirtIO_t &operator<<(unsigned short _var) = 0;
    virtual VirtIO_t &operator<<(int _var) = 0;
    virtual VirtIO_t &operator<<(unsigned int _var) = 0;
    virtual VirtIO_t &operator<<(double _var) = 0;
    virtual VirtIO_t &operator<<(float _var) = 0;
    virtual VirtIO_t &operator<<(long _var) = 0;
    virtual VirtIO_t &operator<<(unsigned long _var) = 0;

    virtual VirtIO_t &operator>>(char &_var) = 0;
    virtual VirtIO_t &operator>>(unsigned char &_var) = 0;
    virtual VirtIO_t &operator>>(short &_var) = 0;
    virtual VirtIO_t &operator>>(unsigned short &_var) = 0;
    virtual VirtIO_t &operator>>(int &_var) = 0;
    virtual VirtIO_t &operator>>(unsigned int &_var) = 0;
    virtual VirtIO_t &operator>>(double &_var) = 0;
    virtual VirtIO_t &operator>>(float &_var) = 0;
    virtual VirtIO_t &operator>>(long &_var) = 0;
    virtual VirtIO_t &operator>>(unsigned long &_var) = 0;

protected:
    bool IsInWriteMode();
    bool IsInReadMode();
    status GetStatus() const { return m_status; }
    void SetStatus(status _status){m_status = _status;}
    FILE* GetFile()const {return m_file;};

private:
    FILE *m_file;
    std::string m_name;
    std::string m_mode;
    status m_status;
    size_t m_length;
    size_t m_position;
    VirtIO_t(const VirtIO_t &);
    VirtIO_t &operator=(const VirtIO_t &);
};


bool VirtIO_t::OpenFile(const char *_fileName, const char *_mode)
{
    if(_fileName == NULL || _mode == NULL)
    {
        m_status = cant_open_file_e;
        return false;
    }
    FILE* file = fopen(_fileName,_mode );
    m_position = 0;
    m_file = file;
    m_status = ok_e;
    m_name = _fileName;
    m_mode = _mode;
    return true;
}

VirtIO_t::VirtIO_t(const char *_fileName, const char *_mode)
{
    OpenFile(_fileName,_mode);
}

VirtIO_t::~VirtIO_t()
{
    
}

VirtIO_t::VirtIO_t()
{
    m_file = NULL;
}

bool VirtIO_t::CloseFile() 
{
    if(m_status == ok_e)
    {
        m_name = "No name selected";
        m_mode = "No mode selected";
        return (fclose(m_file) == 0) ? true : false;
    }
    return false;
}

const int VirtIO_t::GetPosition() const
{
    long int pos;
    return ((pos = ftell(m_file))/*  != EOF */ && m_status == ok_e) ? pos : -1;
}


bool VirtIO_t::IsInWriteMode()
{
   return (m_file != NULL &&( m_mode == "w" ||  m_mode == "w+" || m_mode == "r+" || m_mode == "a+" || m_mode == "a")) ? true : false;
}

bool VirtIO_t::IsInReadMode()
{
    return (m_file != NULL &&( m_mode == "r" ||  m_mode == "w+" || m_mode == "r+" || m_mode == "a+")) ? true : false;
}

int VirtIO_t::GetLength() const
{
    long pos, temp;
    if (m_file == NULL) 
    { 
        return -1; 
    } 
    temp = ftell(m_file);
    fseek(m_file, 0, SEEK_END); 
    pos = ftell(m_file);
    fseek(m_file, temp, SEEK_SET); 
    return pos;
}
bool VirtIO_t::SetPosition(int _pos)
{
    
    if(m_file != NULL && _pos < GetLength())
    {
        fseek(m_file, _pos, SEEK_SET );
        return true;
    }    
    return false;
}

#endif