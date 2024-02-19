/*
Rev: Olev Vragov.
Dev: Leonid Golovko
status: finished
date: 15/09/2023
*/
#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include "waitable_queue.hpp"
#include "handleton.hpp"

#include <functional>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <thread>
#include <iostream>
#include <iomanip>
#include <ctime>

namespace ilrd
{
    class Logger
    {
        public:
        enum Severity
        {
            ERROR = 0,
            DEBUG,
            OTHER, 
            CLOSE
        };

        
        struct ArrayServerity
        {
            std::string array;
            Severity severity;
            std::string time_and_data;
        };

        friend class Handelton;
        void Log(const std::string& array, Severity severity);
        //Description: According to the arguments and key entered returns a BASE.
        //Input variables: key value of hash map, N arguments.
        //Return variables: BASE.
        //Time complexity: O(1).
        //Space complexity: O(1).
        static void ThreadAction(Logger &its_me);
        //Description: According to the arguments and key entered returns a BASE.
        //Input variables: key value of hash map, N arguments.
        //Return variables: BASE.
        //Time complexity: O(1).
        //Space complexity: O(1).
        std::string GetServerityString(size_t data);
        
        private:
        Logger();
        ~Logger();
        Logger& operator=(const Logger& other) = delete;
        Logger(const Logger* other) = delete;
        WaitableQueue <ArrayServerity> m_queue;
        std::ofstream m_myfile;
        std::thread m_checker;
        std::mutex m_mutex;
        
    };

}
#endif /*__LOGGER_HPP__*/


