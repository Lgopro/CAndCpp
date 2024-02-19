#include "treeprint.hpp"
#include <iostream>
#include <set>

using namespace ilrd;

int main()
{

    File file1("file1");
    File file2("file2");
    File file3("file3");
    File file4("file4");

    Directory directory1("directory1");
    Directory directory2("directory2");
    Directory directory3("directory3");
    Directory directory4("directory4");
    Directory directory5("directory5");
    Directory directory6("directory6");
    directory1.AddEntry(file1);
    directory1.AddEntry(file2);
    directory1.AddEntry(file3);
    directory1.AddEntry(file4);
    directory1.AddEntry(directory2);

    directory2.AddEntry(file1);
    directory2.AddEntry(file2);
    directory2.AddEntry(file3);
    directory1.AddEntry(directory5);
    directory2.AddEntry(file4);
    directory1.AddEntry(directory3);

    directory3.AddEntry(file1);
    directory3.AddEntry(file2);
    directory3.AddEntry(file3);
    directory3.AddEntry(file4);
    directory1.AddEntry(directory4);

    directory4.AddEntry(file1);
    directory4.AddEntry(file2);
    directory4.AddEntry(file3);
    directory4.AddEntry(file4);

    directory1.Print();

    Directory *directory10 = static_cast<Directory *>(directory1.Clone());
    std::cout << "" << std::endl;
    directory10->Print();

    delete directory10;
    return 0;
}