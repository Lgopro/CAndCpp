#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 0
#define CREATE_AD 1
#define CREATE_MEETING 2
#define INSERT_APOITMENT_INTO_AD 3
#define REMOVE_APOITMENT_FROM_AD 4
#define FIND_APOITMENT_IN_AD 5
#define DESTROY_AD 6
#define PRINT_AD 7
#define ERROR_OK  1
#define ERROR_NOT_OK 0
typedef int ErrorCode;
struct AD 
	{
		struct meeting* *m_day;
		size_t m_initSize;
		size_t m_blockSize;
		size_t m_actualSize;
		size_t m_numOfMeetings;
	};

 struct meeting
   {
        float m_begin;
        float m_end;
        int m_room;
   };

struct meeting* *m_day;
struct AD *newAD;


struct AD* CreateAD(size_t _initSize, size_t _blockSize);
struct meeting* CreateMet(float _begin, float _end, int _room);
ErrorCode InsertMeeting(struct AD* _ad, struct meeting* _newMeet);
ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour);
void PrintAD(struct AD * _ad);
size_t FindMet(struct AD* _ad, float _begin);
int DestroyArray(struct AD* _ad);
float GetHour(void);
struct meeting* AddMet(struct AD* _ad);

size_t FindMet(struct AD* _ad, float _begin)
{
	int i;
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return ERROR_NOT_OK;
	}
	else if(_ad->m_numOfMeetings==0)
	{
		printf("The was a mistake\nThere are no meetings\nPlease add a meeting\n");
        return ERROR_NOT_OK;
	}
	else
	{
		for(i=0;i<_ad->m_numOfMeetings;i++)
		{
			if(_ad->m_day[i]->m_begin==_begin)
			{
				printf("The begin time is: %0.2f\n", _ad->m_day[i]->m_begin);
				printf("The begin time is: %0.2f\n", _ad->m_day[i]->m_end);
				printf("The room is: %d\n", _ad->m_day[i]->m_room);
				return ERROR_OK;
			}
		}
		printf("There is no such hour!\nPlease try again..\n");
		return ERROR_NOT_OK;
	
	
	}


}
int DestroyArray(struct AD* _ad)
{
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return ERROR_NOT_OK;
	}
	else 
	{
		free(_ad);
		return ERROR_OK;
	
	}
}


ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour)
{
	int i,j;
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return ERROR_NOT_OK;
	}
	if(_ad->m_numOfMeetings==0)
	{
		printf("The was a mistake\nThere are no meetings\nPlease add a meeting\n");
        return ERROR_NOT_OK;
	}
	for(i=0;i<_ad->m_actualSize;i++)
	{
		if(_ad->m_day[i]->m_begin==_beginHour)
		{
			for(j=i;j<_ad->m_numOfMeetings;j++)
			{
				_ad->m_day[j]->m_begin=_ad->m_day[j+1]->m_begin;
				_ad->m_day[j]->m_end=_ad->m_day[j+1]->m_end;
				_ad->m_day[j]->m_room=_ad->m_day[j+1]->m_room;
			
			}
		}
		
	}
	_ad->m_numOfMeetings--;
	return ERROR_OK;
}

/*----------------------------------------------------*/
void PrintAD(struct AD * _ad)
{
	int i;
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return;
	}
	else if(_ad->m_numOfMeetings==0)
	{
		printf("The was a mistake\nThere are no meetings to print\n");
        return;
	}
	for(i=0;i<_ad->m_numOfMeetings;i++)
	{
		printf("The %d apoitment is:\n", i+1);
		printf("The begin time is: %0.2f\n", _ad->m_day[i]->m_begin);
		printf("The begin time is: %0.2f\n", _ad->m_day[i]->m_end);
		printf("The room is: %d\n", _ad->m_day[i]->m_room);
	
	
	}
	return;

}
/*----------------------------------------------*/

