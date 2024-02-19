

#ifndef __MASTER_COMMAND_HPP__
#define __MASTER_COMMAND_HPP__


#include "i_command.hpp"

namespace ilrd
{
    class ReadCommand : public ICommand
    {

        ReadCommand(std::function <bool()>func);
        ~ReadCommand() = default;
        ReadCommand(const ReadCommand& other) = default;
        ReadCommand& operator=(const ReadCommand& other) = default;
        
        bool Run(std::shared_ptr<IProxy::IProxyTask> task);
        std::function <bool()> GetFunc() const;

        private:

        std::function <bool()> m_task;
    };


    class WriteCommand : public ICommand
    {
        public:

        WriteCommand(std::function <bool()>func);
        ~WriteCommand() = default;
        WriteCommand(const WriteCommand& other) = default;
        WriteCommand& operator=(const WriteCommand& other) = default;

        bool Run(std::shared_ptr<IProxy::IProxyTask> task);
        std::function <bool()> GetFunc() const;


        private:

        std::function <bool()> m_task;

    };

}

#endif