

#include "logger.hpp"


using namespace ilrd;


void Logger::ThreadAction(Logger &its_me)
{
    ArrayServerity get_data;
    int flag = 1;
    while(flag)
    {
        its_me.m_queue.Pop(get_data);
        if(get_data.severity == Logger::CLOSE)
        {
            flag = 0;
        }
        if(its_me.m_myfile.is_open())
        {
            its_me.m_myfile << " " << get_data.time_and_data  << " " << its_me.GetServerityString(get_data.severity) <<" " <<  get_data.array << "\n";
            
        }
    }
}

Logger::Logger()
{
    m_myfile.open("Logger.txt");
    m_checker = std::thread(ThreadAction, std::ref(*this));
}

Logger::~Logger()
{
    std::time_t current_time = std::time(nullptr);
    std::string date_time_string = std::ctime(&current_time);
    ArrayServerity insert_data;
    std::string close = "Closed";
    insert_data.array = close;
    insert_data.severity = Logger::CLOSE;
    insert_data.time_and_data = date_time_string;
    insert_data.time_and_data.pop_back();
    m_queue.Push(insert_data);
    m_checker.join();
    m_myfile.close();
}
std::string Logger::GetServerityString(size_t data)
{
    std::string error = "Error";
    std::string debug = "Debug";
    std::string other = "Other";
    std::string close = "Close";
    std::string wrong_input = "Wrong input";
    switch (data) {
        case 0:
            return error;
            break;
        case 1:
            return debug;
            break;
        case 2:
            return other;
            break;
        case 3:
            return close;
            break;
        default:
            std::cout << "Wrong insert" << std::endl;
            break;
    }
    return wrong_input;
}
void Logger::Log(const std::string& array, Severity severity)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::time_t current_time = std::time(nullptr);
    std::string date_time_string = std::ctime(&current_time);
    date_time_string.pop_back();
    ArrayServerity insert_data;
    insert_data.array = array;
    insert_data.severity = severity;
    insert_data.time_and_data = date_time_string;
    m_queue.Push(insert_data);
}

