#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTEGER 1
#define FLOAT 2

void IntegerArray(void);
void FloatArray(void);
void UserFloat(void);
void RandFloat(void);
void SortArrayFloat(float _arr[],int _length);
void SumFloatArr(float _arr[], int _length);
void MaxFloatArr(float _arr[],int _length);
void SortArrayInt(int _arr[],int _length);
void SumIntArr(int _arr[], int _length);
void  ScanFun(void);
void UserInt(void);
void RandInt(void);
void IntegerArray(void);

void FloatArray(void)
{
     int input;
    do
    {
        printf("Please enter the type of your input:\n1)User Input.\n2)Random input.\n");
        scanf("%d", &input);

    }
    while(input<1 && input>2);
    if(input==1)
    {
        UserFloat();
    }
    else if(input==2)
    {
       RandFloat();
    }
   return;
}

void UserFloat(void)
{
    float arr[10];
    int i,num;
    printf("How much numbers you want to input?\n");
    scanf("%d", &num);
    printf("Please enter the array input.Up to %d numbers\n", num);
    
    for(i=0;i<num;i++)
    {
        scanf("%f", &arr[i]);
    }
   
    MaxFloatArr(arr, num);
    SumFloatArr(arr, num);
    SortArrayFloat(arr, num);
    return;
}

void RandFloat(void)
{
    float arr[10],r;
    int i,seed,num;
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    srand(seed);
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    for(i=0;i<num;i++)
    {
       r=rand()*1.1/1000;
       arr[i]=r;
    }

   MaxFloatArr(arr, num);
    SumFloatArr(arr, num);
    SortArrayFloat(arr, num);
    return;
}

void SortArrayFloat(float _arr[],int _length)
{
    int i,j;
    float num;
    for(i=0;i<_length-1;i++)
    {
        for(j=i+1;j<_length;j++)
        {
            if(_arr[i]>_arr[j])
            {
               num=_arr[j];
               _arr[j]=_arr[i];
               _arr[i]=num;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<_length;i++)
    {
        printf("%f ", _arr[i]);
    }
    printf("\n");
    return;
}
void SumFloatArr(float _arr[], int _length)
{
    int i;
    float sum=0;
    for(i=0;i<_length;i++)
    {
        sum+=_arr[i];
    }
    printf("The sum of the string is: %f\n", sum);
    return;
}
void MaxFloatArr(float _arr[],int _length)
{
    int i;
    float maxnum;
    maxnum=_arr[0];
    for(i=1;i<_length;i++)
    {
        if(_arr[i]>maxnum)
        {
            maxnum=_arr[i];
        }

    }
    printf("The maximum number in the array is: %f\n", maxnum);
    return;
}


void SortArrayInt(int _arr[],int _length)
{
    int i,j,num;
    for(i=0;i<_length-1;i++)
    {
        for(j=i+1;j<_length;j++)
        {
            if(_arr[i]>_arr[j])
            {
               num=_arr[j];
               _arr[j]=_arr[i];
               _arr[i]=num;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<_length;i++)
    {
        printf("%d ", _arr[i]);
    }
    printf("\n");
    return;
}
void SumIntArr(int _arr[], int _length)
{
    int i,sum=0;
    for(i=0;i<_length;i++)
    {
        sum+=_arr[i];
    }
    printf("The sum of the string is: %d\n", sum);
    return;
}
void MaxIntArr(int _arr[],int _length)
{
    int i,maxnum;
    maxnum=_arr[0];
    for(i=1;i<_length;i++)
    {
        if(_arr[i]>maxnum)
        {
            maxnum=_arr[i];
        }

    }
    printf("The maximum number in the array is: %d\n", maxnum);
    return;
}

void  ScanFun(void)
{
    int i,arr[100],num;
char ch,sign;
printf("Please enter the array input.Up to 10 numbers:\n");
    i=0;
    num=0;
    sign='+';
    getchar();
    while(scanf("%c",&ch)==1)
    {
        if(ch=='-')
        {
          sign='-';
        }
        else if(ch==' ' || ch=='\n')
{
if(sign=='-')
{
   num=-num;
                    sign='+';
                }
arr[i++] = num;
num=0;
if(ch=='\n')
{
                    break;
}
}
else num = 10*num + (ch-'0');
    }

   if(i<10)
    {
        MaxIntArr(arr, i);
        SumIntArr(arr, i);
        SortArrayInt(arr, i);
    }
    else
    {
        MaxIntArr(arr, 10);
        SumIntArr(arr, 10);
        SortArrayInt(arr, 10);
    }

return;
}


void UserInt(void)
{
    
    

    ScanFun();

    return;
}

void RandInt(void)
{
    int i,arr[10],seed,r,num;
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    srand(seed);


    for(i=0;i<num;i++)
    {
       r=rand()%1000;
       arr[i]=r;
    }

    MaxIntArr(arr, num);
    SumIntArr(arr, num);
    SortArrayInt(arr, num);
    return;
}




void IntegerArray(void)
{
    int input;
    do
    {
        printf("Please enter the type of your input:\n1)User Input.\n2)Random input.\n");
        scanf("%d", &input);

    }
    while(input<1 && input>2);
    if(input==1)
    {
        UserInt();
    }
    else if(input==2)
    {
       RandInt();
    }
   return;

}

int main()
{
    int bhira;
    do
    {
        printf("Please enter what type of array you choose:\nEnter 0 to exit.\n");
        printf("1)Integer\n");
        printf("2)Float\n");
        scanf("%d", &bhira);
        if(bhira==INTEGER)
        {
            IntegerArray();
        }
        else if(bhira==FLOAT)
        {
            FloatArray();
        }
    }
    while(bhira!=0);

    return 0;
}
