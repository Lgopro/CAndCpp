

#ifndef __PUMP_HPP__
#define __PUMP_HPP__


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

        enum WorkingPump
        {
            FIRSTPUMP = 1,
            SECONDPUMP = 2
        };

        Pumps(size_t pause_before_change_pump = 2, size_t timer_before_alarm_sensor = 2, 
              size_t time_in_sec_to_work_pump = 10);

        ~Pumps();

        class Timer 
        {
            public:
                Timer();
                ~Timer() = default;
                Timer(const Timer& other) = default;
                Timer& operator=(const Timer& other) = default;

                void ResetTime();
                double WorkTime();

            private:

                std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;
        };

        class Pump
        {
            public:
            Pump(size_t work_before_change_pump = 5,  size_t timer_before_alarm_sensor = 2, size_t pump_number = 0);
            ~Pump();
            Pump(const Pump& other) = default;
            Pump& operator=(const Pump& other) = default;

            void TurnOn();
            void TurnOff();
            void TurnOnAlarm();
            void TurnOffAlarm();
            void AddToTimeStruct();
            bool CheckAlarmStatus();
            void RunPump();
            void SetPumpNumber(size_t number);
            void SetPumpWorkTime(size_t work_time);
            void SetAlarmTimer(size_t alarm_timer);
            size_t GetPumpNumber() const;
            
            private:

            bool m_turn_on_pump = false;
            bool m_alarm_pump = false;

            TimeStruct total_time_pump_struct;
            Timer m_pump_timer;

            size_t m_work_before_change_pump;
            size_t m_timer_before_alarm_sensor;
            size_t m_pump_number;
        };

        void Run();
        void PauseBeforeNextPump();
        void Stop();
        uint32_t GetSysTicks();
        TimeStruct TotalPumpWorkingTime();
        Pump *GetPumps();

        private:

        Pumps(const Pumps& other) = default;
        Pumps& operator=(const Pumps& other) = default;

        bool m_sensor11_open = false;
        bool m_sensor14_open = false;
        bool m_run_first_time = true;
        bool m_stop_flag = false;

        size_t m_pause_before_change_pump;
        size_t m_timer_before_alarm_sensor;
        size_t m_time_in_sec_to_work_pump;

        TimeStruct m_total_time_struct;
        Timer m_total_timer;

        Pump m_two_pumps[2];
    };
}

#endif /*__PUMP_HPP__*/