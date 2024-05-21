#ifndef __MOVE_STRING_H__
#define __MOVE_STRING_H__

#include <iostream>
#include <iosfwd>

namespace ilrd
{
    class MoveString
    {
        public:

        MoveString(std::string name = "");
        MoveString(const char* name);
        ~MoveString() = default;

        MoveString(MoveString& other);
        MoveString& operator=(MoveString& other);

        std::string GetString() const;
        void EmptyString();

        private:

        std::string m_name;

    };

    std::ostream& operator<<(std::ostream& out, const MoveString& value);
}


#endif /*__MOVE_STRING_H__*/
