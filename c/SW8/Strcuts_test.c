/*
Rev: Amitai Bar
Dev: Leonid Golovko
status: finished
date:04/04/23
*/



#include <stdio.h> /*printf*/
#include "Structs.h"

void CreateAndPrintCheckAndDelete();


int main()
{	
	CreateAndPrintCheckAndDelete();
	
	
	return 0;
}

void CreateAndPrintCheckAndDelete()
{
	int number = 322;
	float num = 5.5;
	char str[]="helloBro";
	element_t arr[3] = { 0 };
	CreateInt(&arr[0], number);
	CreateFloat(&arr[1], num);
	CreateString(&arr[2], str);
	Print(arr, 3);
	AddAll(arr, 3, number);
	Print(arr, 3);
	CleanUpAll(arr, 3);


}

