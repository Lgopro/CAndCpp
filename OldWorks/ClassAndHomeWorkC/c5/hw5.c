#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT 0
#define CREATEARRAY 1
#define DESTROYARRAY 2
#define ADDSTUDENT 3
#define REMOVESTUDENT 4
#define PRINTSTUDENT 5
#define PRINTSTUDENTS 6
#define SORTBYID 7

typedef void ErrorCode;
typedef int* id;
typedef int* garade;
/*typedef int* (struct student*);*/
typedef unsigned long long size_t;
unsigned int numberofstudents=0;
unsigned int blocksize=0;
struct student *Arr;
 struct student
   {
        char name[20];
        int id;
        int grade;
   };

/*struct student**/
struct student* CreateArrayOfStudents(size_t _initSize);
void DestroyArrayOfStudents(struct student* _students);
ErrorCode AddStudent(struct student* _students,char* _name,  id _id, garade _grade, size_t _blockSize);
ErrorCode RemoveLastStudent(struct student* _students);
ErrorCode PrintStudent(struct student* _students,id _id);
ErrorCode PrintStudents(struct student* _students);
void SortByID(struct student* _students);
void GetId(void);
void Add(void);
int choosenumber(void);
void choise(int _num);


void SortByID(struct student* _students)
{
    int i,j,id,grade;
    char name[20];
    if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
    for(i=0;i<blocksize;i++)
    {
        for(j=i+1;j<blocksize;j++)
        {
            if(_students[i].id>=_students[j].id)
            {
               id=_students[i].id ;
               grade=_students[i].grade;
               strcpy(name,_students[i].name);
               _students[i]=_students[j];
               _students[j].grade=grade;
               _students[j].id=id;
               strcpy(_students[j].name,name);
            }
        }
    }
    return;
}




ErrorCode PrintStudents(struct student* _students)
{
    int i;
    if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
   if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
    for(i=0;i<=blocksize;i++)
    {
        if(blocksize==0)
        {
            printf("There are no students to choose from\nPlease enter the student data first\n");
            return;
        }
        else
        {
            printf("The ID of the student is: %d\n",_students[i].id);
            printf("The name of the student is: %s\n",_students[i].name);
            printf("The grade of the student is: %d\n",_students[i].grade);
            return;
        }

    }
}



void GetId(void)
{
    int id;
    if(Arr==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
    printf("Please enter an id number please\n");
    scanf("%d", &id);
    getchar();
    PrintStudent(Arr,id);
    return;

}
ErrorCode PrintStudent(struct student* _students,id _id)
{
   int i;
   if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
    for(i=0;i<blocksize;i++)
    {
        if(blocksize==0)
        {
            printf("There are no students to choose from\nPlease enter the student data first\n");
            return;
        }
        else if(_students[i].id==_id)
        {
            printf("The name of the student is: %s\n",_students[i].name);
            printf("The grade of the student is: %d\n",_students[i].grade);
            return;
        }
        else
        {
            printf("Wrong input of id. Please try again\n");
            return;
        }
    }
}



ErrorCode RemoveLastStudent(struct student* _students)
{
   if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
	else if(blocksize==0)
    {
        printf("There is no students to delete\n");
    }
	else
    {
        blocksize--;
        return;
    }

}

void Add(void)
{

        int id,grade;
        char name[20];
        if(Arr==NULL)
        {
            printf("The was a mistake\nPlease create array of students first\n");
            return;
        }
        if(blocksize==numberofstudents)
        {
            printf("Please Create array of students or remove to student to add a new one\n");
            return;
        }
        printf("Please enter your first name please:\n");
        scanf("%s",name);
        getchar();
        printf("Please enter your id please:\n");
        scanf("%d",&id);
        getchar();
        printf("Please enter your grade please:\n");
        scanf("%d",&grade);
        getchar();
        AddStudent(Arr,name,id,grade,blocksize);
        return;


}


ErrorCode AddStudent(struct student* _students,char* _name,  id _id, garade _grade, size_t _blockSize)
{
     if(_students==NULL)
	{
		printf("The was a mistake\nPlease create array of students first\n");
        return;
	}
	_students[_blockSize].id=_id;
	_students[_blockSize].grade=_grade;
	strcpy(_students[_blockSize].name,_name);
	blocksize++;
	return;
}


struct student* CreateArrayOfStudents(size_t _initSize)
{

    if((Arr=(struct student*)malloc(_initSize*sizeof(struct student)))==NULL)
    {
        printf("\nError-no place on disk\n");
        return NULL;
    }
    return Arr;

}

void DestroyArrayOfStudents(struct student* _students)
{
    if(_students==NULL)
	{

		printf("The was a mistake\n");
		printf("Either you dident created a student array or there is other error\n");
        return;
	}
	free(_students);
	return;
}


int choosenumber(void)
{
    unsigned int num;

    printf("Please enter the number of students you want to input:\n");
    scanf("%d", &num);
    getchar();
    numberofstudents=num;
    return num;
}

void choise(int _num)
{
    int* arr;
    int num;
    switch(_num)
    {
        case CREATEARRAY:
           num=choosenumber();
           arr=CreateArrayOfStudents(num);
           break;
        case DESTROYARRAY:
           DestroyArrayOfStudents(Arr);
           break;
        case ADDSTUDENT:
           Add();
           break;
        case REMOVESTUDENT:
           RemoveLastStudent(Arr);
           break;
        case PRINTSTUDENT:
           GetId();
           break;
        case PRINTSTUDENTS:
           PrintStudents(Arr);
           break;
        case SORTBYID:
           SortByID(Arr);
           break;
    }

}


int main()
{
    int num;
   do
   {
       printf("Please enter one of the folloing options\n");
       printf("1)Create array of students\n");
       printf("2)Destroy array of students\n");
       printf("3)Add student\n");
       printf("4)Remove last student\n");
       printf("5)Print student data\n");
       printf("6)Print all students data\n");
       printf("7)Find student by ID\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
       choise(num);
   }
   while(num!=EXIT);
    return 0;
}


