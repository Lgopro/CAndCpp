#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
int Checkstr(char _str[]);


int main()
{
 	char str[]="{}";
 	int num;
 	num=Checkstr(str);
 	if(num==0)
 	{
 		printf("Not meuzan\n");
 	}
 	else
 	{
 		printf(" meuzan\n");
 	
 	}
	return 0;
}

	
	
int Checkstr(char _str[])
{
	struct Stack* Stack=NULL;
	int num,i,empty,ch;
	Stack=StackCreate (200,200);
	for(i=0;i<strlen(_str);i++)
	{	
		if(_str[i]=='[' ||  _str[i]=='(' || _str[i]=='{')
		
		{
			ch=_str[i];
			StackPush (Stack, ch);
		}
		
		if(_str[i]==']' ||  _str[i]==')' || _str[i]=='}')
		{
			if(_str[i]==']')
			{
				StackPop (Stack, &num);
				if(num!=(int)'[')
				{
					return 0;
				
				}
			}
			if(_str[i]==')')
			{
				StackPop (Stack, &num);
				if(num!=(int)'(')
				{
					return 0;
				}
			}
			if(_str[i]=='}')
			{
				StackPop (Stack, &num);
				if(num!=(int)'{')
				{
					return 0;
				}
			}
		}
		
	}
	
	
	empty=StackIsEmpty(Stack);
	if(empty==0)
	{
		
		return 0;
	}
	return 1;
}

