
#include "Pump.hpp"
#include <iostream> /*std::cout*/

using namespace ilrd;

const int MILISECONDS = 1000;
const int PIPE1 = 1;
const int PIPE2 = 2;

/***********Pumps functions implementation************/
Pumps::Pumps(size_t pause_before_change_pump, size_t timer_before_alarm_sensor, size_t time_in_sec_to_work_pump)
    : m_pause_before_change_pump(pause_before_change_pump),
      m_timer_before_alarm_sensor(timer_before_alarm_sensor),
      m_time_in_sec_to_work_pump(time_in_sec_to_work_pump)
{
    m_total_time_struct.m_seconds = 0;
    m_total_time_struct.m_minutes = 0;
    m_total_time_struct.m_hours = 0;

    m_two_pumps[0].SetPumpNumber(PIPE1);
    m_two_pumps[0].SetAlarmTimer(m_timer_before_alarm_sensor);
    m_two_pumps[0].SetPumpWorkTime(m_time_in_sec_to_work_pump);

    m_two_pumps[1].SetPumpNumber(PIPE2);
    m_two_pumps[1].SetAlarmTimer(m_timer_before_alarm_sensor);
    m_two_pumps[1].SetPumpWorkTime(m_time_in_sec_to_work_pump);
}

void Pumps::Run()
{
    WorkingPump next_pump = FIRSTPUMP;
    while(m_stop_flag != true)
    {
        if(m_run_first_time == true)
        {
            m_two_pumps[0].RunPump();
            next_pump = SECONDPUMP;
            m_run_first_time = false;
        }
        else
        {
            if(next_pump == FIRSTPUMP)
            {
                m_two_pumps[0].RunPump();
                next_pump = SECONDPUMP;
            }
            else
            {
                m_two_pumps[1].RunPump();
                next_pump = FIRSTPUMP;
            }
        }
        PauseBeforeNextPump();
    }
}
        
void Pumps::PauseBeforeNextPump()
{
    #ifndef NDEBUG
    std::cout<< "Pausing before next pump for " << m_pause_before_change_pump << " seconds" << std::endl;
    #endif /*NDEBUG*/
    
    std::this_thread::sleep_for(std::chrono::milliseconds(m_pause_before_change_pump * MILISECONDS)); 
    std::cout<< "" << std::endl;
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
    #ifndef NDEBUG
    std::cout<< "Closing pumps" << std::endl;
    #endif /*NDEBUG*/
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
    #ifndef NDEBUG
    std::cout << "Work Time is: " << m_timer.WorkTime() << std::endl;
    #endif /*NDEBUG*/
    /*add time*/
}
            
bool Pumps::Pump::CheckAlarmStatus()
{
    return m_alarm_pump;
}

Pumps::Pump::Pump(size_t work_before_change_pump, size_t timer_before_alarm_sensor, size_t pump_number):m_work_before_change_pump(work_before_change_pump)
                ,m_timer_before_alarm_sensor(timer_before_alarm_sensor), m_pump_number(pump_number)
{

}


Pumps::Pump::~Pump()
{
    #ifndef NDEBUG
    std::cout<< "Closing pump N" << m_pump_number << std::endl;
    #endif /*NDEBUG*/
}

void Pumps::Pump::RunPump()
{
    bool alarm_once = false;
    m_timer.ResetTime();

    #ifndef NDEBUG
    std::cout << "Pumping pump number " << m_pump_number << std::endl;
    #endif /*NDEBUG*/

    while(m_timer.WorkTime() < m_work_before_change_pump * MILISECONDS)
    {
        
        if(CheckAlarmStatus() == true && alarm_once == false)
        {
            alarm_once = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(m_timer_before_alarm_sensor * MILISECONDS));

        }
        if(CheckAlarmStatus() == true && alarm_once == true)
        {
            #ifndef NDEBUG
            std::cout << "Alarm activated! Turning off pipe!" << std::endl;
            #endif /*NDEBUG*/
            break;
        }
    }
    AddToTimeStruct();
}
            
void Pumps::Pump::SetPumpNumber(size_t number)
{
    m_pump_number = number;
}

void Pumps::Pump::SetPumpWorkTime(size_t work_time)
{
    m_work_before_change_pump = work_time;
}

void Pumps::Pump::SetAlarmTimer(size_t alarm_timer)
{
    m_timer_before_alarm_sensor = alarm_timer;
}