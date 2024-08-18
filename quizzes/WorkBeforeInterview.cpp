#include <iostream>
#include <semaphore.h>
#include <condition_variable>
#include <thread>

bool IsPowerOfTwoIter(unsigned int value)
{
    int counter = 0;
    for(int i = 31; i >= 0; --i)
    {
        if(value & 1 << i)
        {
            ++counter;
        }
    }
    if(counter == 1)
    {
        return true;
    }
    return false;
}

bool IsPowerOfTwoNotIter(unsigned int value)
{
    int counter = 0;
    while(value & (value - 1) != 0)
    {
        value = value & (value - 1);
        ++counter;
    }
    if(counter == 0)
    {
        return true;
    }
    return false;
}

unsigned int AddOne(unsigned int number)
{
    for(int i = 0; i < 32; ++i)
    {
        if(number & 1 << i)
        {
            number ^= 1 << i;
        }
        else
        {
            number ^= 1 << i;
            break;
        }
    }
    return number;
}


bool TwoAndSixBit(unsigned char value)
{
    return (((int)value & 1 << 1) && ((int)value & 1 << 5));
}

std::mutex mtx;
std::condition_variable condition;
bool flag = false;

void ConditionVariable()
{
    std::unique_lock<std::mutex> lock(mtx);
    condition.wait(lock, [&]{return flag;});
    std::cout << "Release" << std::endl;
}

void Release()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    flag = true;
    condition.notify_one();
}

int main()
{
    bool result = IsPowerOfTwoIter(1);
    if(result == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result1 = IsPowerOfTwoIter(2);
    if(result1 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result2 = IsPowerOfTwoIter(32);
    if(result1 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result3 = IsPowerOfTwoIter(31);
    if(result3 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }



    bool result4 = IsPowerOfTwoNotIter(1);
    if(result4 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result5 = IsPowerOfTwoNotIter(2);
    if(result5 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result6 = IsPowerOfTwoNotIter(32);
    if(result6 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result7 = IsPowerOfTwoNotIter(31);
    if(result7 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    

    std::cout << AddOne(31) << std::endl;
    std::cout << AddOne(32) << std::endl;


    bool result8 = TwoAndSixBit((unsigned char)127);
    if(result8 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    bool result9 = TwoAndSixBit((unsigned char)32);
    if(result9 == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }


    std::thread t1(ConditionVariable);
    std::thread t2(Release);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    t1.join();
    t2.join();


    return 0;
}

