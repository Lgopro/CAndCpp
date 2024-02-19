
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>   
#include <sys/resource.h> 
#include <unistd.h>

#include "Time.h"

#define MIC_SEC 1000000
#define NANO_IN_SECS 1000000000
#define TIME_ONE_BIGGER 1
#define TIME_TWO_BIGGER 0


TaskTime Time_Convert(double _interval)
{
    struct timespec time;
    time.tv_sec = (time_t)_interval;
    time.tv_nsec = (long)((_interval- (int)_interval) * (NANO_IN_SECS));
    return time;
}

TaskTime Time_Add(TaskTime* _interval)
{
    struct timespec TimeNow;
    clock_gettime(CLOCK_REALTIME, &TimeNow); 
    TimeNow.tv_sec += _interval->tv_sec;
    TimeNow.tv_nsec += _interval->tv_nsec;
    return TimeNow;

}
int Time_Is_Less(TaskTime* _time1, TaskTime* _time2)
{
    if((_time1->tv_sec > _time2->tv_sec) || (_time1->tv_sec == _time2->tv_sec && _time1->tv_nsec >= _time2->tv_nsec))
    {
        return TIME_ONE_BIGGER;
    }
    return TIME_TWO_BIGGER;
}

TaskTime Time_SleepUntil(TaskTime _next)
{
    
    TaskTime TimeNow;
    double waitUntill,now;

    clock_gettime(CLOCK_REALTIME ,&TimeNow);
    waitUntill = (double)_next.tv_nsec/NANO_IN_SECS + (double)_next.tv_sec;
    now = (double)TimeNow.tv_nsec/NANO_IN_SECS + (double)TimeNow.tv_sec;
    printf("right before sleep:%f %f, seconds to sleep:%f \n", now, waitUntill, waitUntill-now);
    if (now < waitUntill)
    {
        waitUntill = (waitUntill-now)*MIC_SEC;
        usleep((useconds_t)(waitUntill));
    }
    clock_gettime(CLOCK_REALTIME ,&TimeNow);
    return _next;
    

}