ErrorCode InsertMeeting(struct AD* _ad, struct meeting* _newMeet)
{
	if(_newMeet==NULL)
	{
		printf("The was a mistake\nPlease create a meeting first\n");
        return ERROR_NOT_OK;
	}
	else if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return ERROR_NOT_OK;
	}
	else 
	{
		_ad->m_day[_ad->m_numOfMeetings]->m_begin=_newMeet->m_begin;
		_ad->m_day[_ad->m_numOfMeetings]->m_end=_newMeet->m_end;
		_ad->m_day[_ad->m_numOfMeetings]->m_room=_newMeet->m_room;
		_ad->m_numOfMeetings=_ad->m_numOfMeetings+1;
	}
	return ERROR_OK;

}

/*----------------------------------------------*/
struct meeting* AddMet(struct AD* _ad)
{
	float begin,end;
	int room;
	struct meeting* arr;
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return NULL;
	}
	printf("Please enter start hour of the meeting:\n");
	scanf("%f", &begin);
	printf("Please enter the finish hour of the meeting:\n");
	scanf("%f", &end);
	printf("Please enter the room of the meeting:\n");
	scanf("%d", &room);
	
	arr=CreateMet(begin,end,room);
	return arr;
}

struct meeting* CreateMet(float _begin, float _end, int _room)
{
	struct meeting* meet;
	meet=(struct meeting*)malloc(sizeof(struct meeting)*1);
	if(meet==NULL)
	{
		printf("The was a mistake\nPlease try again\n");
        return NULL;
	}
	meet->m_begin=_begin;
	meet->m_end=_end;
	meet->m_room=_room;
	
	
	return meet;
}

struct AD* Enter(void)
{	
	size_t initsize,blocksize;
	struct AD* arr = NULL;

	printf("Please enter the initual size of the AD:\n");
	scanf("%lu", &initsize);

	printf("Please enter the block size of the AD:\n");
	scanf("%lu", &blocksize);
	arr=CreateAD(initsize,blocksize);
	return arr;
}



/*----------------------------------------------*/

struct AD* CreateAD(size_t _initSize, size_t _blockSize)
{
	struct AD* newAD=NULL;
	struct meeting* *day = NULL;
	
 	if(NULL == (newAD=(struct AD*)malloc(sizeof(struct AD)*1)))
   {
   		printf("The function AD dident created\nPlease try again\n");
   		return NULL;
   }
   newAD->m_initSize = _initSize;
   newAD->m_blockSize = _blockSize;
   newAD->m_actualSize = _initSize;
   newAD->m_numOfMeetings = 0;
   
	day=(struct meeting**)malloc(sizeof(struct meeting*)*newAD->m_initSize);
  	 if(NULL == day)
   {
   		printf("The function meeting dident created\nPlease try again\n");
   		return NULL;
   	
   }
   newAD->m_day = day;
   return newAD;
}
/*----------------------------------------------*/
float GetHour(void)
{
	float hour;
	printf("Please enter a hour of meating:\n");
	scanf("%f",&hour);
	return hour;


}

   void Choise(int _num,  struct AD** _arr)
{
 	float hour;

    switch(_num)
    {
        case CREATE_AD:
           newAD=Enter();
           break;
        case CREATE_MEETING:
        	m_day=AddMet(newAD);
            break;
        case INSERT_APOITMENT_INTO_AD:
        	InsertMeeting(newAD,*m_day);
            break;
        case REMOVE_APOITMENT_FROM_AD:
        	RemoveMeeting(newAD,*m_day->m_begin);
            break;
        case FIND_APOITMENT_IN_AD:
        	hour=GetHour();
        	FindMet(newAD,hour);
            break;
        case DESTROY_AD:
        	DestroyArray(newAD);
        	break;
        case PRINT_AD:
        	PrintAD(newAD);
        	break;
    }

}


int main()
{
    int num;
    struct AD* arr;
   do
   {
       printf("Please enter one of the folloing options\n");
       printf("1)Create AD\n");
       printf("2)Create meeting\n");
       printf("3)Insert apointment into AD\n");
       printf("4)Remove apointment from AD\n");
       printf("5)Find apointment in AD\n");
       printf("6)Destroy AD\n");
       printf("7)Print AD\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       Choise(num, &arr);
   }
   while(num!=EXIT);
    return 0;
}



