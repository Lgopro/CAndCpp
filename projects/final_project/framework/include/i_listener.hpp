#ifndef __ILRD_I_LISTENER_HPP__
#define __ILRD_I_LISTENER_HPP__

#include <vector>

class IListener
{
public:
    IListener() = default;
    virtual ~IListener() = default;
    IListener(const IListener&) = delete;
    IListener& operator=(const IListener&) = delete;

    enum Mode
    {
        READ = 0,
        WRITE
    };

    struct FdModePair
    {
        int fd;
        Mode mode;
        bool operator==(const FdModePair& val) const
        {
            return ((this->fd == val.fd) && (this->mode == val.mode));
        }
        FdModePair& operator=(const FdModePair* val)
        {
            fd = val->fd;
            mode = val->mode;
            return *this;
        }

        FdModePair& operator=(const FdModePair& val)
        {
            fd = val.fd;
            mode = val.mode;
            return *this;
        }
    };
    
    
    //Description: Load a DLL
    //Input variables: name of DLL
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    virtual std::vector<FdModePair> Listen(std::vector<FdModePair>& fds) = 0;
};

class ListenHere : public IListener
{
    public:
    ListenHere() = default;
    virtual ~ListenHere() = default;
    ListenHere(const ListenHere&) = delete;
    ListenHere& operator=(const ListenHere&) = delete;

    std::vector<FdModePair> Listen(std::vector<FdModePair>& fds);
};
#endif 