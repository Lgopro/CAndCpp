



#include "Pump.hpp"
#include <iostream>
#include <thread>

using namespace ilrd;


void Test1()
{
    std::cout<< "Start Test1" <<std::endl;
    Pumps complex(1, 2, 3);
    std::thread t1([&complex]() {
        complex.Run();
    });

    std::this_thread::sleep_for(std::chrono::seconds(10));
    complex.Stop();
    t1.join();
    std::cout<< "End Test1" <<std::endl;
}

void Test1()
{
    std::cout<< "Start Test1" <<std::endl;
    Pumps complex(1, 2, 3);
    std::thread t1([&complex]() {
        complex.Run();
    });
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    std::this_thread::sleep_for(std::chrono::seconds(10));
    complex.Stop();
    t1.join();
    std::cout<< "End Test1" <<std::endl;
}

int main()
{
    Test1();
    
    return 0;
}