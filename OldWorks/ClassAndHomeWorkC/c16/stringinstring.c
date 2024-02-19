#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WRONG -1
/*
Description: Check if string 2 located somewhere in string 1.
Input: String 1 and string 2.
Output: -1 if nothing found and a number of the character in string 1 that string 2 is starting from.
Complexity: o(n).
*/
int Location(char _str1[],char _str2[]);

int main()
{
	char str1[100],str2[100];
	int location;
	
	
		printf("Please enter the string you want to search in\n");
		fgets(str1,100,stdin);
		printf("Please enter characters you want to delete in string\n");
		fgets(str2,100,stdin);
		location=Location(str1,str2);
		printf("The location is: %d\n", location);
	
	return 0;
}



int Location(char _str1[],char _str2[])
{
	int i,k;
	if(NULL == _str1 || NULL == _str2)
	{
		return WRONG;
	}
	if(strlen(_str1) < strlen(_str2))
	{
		return WRONG;
	}
	for(i=0;i<strlen(_str1);i++)
	{
		if(_str1[i] == _str2[0])
		{
			for(k=0;k<strlen(_str2);k++)
			{
				if(k==strlen(_str2)-1)
				{
					return i;	
				}
				if(_str2[k] == _str1[i+k])
				{
					continue;
				}
				else
				{
					break;	
				}
			}
		}
	}
	return WRONG;
}




