/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:11/04/23
*/




#include <stdio.h> /*printf*/
#include <string.h> /*strcpy*/
#include <stdlib.h> /*malloc*/

#include "WordOpt.h"


void MemsetTestAlligned();
void MemsetTestNOTAlligned();
void MemcpyTestAlligned();
void MemcpyTestNOTAlligned();
void MemmoveTestAlligned();
void MemmoveTestAlligned2();
void MemmoveTestNOTAlligned1();
void MemmoveTestNOTAlligned2();
void MemmoveTestNOTAlligned3();
int main()
{	
	MemsetTestAlligned();
	MemsetTestNOTAlligned();
	MemcpyTestAlligned();
	MemcpyTestNOTAlligned();
	MemmoveTestAlligned();
	MemmoveTestNOTAlligned1();
	MemmoveTestNOTAlligned2();
	MemmoveTestNOTAlligned3();
	return 0;
}


void MemmoveTestNOTAlligned3()
{
	char dest[] = "AAAAAAAAAAAAAAAAAMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char dest1[] = "AAAAAAAAAAAAAAAAAMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	if(0 == strcmp(Memmove((void *)(dest + 17),(const void *)(dest + 1), 15), memmove((void *)(dest1 + 17),(const void *)(dest1 + 1), 15)))
	{
		printf("Test memmove same string2 not aligned pass\n");
	
	}
	else
	{
		printf("Test memmove same string2 not aligned fail\n");
	
	}

}


void MemmoveTestNOTAlligned2()
{
	char dest[] = "AAAAAAAAAAAAAAAAAMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char dest1[] = "AAAAAAAAAAAAAAAAAMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	if(0 == strcmp(Memmove((void *)(dest + 1),(const void *)(dest + 17), 25), memmove((void *)(dest1 + 1),(const void *)(dest1 + 17), 25)))
	{
		printf("Test memmove same string1 not aligned pass\n");
	
	}
	else
	{
		printf("Test memmove same string1 not aligned fail\n");
	
	}
}

void MemmoveTestNOTAlligned1()
{
	char dest[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	char dest1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src1[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	if(0 == strcmp(Memmove((void *)(dest + 1),(const void *)(src + 1), 21), memmove((void *)(dest1 + 1),(const void *)(src1 + 1), 21)))
	{
		printf("Test memmove not aligned pass\n");
	
	}
	else
	{
		printf("Test memmove not aligned fail\n");
	
	}


}


void MemmoveTestAlligned()
{
	char dest[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	char dest1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src1[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	if(0 == strcmp(Memmove((void *)dest,(const void *)src, 21), memmove((void *)dest1,(const void *)src1, 21)))
	{
		printf("Test memmove aligned pass\n");
	
	}
	else
	{
		printf("Test memmove aligned fail\n");
	
	}

}



void MemcpyTestNOTAlligned()
{
	
	
	char dest[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	char dest1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src1[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	if(0 == strcmp(Memcpy((void *)(dest + 1),(const void *)(src + 1), 21), memcpy((void *)(dest1 + 1),(const void *)(src1 + 1), 21)))
	{
		printf("Test memcpy not aligned pass\n");
	
	}
	else
	{
		printf("Test memcpy not aligned fail\n");
	
	}


}

void MemcpyTestAlligned()
{
	
	char dest[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	char dest1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char src1[] = "HEHEHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHHEH";
	if(0 == strcmp(Memcpy((void *)dest,(const void *)src, 21), memcpy((void *)dest1,(const void *)src1, 21)))
	{
		printf("Test memcpy aligned pass\n");
	
	}
	else
	{
		printf("Test memcpy aligned fail\n");
	
	}
}

void MemsetTestNOTAlligned()
{

	char line[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char line1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	if(0 == strcmp(Memset((void *)(line + 1), 'A', 25), memset((void *)(line1 + 1), 'A', 25)))
	{
		printf("Test memset not aligned pass\n");
	
	}
	else
	{
		printf("Test memset not aligned fail\n");
	
	}
	
}



void MemsetTestAlligned()
{
	
	char line[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	char line1[] = "My name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobMy name is BobBobMy name is Bob";
	if(0 == strcmp(Memset((void *)line, 'A', 25), memset((void *)line1, 'A', 25)))
	{
		printf("Test memset aligned pass\n");
	
	}
	else
	{
		printf("Test memset aligned fail\n");
	
	}
}
