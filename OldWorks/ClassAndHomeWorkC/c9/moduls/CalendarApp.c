#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calendar.h"



int main()
{
 	float hour;
 	struct AD* newAD=NULL;
    struct meeting** m_day=NULL;
    struct meeting* newMeet = NULL; 
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
        	newMeet=AddMet(newAD);
        break;
        case INSERT_APOITMENT_INTO_AD:
        	
        	InsertMeeting(newAD,newMeet);
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
        case STORE_AD:
        	if(newAD==NULL)
        	{
        		printf("There is nothing to store. Please create AD first\n");
        	}
        	else
        	{
        		GetFileName(newAD);
        	}
        break;
        case LOAD_AD:
        	if(newAD==NULL)
        	{
        		newAD=FileName();
        	}
        	else
        	{
        		printf("Please destroy the existing AD first\n");
        	}
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
       printf("9)Load AD from file\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>9);
    return num;
}
