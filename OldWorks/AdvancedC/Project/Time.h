#ifndef __TIME_H__
#define __TIME_H__

#include <time.h>  /* clock_gettime, timespec */
/** 
 * @brief Create a task.
 * @author Author Leon Golovko (lgopro06@gmail.com)
 * @see  
 */ 

typedef struct timespec TaskTime;

/* 
 * @brief Convert double into timespec.  
 * @param[in] _interval - The number you want to convert
 * @return TaskTime - on success.
 * */
TaskTime Time_Convert(double _interval);

 /*
 * @brief Add the interval to the current time.  
 * @param[in] _interval - The number you want to add to the current time.
 * @return TaskTime - on success.
 * */
 
TaskTime Time_Add(TaskTime* _interval);

/*
 * @brief Sleeps until the time _next if needed.  
 * @param[in] _next -pointer to the _next timespec.
 * @return TaskTime of next - on success.
 * */
TaskTime Time_SleepUntil(TaskTime _next);

/*
 * @brief Check whitch of the two times in bigger.  
 * @param[in] _time1 -pointer to the time1 timespec.
 * @param[in] _time2 -pointer to the time1 timespec.
 * @return 1 if time1 i bigger or 0 if time 2 is bigger.
 * */
int Time_Is_Less(TaskTime* _time1, TaskTime* _time2);

#endif /*__TIME_H__*/