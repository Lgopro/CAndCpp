#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Description: Function deletes the characters of string 1 the selected in string 2.
Input: The two strings.
Output: Void.
Complexity: o(n).
*/
void squeeze(char _str1[],char _str2[]);

int main()
{
	char str1[100],str2[100];
	
	
		printf("Please enter the string you want to delete from\n");
		fgets(str1,100,stdin);
		printf("Please enter characters you want to delete in string\n");
		fgets(str2,100,stdin);
		squeeze(str1,str2);
	
	return 0;
}



void squeeze(char _str1[],char _str2[])
{

	int i,j,k;
	if(NULL == _str1 || NULL == _str2)
	{
		return;
	}
	for(i=0;i<strlen(_str1);i++)
	{
		for(j=0;j<strlen(_str2);j++)
		{
			if(_str1[i] == _str2[j])
			{
				for(k=i;k<strlen(_str1);k++)
				{
					_str1[k]=_str1[k+1];
				
				}
			
			}
		}
		
	}
	
	printf("%s", _str1);
}




