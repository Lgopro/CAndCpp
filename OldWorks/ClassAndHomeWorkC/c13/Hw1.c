#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 0
#define FLIP_STRING 1
#define POLINDROM 2
#define HANOI 3
#define MULTIPLICATION_TABLE 4
#define LAST_CHARACTER 5

/*
Description: Flip the string.
Input: String and length of string.
Output:void.
Complexity: o(n).
*/
void rek(char _arr[],int _n);
/*
Description: Check if the string is polindrom.
Input: String and length of the string.
Output:return 1 of the string is polindrom and 0 if its not.
Complexity: o(n).
*/
int polindrom(char _arr[],int _n);
/*
Description: Finds the last character in the string.
Input: String .
Output: The last character in the string.
Complexity: o(n).
*/
char Last(char _arr[]);
/*
Description: Prints multiplication table up to the selected number.
Input: The selected number and amount of lines and columns.
Output: void.
Complexity: o(n).
*/
void Kefel(int _i,int _j,int _num);
/*
Description: Prints The menu.
Input: Void.
Output: The selected number from the menu.
Complexity: o(1).
*/
int PrintMenu(void);
/*
Description: Moves all variables from pyramid a to pyramid c using pyramid b.
Input: Void.
Output: The needed moves to move all variebles.
Complexity: o(n^2).
*/
void Hanoi(int _num,char _a,char _c, char _b);

int main()
{
	int choise,num;
	char ch,str[100];
	do
	{
		choise=PrintMenu();
		switch(choise)
		{	
		case FLIP_STRING:
			printf("Please enter a string:\n");
			fgets(str,100,stdin);
			rek(str,strlen(str)-1);
			printf("The string after the flip is: %s\n",str);
		break;
		
		case POLINDROM:
			printf("Please enter a string:\n");
			fgets(str,100,stdin);
			num=polindrom(str,strlen(str)-2);
			if(num == 0)
			{
				printf("The string is not a polindrom\n");
			}
			if(num == 1)
			{
				printf("The string is a polindrom\n");
			}
		break;
		case HANOI:
		do
		{
			printf("Please enter the number of the disks\n");
			scanf("%d", &num);
			Hanoi(num,'a','b','c');
		}while(num<0);
		break;
		
		case MULTIPLICATION_TABLE:
			printf("Please enter the number you want to make a multiplication table to:\n");
			scanf("%d", &num);
			Kefel(1,1,num);
		break;
		case LAST_CHARACTER:
			printf("Please enter a string:\n");
			fgets(str,100,stdin);
			ch=Last(str);
			printf("The last character of the string is: %c\n", ch);
		break;
		}
	}while(choise!=EXIT);
	return 0;
}
void rek(char _arr[],int _n)
{
	int num;
	if(_n<=0)
	{
		return;
	}
	num=_arr[_n];
	_arr[_n]=_arr[0];
	_arr[0]=num;
	rek(_arr+1,_n-2);
	return;
}


void Hanoi(int _num,char _a,char _c, char _b)
{
	if(_num==0)
	{
		return;
	}
	Hanoi(_num-1,_a,_b,_c);
	printf("Moving disc %d from %c to %c\n", _num,_a,_c);
	Hanoi(_num-1,_b,_c,_a);
	return;
}

int polindrom(char _arr[],int _n)
{
	int num;
	if(_n<=0)
	{
		return 1;
	}
	if(_arr[_n]!=_arr[0])
	return 0;
	if(_arr[_n]==_arr[0])
	num=polindrom(_arr+1,_n-2);
	if(num==1)
	return 1;
	if(num==0)
	return 0;
	
	return 0;
}

char Last(char _arr[])
{
	char ch;
	if(_arr[1]=='\n')
	{
		return _arr[0];
	}
	ch=Last(_arr+1);
	return ch;
}

void Kefel(int _i,int _j,int _num)
{
	if(_j>_num)
	{
		return;
	}
	if(_i>_num)
	{
		printf("\n");
		Kefel(1,_j+1,_num);
		return;
	}
	printf("%5d", _i*_j);
	Kefel(_i+1,_j,_num);
	return;

}

int PrintMenu(void)
{
	int num;
	do
	{
    	printf("Please enter one of the folloing options\n");
    	printf("1)Flip the string\n");
    	printf("2)Check if string is polindrom\n");
    	printf("3)The Hanoi\n");
    	printf("4)Create multiplication table\n");
    	printf("5)Check the value of last character in the string\n");
    	printf("Please enter %d to exit\n", EXIT);
    	scanf("%d", &num);
    	getchar();
	}while(num<0 || num>5);
	return num;

}





