#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define EXIT	0
#define SELECT_ARR_SIZE	1
#define SELECT_FACTORIAL	2
#define SELECT_PALNDROM	3
#define SELECT_ACSND		4
#define SELECT_NEW_OPTION	5	4
#define LAST_CHOSE		6


void GetArr(int _num);
int NumToArray(long long int _num);
int BdikatPolindrom(int _maarah[], int _mispar);
int BdikatPolindrom(int _maarah[], int _mispar);
int BdikatNumber(long long int _num,int _mesima);



int GetUserSelectionFromMenu(void)
{
    int userSelection=1;
    int  i=0;
    
 
   	printf("Please choose:\n");
    	printf("%d)print value and size:\n", i);
    	printf("%d)Azeret\n", ++i);
    	printf("%d)Palindrome\n",++i);
    	printf("%d)growing digets\n");
    	printf("%d)NewOption\n");
    	printf("0)Exit\n");
    	scanf("%d",&userSelection);
 
    
    
}

/*
* Description: Get the task input from user and send him to other function.
* Input: number of task from menu.
* Return: number of task from menu.
* output: send the user to other functions depending on num.
*/
void ChooseMission(int _num)
{

	if(_num==1)
	{
		Array(_num);
		return _num;
	}
	if(_num==2)
	{
		Azeret(_num);
		return _num;
	}
	if(_num==3)
	{
		NumToArray(_num);
		return _num;
	}
	if(_num==4)
	{
		NumToArray(_num);
		return _num;
	}

	printf("Bad choise. Try again...\n");
	return;

}

void FloatArray(int _num)
{
    int i,num;
    float array[1000];
    num=_num;
    for(i=0;i<num;i++)
    {
    printf("Please enter the %d element of the array: ", i+1);
 	scanf("%f", &array[i]);
    }
    printf("The elements of the float array are: ");
     for(i=0;i<num;i++)
     {
         if(i==num-1)
         {
        printf("%f.", array[i]);
         }
         else
         {
        printf("%f, ", array[i]);
         }
     }
    printf("\nThe float maarah size is: %ld\n", sizeof(float)*num);
}

