
#include "Pump.hpp"

using namespace ilrd;

/***********Pumps functions implementation************/
Pumps::Pumps(size_t pause_before_change_pump, size_t timer_before_alarm_sensor, 
              size_t time_in_sec_to_change_pump):m_pause_before_change_pump(pause_before_change_pump),  
              m_timer_before_alarm_sensor(timer_before_alarm_sensor), 
              m_time_in_sec_to_change_pump(time_in_sec_to_change_pump)
{
    m_total_time_struct.m_seconds = 0;
    m_total_time_struct.m_minutes = 0;
    m_total_time_struct.m_hours = 0;

}

void Pumps::Run()
{
    while(m_stop_flag != true)
    {
        
    }
}
        
void Pumps::PauseBeforeNextPump()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); 
}
        
void Pumps::Stop()
{
    m_stop_flag = true;
}
        
uint32_t Pumps::GetSysTicks()
{
    return m_total_timer.WorkTime();
}
        
Pumps::TimeStruct Pumps::TotalPumpWorkingTime()
{
    return m_total_time_struct;
}


Pumps::~Pumps()
{

}

/***********Timer functions implementation************/
Pumps::Timer::Timer() : m_start_timepoint(std::chrono::high_resolution_clock::now())
{
}

void Pumps::Timer::ResetTime()
{
    m_start_timepoint = std::chrono::high_resolution_clock::now();
}

double Pumps::Timer::WorkTime() const
{
    auto end_timepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_start_timepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(end_timepoint).time_since_epoch().count();
    auto duration = end - start;
    return duration;
}



/***********Pump functions implementation************/
void Pumps::Pump::TurnOn()
{
    m_turn_on_pump = true;
}

void Pumps::Pump::TurnOff()
{
    m_turn_on_pump = false;
}
            
void Pumps::Pump::TurnOnAlarm()
{
    m_alarm_pump = true;
}
            
void Pumps::Pump::TurnOffAlarm()
{
    m_alarm_pump = false;
}
            
void Pumps::Pump::AddToTimeStruct()
{

}
            
bool Pumps::Pump::CheckAlarmStatus()
{
    return m_alarm_pump;
}

Pumps::Pump::Pump(size_t work_before_change_pump):m_work_before_change_pump(work_before_change_pump)
{

}


Pumps::Pump::~Pump()
{

}

void Pumps::Pump::RunPump()
{
    /*write code*/
}

void Pumps::Pump::ThreadFunction(size_t time_in_sec)
{

}
            
