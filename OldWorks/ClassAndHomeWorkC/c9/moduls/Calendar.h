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
#define STORE_AD 8
#define LOAD_AD 9
#define DEFAULT_BLOCK_SIZE 2
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
   
struct meeting* AddMet(struct AD* _ad);   
void Swap(struct AD * _ad, int _i,int _j);
struct AD* CreateAD(size_t _initSize, size_t _blockSize);
struct meeting* CreateMet(float _begin, float _end, int _room);
ErrorCode InsertMeeting(struct AD* _ad, struct meeting* _newMeet);
ErrorCode RemoveMeeting(struct AD* _ad,float _beginHour);
void PrintAD(struct AD * _ad);
size_t FindMet(struct AD* _ad, float _begin);
struct AD* DestroyArray(struct AD* _ad);
float GetHour(void);
struct AD* Enter(struct AD* _ad);
int Printmenu(void);
struct meeting** IncreaseADSize(struct meeting* *_m_day,struct AD* _ad );
struct meeting** ReduseADSize(struct meeting* *_m_day,struct AD* _ad );
struct AD* LoadAD(char* _filename);
struct AD* FileName(void);
void GetFileName(struct AD* _ad);
void StoreAd(struct AD* _ad, char* _filename);
