/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 16/05/2023
*/
#include <time.h> /* time_t*/
#include <ifaddrs.h> /* strcut ifaddrs */
#include <string.h> /*srcpy*/
#include <assert.h> /*assert*/
#include <sys/types.h> /*getpid*/
#include <unistd.h> /*getpid*/
#include <pthread.h> /*pthread_mutex_t*/


#include "uid.h"

const ilrd_uid_t UIDBadUID = {0};
pthread_mutex_t mutex;

ilrd_uid_t UIDCreate(void)
{
	
	
	static size_t new_counter = 1;
	ilrd_uid_t new = {0};
	struct ifaddrs *ifa, *ifap;
    struct sockaddr_in *sa = NULL;
	char *addr;
	
	
    if(0 != getifaddrs(&ifap))
    {
    	return UIDBadUID;
    }
    
    ifa = ifap;
    
    
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family==AF_INET) 
        {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
        }
    }
    
    addr = inet_ntoa(sa->sin_addr);
          
    new.pid = getpid();
    new.time = time(NULL);

    pthread_mutex_lock(&mutex);
    new.counter = new_counter;
    ++new_counter;
    pthread_mutex_unlock(&mutex);

    strcpy(new.ip, addr);
    
    freeifaddrs(ifap);
    
    

   	return new;
}


int UIDIsSame(ilrd_uid_t id1, ilrd_uid_t id2)
{
	assert(NULL != id1.ip);
	assert(NULL != id2.ip);
	
	return (id1.pid == id2.pid && id1.time == id2.time && id1.counter 
			== id2.counter && (0 ==  strcmp(id1.ip, id2.ip)));

}
