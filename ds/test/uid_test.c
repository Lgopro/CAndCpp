/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date:16/05/2023
*/

#include <stdio.h> /*printf*/
#include <time.h> /*sleep*/
#include<unistd.h> /*sleep*/



#include "uid.h"

void Print(ilrd_uid_t var);
void UIDCreateTest();

int main()
{	
	UIDCreateTest();
	return 0;
}




void UIDCreateTest()
{
	ilrd_uid_t var1 = {0};
	ilrd_uid_t var = {0};
	
	
	var = UIDCreate();
	sleep(5);
	var1 = UIDCreate();
	Print(var);
	
	Print(var1);
	
	if(0 == UIDIsSame(var, var1) && 1 == UIDIsSame(var, var))
	{
		printf("All pass\n");
	}
	else
	{
		printf("All fail\n");
	}

}



void Print(ilrd_uid_t var)
{
    struct tm* curr_time;
  
    curr_time = localtime(&var.time);
	printf("pid is: %d\n", var.pid);
	printf("counter is: %ld\n", var.counter);
	printf("%02d:%02d:%02d\n", curr_time->tm_hour, curr_time->tm_min,
   			curr_time->tm_sec);
	printf("pip is: %s\n", var.ip);
	printf("*****************\n");
}
