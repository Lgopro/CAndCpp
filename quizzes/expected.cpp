

#include <iostream>
#include <string>

namespace ilrd
{

    template <typename TRUE, typename ERROR>
    class Expected
    {
    public:
        Expected(TRUE val);
        Expected(ERROR err);
        ~Expected() = default;
        Expected(const Expected &other) = default;
        Expected& operator=(const Expected &other) = default;

        ERROR GetError() const;
        TRUE GetValue() const;
        bool HasValue() const;

    private:
        TRUE m_val;
        ERROR m_err;
        bool m_has_value;
    };

}

using namespace ilrd;

template <typename TRUE, typename ERROR>
Expected<TRUE, ERROR>::Expected(ERROR err) : m_err(err), m_has_value(false)
{
}

template <typename TRUE, typename ERROR>
Expected<TRUE, ERROR>::Expected(TRUE val) : m_val(val), m_has_value(true)
{
}

template <typename TRUE, typename ERROR>
ERROR Expected<TRUE, ERROR>::GetError() const
{
    return m_err;
}

template <typename TRUE, typename ERROR>
TRUE Expected<TRUE, ERROR>::GetValue() const
{
    return m_val;
}

template <typename TRUE, typename ERROR>
bool Expected<TRUE, ERROR>::HasValue() const
{
    return m_has_value;
}

Expected<double, std::string> Devide(double numerator, double denominator)
{
    if (denominator == 0)
    {
        Expected<double, std::string> ret("denominator can't be  0");
        return ret;
    }
    Expected<double, std::string> ret(numerator / denominator);
    return ret;
}

int main()
{
    // Example a - prints “2.5”:
    Expected<double, std::string> result = Devide(5, 2);
    if (result.HasValue())
    {
        std::cout << result.GetValue() << std::endl;
    }
    else
    {
        std::cout << result.GetError() << std::endl;
    }

    // Example b - prints “denominator can't be  0”:
    result = Devide(5, 0);
    if (result.HasValue())
    {
        std::cout << result.GetValue() << std::endl;
    }
    else
    {
        std::cout << result.GetError() << std::endl;
    }
}
