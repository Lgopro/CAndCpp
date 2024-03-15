

#ifndef __PUMP_HPP__
#define __PUMP_HPP__

#include <iostream>
#include <chrono> /*chrono*/
#include <thread> /*std::thread*/

namespace ilrd
{
    class Pumps
    {
        public:

        struct TimeStruct
        {
            int16_t m_seconds; //!< Секунды
            int16_t m_minutes; //!< Минуты
            int16_t m_hours; //!< Часы
        };

        enum WorkingTime
        {
            FIRSTPUMP = 1,
            SECONDPUMP = 2
        };

        Pumps(size_t pause_before_change_pump = 1, size_t timer_before_alarm_sensor = 2, 
              size_t time_in_sec_to_change_pump = 10);
        ~Pumps();

        class Timer 
        {
            public:
                Timer();
                ~Timer() = default;

                void ResetTime();
                double WorkTime() const;

            private:

                Timer(const Timer& other) = delete;
                Timer& operator=(const Timer& other) = delete;

                std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;
        };

        class Pump
        {
            public:
            Pump(size_t work_before_change_pump = 10);
            ~Pump();

            void TurnOn();
            void TurnOff();
            void TurnOnAlarm();
            void TurnOffAlarm();
            void AddToTimeStruct();
            bool CheckAlarmStatus();
            void RunPump();

            private:

            Pump(const Pump& other) = delete;
            Pump& operator=(const Pump& other) = delete;

            bool m_turn_on_pump = false;
            bool m_alarm_pump = false;

            TimeStruct total_time_pump_struct;
            size_t m_work_before_change_pump;
            Timer m_timer;

            void ThreadFunction(size_t time_in_sec);
            std::thread m_thread;
        };

        void Run();
        void PauseBeforeNextPump();
        void Stop();
        uint32_t GetSysTicks();
        TimeStruct TotalPumpWorkingTime();

        private:

        Pumps(const Pumps& other) = delete;
        Pumps& operator=(const Pumps& other) = delete;

        bool m_sensor11_open = false;
        bool m_sensor14_open = false;
        bool m_run_first_time = true;
        bool m_stop_flag = false;

        size_t m_pause_before_change_pump;
        size_t m_timer_before_alarm_sensor;
        size_t m_time_in_sec_to_change_pump;

        TimeStruct m_total_time_struct;
        Timer m_total_timer;

        Pump m_two_pumps[2];
    };
}

#endif /*__PUMP_HPP__*/