/*
Rev: Liran Tzuman.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/

#ifndef __ILRD_WATCHDOG__
#define __ILRD_WATCHDOG__

#include <stddef.h>

enum
{
	SUCCESS_WATCH, 
	FAILED_TO_CREATE_CHILD_PROCESS = -1,
	FAILED_TO_CREATE_WATCHDOG = 1
};

/*
Name: WDStart
Description: 
Start a watchdog to protect a section of code.
Arguments:
exe_path - path to an executable file
Return: status
Time complexity: O(1)
Space complexity: O(1)  
*/ 

int WDStart(char **path);

/*
Name: WDStop
Description: 
Stop the watchdog
Arguments:
timeout - max time to wait for graceful exit 
Return: none
Time complexity: O(1)
Space complexity: O(1)  
*/

void WDStop(size_t timeout);

#endif /* __ILRD_WATCHDOG__*/
