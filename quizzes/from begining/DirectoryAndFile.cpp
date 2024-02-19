
#include <iostream>
#include <list>


namespace ilrd
{
    class FileType
    {
        public:

        FileType(const std::string string = "");
        ~FileType() = default;
        FileType& operator=(const FileType& other) = default;
        FileType(const FileType& other) = default;

        enum Type
        {
            FILE = 0,
            DIRECTORY
        };

        virtual void Print() = 0;
        virtual FileType* Clone() = 0;

        private:
        std::string m_filename;
    };

    class File : public FileType
    {
        public:

        File(const std::string filename = "");
        ~File() = default;
        File& operator=(const File& other) = default;
        File(const File& other) = default;

        void Print() override;
        File* Clone() override;

        private:

        std::string m_filename;
        Type m_type;

    };

    class Directory : public FileType
    {
        public:

        Directory(const std::string filename = "");
        ~Directory() = default;
        Directory& operator=(const Directory& other) = default;
        Directory(const Directory& other) = default;

        
        void Print() override;
        Directory* Clone() override;

        void Add(Type type, std::string filename);

        private:
        std::string m_filename;
        std::list<FileType *> m_directory; 
        Type m_type;

    };
}



using namespace ilrd;

File* ilrd::File::Clone()
{
    return new File(*this);
}

Directory* ilrd::Directory::Clone()
{
    return new Directory(*this);
}


FileType::FileType(const std::string string):m_filename(string)
{

}
        

File::File(const std::string filename): m_filename(filename),m_type(FILE)
{ 
}

Directory::Directory(const std::string filename):m_filename(filename) , m_type(DIRECTORY)
{
}

void Directory::Add(Type type, std::string filename)
{
    if(type == Type::FILE)
    {
        File *file = new File(filename);
        m_directory.push_back(file);
    }
    else
    {
        Directory *directory = new Directory(filename);
        m_directory.push_back(directory);
    }
}

void File::Print()
{
    std::cout << m_filename << " ";
}

void Directory::Print()
{
    std::cout << "diretory name is: " << m_filename << std::endl;
    for(auto iter = m_directory.begin(); iter != m_directory.end(); ++iter)
    {
        (*iter)->Print();
    }
}


int main()
{
    
    Directory directory("first");
    directory.Add(FileType::FILE, "file1");
    directory.Add(FileType::FILE, "file2");
    
    directory.Add(FileType::FILE, "file3");
    
    directory.Add(FileType::FILE, "file4");
    
    directory.Add(FileType::FILE, "file5");
    
    directory.Add(FileType::FILE, "file6");

    
    directory.Add(FileType::DIRECTORY, "FILE");

    Directory directory2("FILE");
    directory2.Add(FileType::FILE, "fillee");

    directory.Print();
    
    return 0;
}