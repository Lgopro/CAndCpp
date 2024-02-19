#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
int PostFix(char _str[],int _length);
int count(char _str[],int _length);

int main()
{
 	char str[200];
 	int result;
 	printf("Please enter the action you want to calculate:\n");
 	fgets(str,200,stdin);
 	result=PostFix(str,strlen(str));
 	printf("the result is: %d\n", result);
 	return 0;
}

	
	
int PostFix(char _str[],int _length)
{
	struct Stack* StackNum=NULL;
	
	char str[200],strpeulot[100],ch;
	int i,j=0,num,result,countpeul=0,n=1;
	StackNum=StackCreate (200,200);
	for(i=0;i<_length;i++)
	{
		if(_str[i]-'0'>=0 && _str[i]-'0'<=9)
		{
			ch=_str[i];
			StackPush (StackNum, ch);
			
		}
	}
	for(i=_length-1;i>=0;i--)
	{
		if(_str[i]=='/' || _str[i]=='*' || _str[i]=='+' || _str[i]=='-')
		{
			strpeulot[j]=_str[i];
			j++;
		}
	}
	strpeulot[j]='\0';
	countpeul=j;
	i=0;
	StackPop (StackNum,&num);
	str[i]=num;
	i++;
	StackPop (StackNum,&num);
	str[i]=num;
	i++;
	for(j=0;j<countpeul;j++)
	{
		if(strpeulot[j]=='/' || strpeulot[j]=='*')
		{
			str[i]=strpeulot[j];
			if(i==_length)
			{
				break;
			}
			i++;
			StackPop (StackNum,&num);
			str[i]=num;
			if(i==_length)
			{
				break;
			}
			i++;
		}
		if(strpeulot[j]=='-' || strpeulot[j]=='+')
		{
			if(strpeulot[j+1]=='-' || strpeulot[j+1]=='+')
			{
				str[i]=strpeulot[j];
				if(i==_length)
				{
					break;
				}
				i++;
				StackPop (StackNum,&num);
				str[i]=num;
				if(i==_length)
				{
					break;
				}
				i++;
			
			}
			else
			{
				while(strpeulot[j+n]!='/' || strpeulot[j+n]!='*')
				{
					str[i]=strpeulot[j+n];
					if(i==_length)
					{
						break;
					}
					i++;
					StackPop (StackNum,&num);
					str[i]=num;
					if(i==_length)
					{
						break;
					}
			 		i++;
				}
				str[i]=strpeulot[j];
				if(i==_length)
				{
					break;
				}
				i++;
				StackPop (StackNum,&num);
				str[i]=num;
				if(i==_length)
				{
					break;
				}	
				i++;
				
			}
		
		}
	
	}
	
	
	free(StackNum);
	result=count(str,_length);
	return result;
}
int count(char _str[],int _length)
{
	
	struct Stack* Stack=NULL;
	int num1,num2,result,i,ch;
	Stack=StackCreate (200,200);
	for(i=0;i<_length;i++)
	{
		if(_str[i]-'0'>=0 && _str[i]-'0'<=9)
		{
			ch=_str[i]-'0';
			StackPush (Stack, ch);	
		}
		if(_str[i]=='/' || _str[i]=='*' || _str[i]=='+' || _str[i]=='-')
		{
			switch(_str[i])
			{
				case '/':
					StackPop (Stack, &num2);
					StackPop (Stack, &num1);
					result=num1/num2;
					StackPush (Stack, result);	
				break;
				case '*':
					StackPop (Stack, &num2);
					StackPop (Stack, &num1);
					result=num1*num2;
					StackPush (Stack, result);	
				break;
				case '+':
					StackPop (Stack, &num2);
					StackPop (Stack, &num1);
					result= num1+num2;
					StackPush (Stack, result);	
				break;
				case '-':
					StackPop (Stack, &num2);
					StackPop (Stack, &num1);
					result=num1-num2;
					StackPush (Stack, result);	
				break;
			
			}	
		
		}
	}
	StackPop (Stack, &result);
	return result;

}

