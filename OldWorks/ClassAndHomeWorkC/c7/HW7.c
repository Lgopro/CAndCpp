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
#define PRINT_AD_TO_FILE 8
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


void Swap(struct AD * _ad, int _i,int _j);
struct AD* CreateAD(size_t _initSize, size_t _blockSize);
struct meeting** CreateMet(float _begin, float _end, int _room);
ErrorCode InsertMeeting(struct AD* _ad, struct meeting* *_newMeet);
ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour);
void PrintAD(struct AD * _ad);
size_t FindMet(struct AD* _ad, float _begin);
struct AD* DestroyArray(struct AD* _ad);
float GetHour(void);
struct AD* Enter(struct AD* _ad);
int Printmenu(void);
struct meeting** IncreaseADSize(struct meeting* *_m_day,struct AD* _ad );
struct meeting** ReduseADSize(struct meeting* *_m_day,struct AD* _ad );
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
				printf("The end time is: %0.2f\n", _ad->m_day[i]->m_end);
				printf("The room is: %d\n", _ad->m_day[i]->m_room);
				return ERROR_OK;
			}
		}
		printf("There is no such hour!\nPlease try again..\n");
		return ERROR_NOT_OK;
	}
}

struct AD* DestroyArray(struct AD* _ad)
{
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return NULL;
	}
	else 
	{
		free(_ad);
		return NULL;
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
	for(i=0;i<_ad->m_numOfMeetings;i++)
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
		else if((i==_ad->m_numOfMeetings-1) && (_ad->m_day[i]->m_begin==_beginHour))
		{
		_ad->m_numOfMeetings--;
		return ERROR_OK;
		}
	}
	printf("\nThere is no such hour meeting..Please try again\n\n");
	return ERROR_NOT_OK;
}

void Swap(struct AD * _ad, int _i,int _j)
{
	int room;
	float beginh,endh;
	beginh=_ad->m_day[_i]->m_begin;
	endh=_ad->m_day[_i]->m_end;
	room=_ad->m_day[_i]->m_room;
	_ad->m_day[_i]->m_begin=_ad->m_day[_j]->m_begin;
	_ad->m_day[_i]->m_end=_ad->m_day[_j]->m_end;
	_ad->m_day[_i]->m_room=_ad->m_day[_j]->m_room;
	_ad->m_day[_j]->m_begin=beginh;
	_ad->m_day[_j]->m_end=endh;
	_ad->m_day[_j]->m_room=room;
	return;
}

void PrintAD(struct AD * _ad)
{
	int i,j;
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
		for(j=i+1;j<_ad->m_numOfMeetings;j++)
		{
			if(_ad->m_day[i]->m_begin>_ad->m_day[j]->m_begin)
			{
			Swap(_ad,i,j);
			
			}
		}
	}
	for(i=0;i<_ad->m_numOfMeetings;i++)
	{
		printf("The %d apoitment is:\n", i+1);
		printf("The begin time is: %0.2f\n", _ad->m_day[i]->m_begin);
		printf("The end time is: %0.2f\n", _ad->m_day[i]->m_end);
		printf("The room is: %d\n", _ad->m_day[i]->m_room);
	}
	return;
}


ErrorCode InsertMeeting(struct AD* _ad, struct meeting* *_newMeet)
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
	_ad->m_day[_ad->m_numOfMeetings]->m_begin=_newMeet-->m_begin;
	_ad->m_day[_ad->m_numOfMeetings]->m_end=_newMeet-->m_end;
	_ad->m_day[_ad->m_numOfMeetings]->m_room=_newMeet-->m_room;
	_ad->m_numOfMeetings=_ad->m_numOfMeetings+1;
	return ERROR_OK;

}

struct meeting** AddMet(struct AD* _ad)
{
	float begin,end;
	int room,i;
	struct meeting* *arr;
	if(_ad==NULL)
	{
		printf("The was a mistake\nPlease create the AD first\n");
        return NULL;
	}
	do
	{
		printf("Please enter start hour of the meeting:\n");
		scanf("%f", &begin);
	}while(begin<0 || begin>24);
	do
	{
		printf("Please enter the end hour of the meeting:\n");
		scanf("%f", &end);
	}while(end<begin || end>24) ;
	printf("Please enter the room of the meeting:\n");
	scanf("%d", &room);
	for(i=0;i<_ad->m_numOfMeetings;i++)
	{
		if((begin>_ad->m_day[i]->m_begin && begin<=_ad->m_day[i]->m_end) || (end>=_ad->m_day[i]->m_begin && end<_ad->m_day[i]->m_end) || (begin<_ad->m_day[i]->m_begin && end>_ad->m_day[i]->m_end))
		{
			printf("\nThere is no option to add a meeting in this time. Other meeting in progress\n");
			return NULL; 
		}
	}
	arr=CreateMet(begin,end,room);
	return arr;
}

