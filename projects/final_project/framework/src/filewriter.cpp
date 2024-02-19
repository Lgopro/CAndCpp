


#include "filewriter.hpp"

#include <fstream>
#include <string>

using namespace ilrd;


void FileWriter::Write(size_t offset, size_t amount_to_write, char *array, char *name)
{
    FILE* file = fopen(name, "w");
    if (file == nullptr) 
    {
        return;
    }
    
    fseek(file, offset, SEEK_SET);  
    fprintf(file, array);
    fclose(file);
    
    std::cout << "Data written to the file with offset successfully." << std::endl;
}



void FileWriter::Read(size_t offset, size_t amount_to_read, char *name , char *array)
{
    std::string filePath = name;

    // Open the file in binary mode
    std::fstream file(filePath, std::ios::binary | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return ;
    }

    // Move the file pointer to the desired offset (e.g., offset bytes from the beginning)
    file.seekp(offset, std::ios::beg);

    // Write data to the file
    file.read(array, amount_to_read);

    // Close the file
    file.close();

    std::cout << "Data recieved to the file with offset successfully." << std::endl;
}