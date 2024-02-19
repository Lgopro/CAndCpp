
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CompressingNew(char _str[]);
struct newchar
{
	unsigned char m_right :4;
	unsigned char m_left  :4; 

};

int main()
{
	char str[100]="ab";
	
	CompressingNew(str);

	return 0;
}


void CompressingNew(char _str[])
{
	int i,length,counter=0;
	struct newchar* compress;
	struct newchar* compress1;
	compress= (struct newchar*)_str;
	compress1= (struct newchar*)_str;
	length=strlen(_str)-1;
	for(i=0 ; i<length ; i+=2) 
	{
		compress->m_right= _str[i]-'a'+1;
		compress->m_left= _str[i+1]-'a'+1;
		counter++;
		compress++;
	}
	
	if(strlen(_str) % 2!= 0)
	{
		compress->m_right=_str[i-1]- 'a' +1;
		compress->m_left= 0;
		counter++;
		compress++;
	}
	for(i=0;i<counter;i++)
	{
	printf("%d %d",compress1->m_right,compress1->m_left);
	printf("\n");
	compress1++;
	}
	return;
	

}