/*
* Description: Checks whats type of array the user want.
* Input: number according to menu in function.
* Return: nothing.
* output: Prints the options for printing arrays.
*/
void Array(int _num)
{
    int num;
    printf("Please choose the type of the array:\n");
    printf("1)Integer array\n");
    printf("2)Char array\n");
    printf("3)Float array\n");
    scanf("%d", &num);
    while(num<1 || num>3)
        {
    printf("Wrong input.. please try again.\n");
    printf("Please choose the type of the array:\n");
    printf("1)Integer array\n");
    printf("2)Char array\n");
    printf("3)Float array\n");
    scanf("%d", &num);
        }
    GetArr(num);
}
/*
* Description: Checks whats type of array the user want.
* Input: number according to menu in function.
* Return: nothing.
* output: Prints the options for printing arrays.
*/
void PrintfintArray(int _maarah[],int _mispar)
{
    int i,num;
    printf("Then integer maarah values are: ");
    for(i=0;i<_mispar;i++)
        {
    if(i==_mispar-1)
    {
     printf("%d.", _maarah[i]);
    }
    else
        {
        printf("%d, ", _maarah[i]);
        }
        }
        num=_mispar*sizeof(int);
    printf("\nThe integer maarah size is: %d bytes\n",sizeof(int);
}




void GetArr(int _num)
{
    char arr[1000];
    int i,num;
    long long int number;
    float array[1000];
    if(_num==1)
    {
    printf("Please enter the integer array:\n");
    scanf("%I64lld", &number);
    NumToArray(number);
    }
    if(_num==2)
    {
    printf("Please enter the char array\n");
    getchar();
    fgets(arr, 1000, stdin);
    printf("The value of elements in the array is: ");
     for(i=0;arr[i+1]!='\0';i++)
        {
            
          printf("%c, ", arr[i]);
            
        }
    printf("\nThe char maarah size is: %ld bytes\n", sizeof(char)*strlen(arr));
    }
    if(_num==3)
    {
    printf("Please enter the number of float elements in the array\n");
    scanf("%d", &num);
    FloatArray(num);
    }
}
/*
* Description: Checks if the array is ascending or not.
* Input: array and his length.
* Return: 0 if not ascending and 1 if ascending.
* output: Prints if array ascends or not.
*/
int Ascending(int maarah[],int mispar)
{
    int i,good=0,notgood=0;
    for(i=0;i<mispar-1;i++)
        {
    if(maarah[i]<maarah[i+1])
        {
        good=1;
    }
    else
        {
        notgood=1;
    }
    }
    if(notgood==1)
    {
        printf("Not ascending number\n");
        return 0;
    }
    else
        {
        printf("Ascending number\n");
        return 1;
    }
}

/*
* Description: Calculates the !number that was scanned.
* Input: Number.
* Return: nothing.
* output: Calculates the !number and prints the answer.
*/
void Azeret(int _num)
{
    int num,i,azeret=1;
    printf("Print the number you want to find the azeret to:\n");
    scanf("%d", &num);
    for(i=1;i<=num;i++)
    {
    azeret*=i;
    }
    printf("the azeret to the number %d is %d\n", num, azeret);
    return;

}
/*
* Description: Scans number and turn it to array.
* Input: number.
* Return: differents numbers depends on the inputed number in main menu.
* output: array from number.
*/
int NumToArray(long long int _num){
    int i,num,bdika,mispar,ehida;
    long long int num1;
    
    
    int count = 0;
    int num = _num;
    
    while(num/=10)
	{
		count++;
	}
    	
    num = _num;
	do
	{
		arr[count--] = num%10;
	}
    while(num/=10)
    
    
    
    do
        {
            if(_num==3 || _num==4)
            {
    printf("Please enter a number up to 10 digits:\n");
    scanf("%I64lld", &num1);
            }
            if(_num>4)
                {
                    num1=_num;
                }
    if(_num==3 || _num==4)
            {
    mispar=BdikatNumber(num1,0);
    if(mispar>0)
    {
    bdika=1;
    }
    else
    {
    bdika=0;
    }
    }

        else
        {
           mispar=BdikatNumber(num1,1);
           bdika=1;
        }
        }
    while(bdika!=1);
    int maarah[mispar];
    for(i=1;i<=mispar;i++)
    {
        ehida=num1%10;
        num1/=10;
        maarah[mispar-i]=ehida;
    }
    if(_num!=4 && _num!=3)
    {
       PrintfintArray(maarah,mispar);
        return _num;
    }
    if(_num==3)
    {
    num=BdikatPolindrom(maarah,mispar);
    return num;
    }
    if(_num==4)
    {
    num=Ascending(maarah,mispar);
    return num;
    }
}
/*
* Description: Check if array is a polindrom.
* Input: array and number of integers in the array.
* Return: 1 if array is polindrom and 0 if its isnt.
* output: if array is a polindrom or not.
*/

int BdikatPolindrom(int _maarah[], int _mispar)
{
    int i,j,k,x,count=1,f;


    if(_maarah[0]==_maarah[_mispar-1])
    {
    for(k=1;k<_mispar-1;k++)
    {
    if(_maarah[k]==_maarah[_mispar-1-k])
    count++;
    }
    }
    if(count==_mispar-1 || _mispar==1)
    {
    printf("This number is Polindrom\n");
    return 1;
    }
    else
    {
    printf("This number is not Polindrom\n");
    return 0;
    }

}
/*
* Description: Check number of integers in the array.
* Input: number.
* Return: number of integers in the input.
* output: number of integers in the array.
*/

int BdikatNumber(long long int _num,int _mesima)
{
    int i=0,num;
    while(_num!=0)
    {
    num=_num%10;
    _num/=10;
    i++;
    }
    if(_mesima==0)
    {
    if(i>10)
    {
    printf("Wrong input.. Please try again\n");
    return 0;
    }
    else
    {
    return i;
    }
    }
    else
    {
       return i;
    }


}

int main()
{
	int userSelection;
	do
    	{
		 userSelection=GetUserSelectionFromMenu();

 		ChooseMission(userSelection);

    	}
   	 while(userSelection!=0);
}
