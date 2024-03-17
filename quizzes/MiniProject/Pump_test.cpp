



#include "Pump.hpp"
#include <iostream>
#include <thread>

using namespace ilrd;


void NormalWorkOfTwoPamps()
{
    std::cout<< "Start Test NormalWorkOfTwoPamps" <<std::endl;
    Pumps complex(1, 2, 3);
    std::thread t1([&complex]() {
        complex.Run();
    });

    std::this_thread::sleep_for(std::chrono::seconds(200));
    complex.Stop();
    t1.join();
}

void OneNotWorkingPump()
{
    std::cout<< "Start Test OneNotWorkingPump" <<std::endl;
    Pumps complex(1, 2, 3);
    Pumps::Pump *pumps = complex.GetPumps();
    std::thread t1([&complex]() {
        complex.Run();
    });
    std::this_thread::sleep_for(std::chrono::seconds(10));
    pumps[0].TurnOnAlarm();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    pumps[0].TurnOffAlarm();
    pumps[1].TurnOnAlarm();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    complex.Stop();
    t1.join();
}

int main()
{

    NormalWorkOfTwoPamps();
    
    /* OneNotWorkingPump(); */
    return 0;

}



