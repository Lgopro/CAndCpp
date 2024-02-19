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
#define ERROR_OK  0

typedef int ErrorCode;
struct AD 
	{
		struct meeting *m_day;
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

struct meeting *m_day;
struct AD *newAD;

struct AD* CreateAD(size_t _initSize, size_t _blockSize);
struct meeting* CreateMet(float _begin, float _end, int _room);
ErrorCode InsertMeeting(struct AD* _ad, struct meeting* _newMeet);
ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour);
/*PrintAD(struct AD * _ad);*/

ErrorCode InsertMeeting(struct AD* _ad, struct meeting* _newMeet)
{

	return ERROR_OK;

}

ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour)
{

	return ERROR_OK;



}
struct meeting* AddMet(void)
{
	float begin,end;
	int room;
	struct meeting* arr;
	printf("Please enter the initual size of the AD:\n");
	scanf("%f", &begin);
	printf("Please enter the initual size of the AD:\n");
	scanf("%f", &end);
	printf("Please enter the initual size of the AD:\n");
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
/*
	getchar();
	*/
	printf("Please enter the block size of the AD:\n");
	scanf("%lu", &blocksize);
	/*getchar();*/
	arr=CreateAD(initsize,blocksize);
	return arr;
}


/*{
	printf("Please enter the initual size of the struct please\n");
	scanf("%lu", 


}*/


struct AD* CreateAD(size_t _initSize, size_t _blockSize)
{
	struct AD* newAD=NULL;
	struct meeting* day = NULL;
	
 	if(NULL == (newAD=(struct AD*)malloc(sizeof(struct AD)*1)))
   {
   		printf("The function AD dident created\nPlease try again\n");
   		return NULL;
   }
   newAD->m_initSize = _initSize;
   newAD->m_blockSize = _blockSize;
   newAD->m_actualSize = _initSize;
   newAD->m_numOfMeetings = 0;
   
	day=(struct meeting*)malloc(sizeof(struct meeting)*newAD->m_initSize);
   if(NULL == day)
   {
   		printf("The function meeting dident created\nPlease try again\n");
   		return NULL;
   	
   }
     newAD->m_day = day;
   return newAD;
}

   void Choise(int _num,  struct AD** arr)
{
 

    switch(_num)
    {
        case CREATE_AD:
        	*arr=Enter();
           
           break;
        case CREATE_MEETING:
           
           break;
        case INSERT_APOITMENT_INTO_AD:
          
           break;
        case REMOVE_APOITMENT_FROM_AD:
          
           break;
        case FIND_APOITMENT_IN_AD:
          
           break;
        case DESTROY_AD:
         
           break;
        case PRINT_AD:
           
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
       printf("7)Printf AD\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       /*getchar();*/
       Choise(num, &arr);
   }
   while(num!=EXIT);
    return 0;
}



