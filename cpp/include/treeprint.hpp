#ifndef __TREE_PRINT__
#define __TREE_PRINT__

#include <set>
#include <iostream>
#include <iosfwd>

namespace ilrd
{

    class Eentry
    {

    public:
        Eentry(const std::string string = "");
        virtual void Print() = 0;
        virtual Eentry *Clone() const = 0;
        ~Eentry();

    protected:
        Eentry &operator=(const Eentry &other);
        Eentry(const Eentry &other);
        inline std::string GetStr() const;

    private:
        std::string str;
    };

    class File : public Eentry
    {
    public:
        File(const std::string string = "");
        virtual File *Clone() const;
        virtual void Print();
        File &operator=(const File &other);
        ~File();

    protected:
        File(const File &other);
    };

    class Directory : public Eentry
    {
    public:
        Directory(const std::string string = "") : Eentry(string) {}
        virtual void Print();
        virtual Directory *Clone() const;
        void AddEntry(Eentry &add);
        Directory &operator=(const Directory &other);
        ~Directory();

    protected:
        Directory(const Directory &other) : Eentry(other), ls(other.ls) {}

    private:
        std::set<Eentry *> ls;
    };

    inline std::string Eentry::GetStr() const
    {
        return this->str;
    }
}

#endif