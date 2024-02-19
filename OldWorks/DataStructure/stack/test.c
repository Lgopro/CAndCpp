#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
void test1(void);

int main()
{
	struct Stack* Stack=NULL;
 	char str[]="[]";
 	int empty,i,ch,arr[10000],num;
 	EnterVariables(Stack);
 	empty=StackIsEmpty (Stack);
	if(empty==1)
	{
		printf("Not meuzan\n");
	}
	while(str[i]=='\0')
	{
		ch=(int)getc(str);
		arr[i]=ch;
		i++;
	}
	num=i;
	for(i=0;i<num;i++)
		printf("%d ", arr[i]);
	
    return 0;
}
