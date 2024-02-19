#include <stdio.h>
#include <unistd.h>
#include "Time.h"
#include "task.h" 
#include "taskExcutor.h" 
#include "mu_test.h"

int task1(void* _context)
{
    if(*(int*)_context > 0)
    {
        printf("Context task1 is: %d \n", *(int*)_context);
        --*(int*)_context;
        return 1;
    }
    return 0;
}
int task2(void* _context)
{
    if(*(int*)_context > 0)
    {
        printf("Context task2 is: %d \n", *(int*)_context);
        --*(int*)_context;
        return 1;
    }
    return 0;
}
int task3(void* _context)
{
    if(*(int*)_context > 0)
    {
        printf("Context task1 is: %d \n", *(int*)_context);
        --*(int*)_context;
        return 1;
    }
    return 0;
}
int task4(void* _context)
{
    if(*(int*)_context > 0)
    {
        printf("Context task1 is: %d \n", *(int*)_context);
        --*(int*)_context;
        return 1;
    }
    return 0;
}
int task5(void* _context)
{
    if(*(int*)_context > 0)
    {
        printf("Context task1 is: %d \n", *(int*)_context);
        --*(int*)_context;
        return 1;
    }
    return 0;
}
UNIT(Time_Convert_Check)
    double x = 2.568452;
    TaskTime time;
	time = Time_Convert(x);
	ASSERT_THAT(time.tv_sec == 2);
	ASSERT_THAT(time.tv_nsec == 568452000);
END_UNIT

UNIT(Time_Add_Check)
    double x = 2.568452;
    TaskTime time, time2, time3;
    time = Time_Convert(x);
	time2 = Time_Add(&time);
	ASSERT_THAT(time.tv_sec != time2.tv_sec);
	ASSERT_THAT(time.tv_nsec != time2.tv_nsec);
    sleep(1);
    time3 = Time_Add(&time);
	ASSERT_THAT(time3.tv_sec != time2.tv_sec);
	ASSERT_THAT(time3.tv_nsec != time2.tv_nsec);
END_UNIT


UNIT(Time_Is_Less_Check)
    double x = 2.568452;
    TaskTime time, time2, time3;
    time = Time_Convert(x);
	time2 = Time_Add(&time);
	ASSERT_THAT(Time_Is_Less(&time2,&time));
    ASSERT_THAT(!Time_Is_Less(&time,&time2));
    sleep(1);
    time3 = Time_Add(&time);
	ASSERT_THAT(!Time_Is_Less(&time2,&time3));
    ASSERT_THAT(Time_Is_Less(&time3,&time2));
END_UNIT


UNIT(Time_SleepUntil_Check)
    double x = 1;
    TaskTime time, time2;
    time = Time_Convert(x);
    time2 = Time_Add(&time);
    Time_SleepUntil(time2);
    Time_SleepUntil(time2);
END_UNIT

UNIT(Task_Create_Check)
    int random=1;
    Task* check;
    ASSERT_THAT(Task_Create(NULL , NULL, 5) == NULL);
    check = Task_Create(task1 , (void*)&random, 5);
    ASSERT_THAT(check != NULL);

END_UNIT


UNIT(Task_Destroy_Check)
    int random=1;
    Task* check;
    ASSERT_THAT(Task_Create(NULL , NULL, 5) == NULL);
    check = Task_Create(task1 , (void*)&random, 5);
    ASSERT_THAT(check != NULL);
    Task_Destroy(check);

END_UNIT

UNIT(Task_Less_Check)
    int random=1;
    Task* check;
    Task* check1;
    check = Task_Create(task1 , (void*)&random, 6.5);
    ASSERT_THAT(check != NULL);
    check1 = Task_Create(task1 , (void*)&random, 5);
    ASSERT_THAT(check != NULL);
    ASSERT_THAT(Task_Less(check, check1) == 1);
    ASSERT_THAT(Task_Less(check1, check) == 0);
    Task_Destroy(check);
    Task_Destroy(check1);
END_UNIT

UNIT(Task_Run_Check)
    int random=1;
    Task* check;
  
    check = Task_Create(task1 , (void*)&random, 2);
    ASSERT_THAT(check != NULL);
    ASSERT_THAT(Task_Run(check));
    Task_Destroy(check);
END_UNIT

UNIT(Exec_Create_Check)
    Executer* check;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
END_UNIT

UNIT(Exec_Destroy_Check)
    Executer* check;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
    Executer_Destroy(check);

END_UNIT



UNIT(Exec_Add_Task_Once_Check)
    Executer* check;
    int try=10;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
    Executer_AddTask(check , task1 , (void*)&try, 5);
    Executer_Destroy(check);

END_UNIT

UNIT(Exec_Multiple_Add_Task_Once_Check)
    Executer* check;
    int insert=10,insert1=11,insert2=6,insert3=2,insert4=100;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
    Executer_AddTask(check , task1 , (void*)&insert, 5);
    Executer_AddTask(check , task1 , (void*)&insert1, 5);
    Executer_AddTask(check , task1 , (void*)&insert2, 5);
    Executer_AddTask(check , task1 , (void*)&insert3, 5);
    Executer_AddTask(check , task1 , (void*)&insert4, 5);
    Executer_Destroy(check);

END_UNIT

UNIT(Exec_Run_Check)
    Executer* check;
    int insert=3 ,insert1=5,insert2=6,insert3=2,insert4=5;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
    Executer_AddTask(check , task1 , (void*)&insert, 0.5);
    Executer_AddTask(check , task2 , (void*)&insert1, 1.5);
    Executer_AddTask(check , task1 , (void*)&insert2, 0.2);
    Executer_AddTask(check , task1 , (void*)&insert3, 0.4);
    Executer_AddTask(check , task1 , (void*)&insert4, 0.3); 
    Executer_Run(check);
    Executer_Destroy(check);

END_UNIT

UNIT(Exec_Pause_Check)
    Executer* check;
    ErrResult_Executer status;
    check = Executer_Create();
    ASSERT_THAT(check != NULL);
    status = Executer_Pause(NULL);
    ASSERT_THAT(status == EXECUTER_NOT_INITIALIZED);
    status = Executer_Pause(check);
    ASSERT_THAT(status == EXECUTER_SUCCESS);
    Executer_Destroy(check);

END_UNIT


TEST_SUITE(string vector test)

	TEST(Time_Convert_Check)
	TEST(Time_Add_Check)
	TEST(Time_Is_Less_Check)
	TEST(Time_SleepUntil_Check)
    TEST(Task_Create_Check)
    TEST(Task_Destroy_Check)
    TEST(Task_Less_Check)
    TEST(Task_Run_Check)
    TEST(Exec_Create_Check)
    TEST(Exec_Destroy_Check)
    TEST(Exec_Add_Task_Once_Check)
    TEST(Exec_Multiple_Add_Task_Once_Check)
    TEST(Exec_Pause_Check)
    TEST(Exec_Run_Check)
END_SUITE

