/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date:16/05/2023
*/

/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 16/05/2023
*/
#ifndef __UID_H__
#define __UID_H__


#include <time.h> /* time_t*/
#include <arpa/inet.h> /* pid_t*/


typedef struct UID ilrd_uid_t;

extern const ilrd_uid_t UIDBadUID;

struct UID
{
	pid_t pid;
	time_t time;
	size_t counter;
	char ip[16];
};

/***********************************************************************/
/*
Description: Create a uid event.
Arguments: Void.
Return: uid.
Time complexity: O(n).
Space complexity: O(1).
*/
ilrd_uid_t UIDCreate(void);

/***********************************************************************/
/*
Description: Check if both uid's are the same.
Arguments: Two uid's.
Return: 1 on Success and 0 on fail.
Time complexity: O(1).
Space complexity: O(1).
*/
int UIDIsSame(ilrd_uid_t id1, ilrd_uid_t id2);

#endif /* __UID_H__ */