struct meeting** CreateMet(float _begin, float _end, int _room)
{
	struct meeting** meet;
	meet=(struct meeting**)malloc(sizeof(struct meeting*)*1);
	if(meet==NULL)
	{
		printf("The was a mistake\nPlease try again\n");
        return NULL;
	}
	meet-->m_begin=_begin;
	meet-->m_end=_end;
	meet-->m_room=_room;
	return meet;
}

struct AD* Enter(struct AD* _ad)
{	
	size_t initsize,blocksize;
	printf("Please enter the initual size of the AD:\n");
	scanf("%lu", &initsize);

	printf("Please enter the block size of the AD:\n");
	scanf("%lu", &blocksize);
	_ad=CreateAD(initsize,blocksize);
	return _ad;
}


struct AD* CreateAD(size_t _initSize, size_t _blockSize)
{
	struct AD* newAD=NULL;
	struct meeting** day = NULL;
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

float GetHour(void)
{
	float hour;
	do
	{
	printf("Please enter a hour of meeting:\n");
	scanf("%f",&hour);
	}while(hour<0 || hour>24);
	return hour;


}

void PrintAdToFile(struct AD* _ad)
{
	
	int i;
	FILE *fp;
	char name[50];

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
	printf("Please enter the name of the file and add .txt after the name:\n");
	fgets(name,50,stdin);
	fp=fopen(name,"w");
	for(i=0;i<_ad->m_numOfMeetings;i++)
	{
		fprintf(fp,"The %d apoitment is:\n", i+1);
		fprintf(fp,"The begin time is: %0.2f\n", _ad->m_day[i]->m_begin);
		fprintf(fp,"The begin time is: %0.2f\n", _ad->m_day[i]->m_end);
		fprintf(fp,"The room is: %d\n", _ad->m_day[i]->m_room);
	}
	fclose(fp);
	return;
}

struct meeting** IncreaseADSize(struct meeting* *_m_day,struct AD* _ad )
{
	
	_m_day=(struct meeting**)realloc(_m_day, sizeof(struct meeting*)*(_ad->m_initSize+_ad->m_blockSize));
	_ad->m_initSize+=_ad->m_blockSize;
	_ad->m_actualSize=_ad->m_initSize;
	return _m_day;
}
struct meeting** ReduseADSize(struct meeting* *_m_day,struct AD* _ad )
{
	
	_m_day=(struct meeting**)realloc(_m_day, sizeof(struct meeting*)*(_ad->m_initSize-_ad->m_blockSize));
	_ad->m_initSize-=_ad->m_blockSize;
	_ad->m_actualSize=_ad->m_initSize;
	return _m_day;

}

int main()
{
 	float hour;
 	struct AD* newAD=NULL;
    struct meeting* *m_day=NULL;
    int num;
	do
	{
		num=Printmenu();
    switch(num)
    {
        case CREATE_AD:
        	if(NULL != newAD)
        	{
         		printf("The AD already created. you can destroy AD to create a new one.\n\n"); 
        	}
        	else
        	{
           		newAD=Enter(newAD);
           		
        	}
        break;
        case CREATE_MEETING:
        	if(newAD->m_numOfMeetings==newAD->m_actualSize)
        	{
        		m_day=IncreaseADSize(m_day, newAD);
        	}
        	m_day=AddMet(newAD);
        break;
        case INSERT_APOITMENT_INTO_AD:
        	
        	InsertMeeting(newAD,m_day);
        break;
        case REMOVE_APOITMENT_FROM_AD:
        	
        	hour=GetHour();
        	RemoveMeeting(newAD,hour);
        	if(newAD->m_initSize-newAD->m_numOfMeetings>newAD->m_blockSize)
        	{
        		m_day=ReduseADSize(m_day, newAD);
        	}
        break;
        case FIND_APOITMENT_IN_AD:
        	if(newAD==NULL)
        	{
         		printf("\nPlease add an AD first.\n\n"); 
        	}
        	if(newAD->m_numOfMeetings==0)
        	{
        		printf("\nPlease create a meeting first.\n\n"); 
        	}
        	else
        	{
        		hour=GetHour();
        		FindMet(newAD,hour);
        	}
        break;
        case DESTROY_AD:
        	if(newAD==NULL)
        	{
         		printf("\nPlease add an AD first.\n\n"); 
        	}
        	newAD=DestroyArray(newAD);
        break;
        case PRINT_AD:
        	PrintAD(newAD);
        break;
        case PRINT_AD_TO_FILE:
        PrintAdToFile(newAD);
        break;
    }
    }while(num!=EXIT); 
    return 0;
}
int Printmenu(void)
{
   int num;
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
       printf("8)printf AD to file\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>8);
    return num;
}
