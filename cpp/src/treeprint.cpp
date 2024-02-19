/*
Rev: Yarone Margalit
Dev: Leonid Golovko
status: finished
date: 24/08/23
*/

#include "treeprint.hpp"
#include <string.h>

using namespace ilrd;
size_t counter = 0;
Eentry::Eentry(const std::string string) : str(string)
{
}

Eentry::~Eentry()
{
}

File::File(const std::string string) : Eentry(string)
{
}
File::File(const File &other) : Eentry(other)
{
}
Eentry &Eentry::operator=(const Eentry &other)
{
    this->str = other.str;
    return *this;
}

Eentry::Eentry(const Eentry &other)
{
    this->str = other.str;
}

void File::Print()
{
    std::cout << "File name is: " << this->GetStr() << std::endl;
}

void Directory::Print()
{
    std::set<Eentry *>::iterator iter = ls.begin();
    std::cout << "Directory name is: " << this->GetStr() << std::endl;
    counter += 2;
    for (size_t i = 0; i < this->ls.size(); ++i)
    {
        for (size_t j = 0; j < counter; ++j)
        {
            std::cout << " ";
        }
        (*iter)->Print();
        ++iter;
    }
}

void Directory::AddEntry(Eentry &add)
{
    this->ls.insert(&add);
}

File *File::Clone() const
{
    return new File(*this);
};

Directory *Directory::Clone() const
{
    return new Directory(*this);
};

File &File::operator=(const File &other)
{
    return *this;
}

File::~File()
{
}

Directory &Directory::operator=(const Directory &other)
{
    return *this;
}
Directory::~Directory()
{
}
